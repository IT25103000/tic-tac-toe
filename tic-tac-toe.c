#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//(structure to hold gameinformation typedef struct {

char**board;//2d array for the game board
int size;//Board size (N*N)
int current_player;//current player(0,1 or 2)
int num_players;//Number of players(2 or 3)
char symbols[3];//Player symbols('X','O','Z')
int player_types[3];//0 = human, 1 = computer
FILE*log_file;//file pointer for logging
	      )
}
