#include <stdio.h>
#include <conio.h> //without using this it says warning: implicit declaration of function 'getch'; did you mean 'getc'? [-Wimplicit-function-declaration]
#include <string.h>

void printblock(char block[][3]);
void chooseSlot(int Slot, int *row, int *col);
int CheckWinner(char block[][3]);
int checkValidity(char block[][3], int Slot);
void system();

int main()
{
    char block[3][3] = {{'1', '2', '3'},
                        {'4', '5', '6'},
                        {'7', '8', '9'}};

    char player[20], player1[20], player2[20];
    int Slot;
    int Turn = 1;
    int row, col;

    printf("WELCOME TO TIC-TAC-TOE\n");
    printf("\tEnter name of player_1(X): ");
    fgets(player1, sizeof(player1), stdin);
    player1[strcspn(player1, "\n")] = 0;
    printf("\tEnter name of player_2(O): ");
    fgets(player2, sizeof(player2), stdin);
    player2[strcspn(player2, "\n")] = 0;

    while (1)
    {
        printblock(block);

        (Turn % 2 != 0) ? strcpy(player, player1) : strcpy(player, player2);
        char Mark = (Turn % 2 != 0) ? 'X' : 'O';

        printf("%s choose a slot b/w 1-9: ", player);
        scanf("%d", &Slot);
        if (Slot < 1 || Slot > 9)
        {
            printf("Invalid Slot !!!\n");
            printf("Choose a slot between 1 to 9\n");
            printf("Enter any key to continue....\n");
            getch();
            continue;
        }

        chooseSlot(Slot, &row, &col);

        if (block[row][col] == 'X' || block[row][col] == 'O')
        {
            printf("Slot Already Taken.... Choose Other\n");
            printf("Enter any Key to Continue....\n");
            getch();
            continue;
        }

        block[row][col] = Mark;
        printblock(block);
        Turn++;

        int Result = CheckWinner(block);
        if (Result == 1)
        {
            printf("\n%s! Won the Match.\n", player);
            break;
        }
        if (Result == 0)
        {
            printf("\nIts a Draw!!\n");
            break;
        }
    }

    return 0;
}

void printblock(char block[3][3])
{
    system("cls");
    printf("\nTic_Tac_Toe\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", block[i][j]);
            if (j < 2)
                printf("|");
        }
        printf("\n");
        if (i < 2)
            printf("___|___|___\n");
    }
    printf("   |   |   \n");
}

void chooseSlot(int Slot, int *row, int *col)
{
    *row = (Slot - 1) / 3;
    *col = (Slot - 1) % 3;
}

int CheckWinner(char block[][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (block[0][i] == block[1][i] && block[1][i] == block[2][i])
            return 1;
        if (block[i][0] == block[i][1] && block[i][1] == block[i][2])
            return 1;
    }

    if (block[0][0] == block[1][1] && block[1][1] == block[2][2])
        return 1;
    if (block[0][2] == block[1][1] && block[1][1] == block[2][0])
        return 1;

    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (block[i][j] == 'X' || block[i][j] == 'O')
                count++;
        }
    }

    if (count == 9)
        return 0;

    return -1;
}
