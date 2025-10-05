Tic-Tac-Toe 

A customizable Tic-Tac-Toe game written in C that supports:

- Human vs Human
- Human vs Computer
- Multiplayer with up to 3 players
- Variable board size (3x3 up to 10x10)
- Simple AI for computer players
- Game logging to a text file

Project Structure

tictactoe/
├── tictactoe.c # Main game logic and implementation
├── tictactoe.h # Header file with prototypes and constants
├── tictactoe_log.txt # Automatically generated game log
├── README.md # You're reading this!


Features

-  Board size selection (from 3x3 to 10x10)
-  Three game modes:
  - Human vs Human
  - Human vs Computer
  - 2-3 Player Multiplayer (each can be human or computer)
-  Win checking (rows, columns, diagonals)
-  Computer logic:
  - Attempts to win
  - Blocks opponent if they are about to win
  - Picks random move otherwise
-  Game logs all moves to `tictactoe_log.txt`
-  Clean modular structure with reusable functions


