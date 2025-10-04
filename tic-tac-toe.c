#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define Max_player 3

void displayWelcome();
void initBoard(char**board,int size);
void printBoard(char**board,int size);
int validMove(char**board,int size,int row,int col);
int cheakWinner(char**board,int size,char mark);
int boardFilled(char**board,int size);
void humanTurn(char**board,int size,char mark);
void computerTurn(char**board,int size,char mark,char opponent);
int getPlayerType(char symbol);

int main() {
	srand((unsigned int)time(NULL));

	int size,mode,totalPlayer;
	char symbols[Max_players] = {'X','o','Z'};
	int playerType[Max_Player]; // 0=human, 1=computer
        
	displayWelcome();
