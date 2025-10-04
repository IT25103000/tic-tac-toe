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
	
	while(1){
		printf("Enter board size(3-10):");
		scanf("%d",&size);
		if(size >= 3&& size <= 10)break;
		printf("Invalid size.Please enter between 3 and 10.\n");
	}
	while(1){
		printf("Select mode:\n");
		prints("1.Human vs Human\n");
		printf("2.Human vs Computer\n");
		printf("3.Custom(2-3 players with type)\n");
		printf("Enter option(1-3):");
		scanf("%d",&mode);
		if(mode >= 1 && mode <= 3)break;
		printf("Invalid option .choose 1,2 or 3.\n");
	}

	if(mode == 1){
		totalplayers = 2;
		playerType[0] = 0;
		playerType[1] = 0;
	}
	else if (mode == 2){
		totalPlayers = 2;
		playerType[0] = 0;
		playerType[1] = 1;
	}
	else{
		while(1) {
			printf("Enter total number of players(2 or 3):");
			scanf("%d",&totalPlayers);
			if(totalPlayers >= 2 && totalPlayers <= 3)
				break;
			printf("Invalid number.Enter 2 or 3.\n");
		}
		for(int i = 0;i<totalPlayers;i++){
			playerType[i] = getPlayerType(symbols[i]);
		}
	}

	char**board = (char**)malloc(size*sizeof(char*));
	for (int i = 0;i < size;i++){
		board[i] =(char *)malloc(size * sizeof(char));
	}

	initBoard(board,size);
	int currentTurn = 0;
	int gameOver = 0;

	while(!gameOver){
		printBoard(board,size);
		printf("Player %d (%c)'s moe\n",currentTurn + 1,symbols[currentTurn]);

		if(playerType[currentTurn] ==0){
			humanTurn(board,size,symbols[currentTurn]);
		}
		else{
			char opponent = symbols[(currentTurn + 1) % totalPlayers];
			computerTurn(board,size,symbols[currentTurn],opponent);
		}
		if(checkWinner(board, size,symbols[currentTurn])) {
			printBoard(board,size);
			printf("Player %d (%c)wins!\n",currentTurn + 1,symbols[currentTurn]);
			gameOver = 1;
		}
		else if(boardFilled(board,size)) {
			printBoard(board,size);
			printf("It's a draw!\n");
			gameOver = 1;
		}
		else{
			currentTurn = (currentturn + 1)% totalPlayer;
		}
	}
	for(int i = 0; i< size;i++){
		free(board[i]);
	}
	free(board);
	return 0;

}
void displayWelcome(){
	printf("..Welcome to Tic-Tac -Toe..\n");
	printf("Rules:\n");
	printf("- 2 or 3 player can play.\n");
	printf("-File a row,column or diagonal to win,\n");
	printf("-Board size range: 3 to 10\n");
}
void initBoard(char**board,int size){
	for(int i = 0;i< size; i++)
		for(int j = 0;j < size;j++)
			board[i][j] = '-';

	void printBoard(char**board,int size){
		printf("\n");

		for(int c = 0; c < size;c++)
			printf("%2d",c + 1);
		printf("\n");

		for(int r = 0;r < size;r++){
			printf("%2d",r + 1);
			for(int c = 0;c < size;c++){
				printf("%c",board[r][c]);
				if(c < size-1)
					printf("|");
			}
			printf("\n");
			if(r < size -1){
				printf(" ");
				for (int c = 0;c < size:c++){
					printf("---");
					if(c < size-1)
						printf("+");
				}
				printf("\n");
			}
		}
		printf("\n");
	}
	//Validate move
	int validMove(char**board,int size,int row,int col){
		if(row < 0||row >=size)
			return 0;
		if(col < 0||col >=size)
			return 0;
		return 1;
	}


	//Check for winner
	int checkWinner(char**board,int size,char mark){
		//Check Rows
		for(int r = 0;r < size;r++){
			int ok = 1;
			for(int c = 0;c < size;c++){
				if(board[r][c] !=mark){
					ok = 0;
					break;
				}
			}
			if(ok)
				return 1;
		}
		//Check Columns
		for(int c = 0;c < size;c++){
			int ok = 1;
			for(int r = 0;r < size;r++){
				if(board[r][c] != mark){
					ok = 0;
					break;
				}
			}
			if(ok)
				return 1;

			//Check Anti-Diagonal
			ok = 1;
			for(int i = 0;i < size;i+=){
				if(board[i][size - 1-i] !=mark){
					ok = 0;
					break;
				}
			}
			return ok;
		}
