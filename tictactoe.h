#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Max_Players 3   // Maximum players can play

// Function Prototypes
void displayWelcome();
void initBoard(char **board, int size);
void printBoard(char **board, int size);
int validMove(char **board, int size , int row, int col);
int checkWinner(char **board, int size, char mark);
int boardFilled(char **board, int size);
void humanTurn(char **board ,int size, char mark, FILE *log);
void computerTurn(char **board,int size, char mark, char opponent, FILE *log);
int getPlayerType(char symbol);

#endif
