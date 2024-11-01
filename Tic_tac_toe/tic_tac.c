#include <stdio.h>
#include <string.h>

char board[3][3] = {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};

char current_marker;
int current_player;
char player1_name[50];
char player2_name[50];

void display_board() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int check_winner() {
    // Rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;

    return 0;
}

int check_draw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return 0;
        }
    }
    return 1;
}

void place_marker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    board[row][col] = current_marker;
}

void swap_player_and_marker() {
    current_marker = (current_marker == 'X') ? 'O' : 'X';
    current_player = (current_player == 1) ? 2 : 1;
}

int main() {
    current_marker = 'X';
    current_player = 1;
    int slot;

    printf("Welcome to Tic-Tac-Toe!\n");

    // Get player names
    printf("Enter name for Player 1 (X): ");
    fgets(player1_name, sizeof(player1_name), stdin);
    player1_name[strcspn(player1_name, "\n")] = 0;  // Remove newline character

    printf("Enter name for Player 2 (O): ");
    fgets(player2_name, sizeof(player2_name), stdin);
    player2_name[strcspn(player2_name, "\n")] = 0;  // Remove newline character

    display_board();

    while (1) {
        printf("%s, enter your slot (1-9): ", current_player == 1 ? player1_name : player2_name);
        scanf("%d", &slot);

        if (slot < 1 || slot > 9) {
            printf("Invalid slot! Try again.\n");
            continue;
        }

        int row = (slot - 1) / 3;
        int col = (slot - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Slot taken! Try another slot.\n");
            continue;
        }

        place_marker(slot);
        display_board();

        if (check_winner()) {
            printf("%s wins!\n", current_player == 1 ? player1_name : player2_name);
            break;
        }

        if (check_draw()) {
            printf("It's a draw!\n");
            break;
        }

        swap_player_and_marker();
    }

    return 0;
}
