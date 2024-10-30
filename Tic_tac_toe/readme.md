# Tic-Tac-Toe in C

Welcome to **Tic-Tac-Toe** - the OG 3x3 grid game that’ll have you doubting your strategy skills! Built using C and powered by the desire to pass the time. 😄

## How to Play

1. Fire up the code! You’ll be asked to enter the names for Player 1 and Player 2 (because "Player 1" and "Player 2" are too mainstream).
2. The board starts as a 3x3 grid with numbers 1 to 9. Pick a number to mark your move.
3. Player 1 is 'X' and Player 2 is 'O' (again, following ancient tradition).
4. The first to complete a row, column, or diagonal wins. Simple, right? 🎉

## Code Overview

- **`char board[3][3]`**: This 2D array is our Tic-Tac-Toe battlefield. It starts off as a grid of numbers 1 to 9 to guide the players on where to place their markers.
  
- **`display_board()`**: Shows the board to the players. This function is called after every turn to help the players keep track of moves and plot their next one (or maybe just admire their X's and O's).

- **`check_winner()`**: Checks if either player has achieved victory by completing a row, column, or diagonal with their marker. If someone’s won, it’s game over! 

- **`check_draw()`**: Runs through the board to see if it's completely filled without any winning line. If all spots are taken and there's still no winner, it’s a tie - which is only slightly less satisfying than winning.

- **`place_marker(int slot)`**: Accepts a slot number (1-9) and places the current player's marker (X or O) on the board. Think of this as the function where the action actually happens!

- **`swap_player_and_marker()`**: Switches the current player and their marker. This function makes sure the game flows smoothly by alternating turns between the players after every move.

- **Main Game Loop**: Inside `main()`, this loop keeps the game running:
  - Prompts the player for a move.
  - Checks if the chosen slot is valid (i.e., not already taken and within bounds).
  - Places the marker, shows the updated board, and checks for a win or a draw.
  - If the game isn’t over, it swaps players and continues the battle.

---

And that’s pretty much it! Enjoy the game, challenge your friends, and may the best player win!
