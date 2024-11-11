# Tic-Tac-Toe in C

Welcome to **Tic-Tac-Toe** - the OG 3x3 grid game that’ll have you doubting your strategy skills! Built using C and powered by the desire to pass the time. 😄

## How to Play

1. Fire up the code! You’ll be asked to enter the names for Player 1 and Player 2 (because "Player 1" and "Player 2" are too mainstream).
2. The board starts as a 3x3 grid with numbers 1 to 9. Pick a number to mark your move.
3. Player 1 is 'X' and Player 2 is 'O' (again, following ancient tradition).
4. The first to complete a row, column, or diagonal wins. Simple, right? 🎉

## Code Overview

The program includes:

- **Headers**: The standard libraries `stdio.h` and `string.h` are included for input/output operations and string handling.

- **Functions**:
  - **`printblock(char block[][3])`**: Displays the current state of the Tic-Tac-Toe board.
  - **`chooseSlot(int Slot, int *row, int *col)`**: Converts a chosen slot number (1-9) to corresponding row and column indices on the board.
  - **`CheckWinner(char block[][3])`**: Checks the board to see if there’s a winner or if the match is a draw.
  - **`checkValidity(char block[][3], int Slot)`**: Verifies if a chosen slot is available for marking.

### Main Logic

The main function contains:

- A 3x3 character array, **`block`**, initialized with numbers 1-9 representing each slot on the board.
- Two strings, **`player1`** and **`player2`**, to store the names of the players.

### Game Loop

- The board is printed at the start of each turn using **`printblock`**.
- Each player takes turns to choose a slot. If the slot is valid, it is marked with 'X' or 'O'.
- **`CheckWinner`** is called to determine if there’s a winner. If not, the game proceeds to the next turn until a player wins or all slots are filled (resulting in a draw).

---

Enjoy the game, challenge your friends, and may the best player win!
