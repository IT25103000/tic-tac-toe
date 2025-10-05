#include "tictactoe.h"

// Show welcome message
void displayWelcome(){
    printf("..Welcome to Tic-Tac-Toe..\n");
    printf("Rules:\n");
    printf("- 2 or 3 players can play.\n");
    printf("- Fill a row, column or diagonal to win.\n");
    printf("- Board size range 3 to 10\n");
}

// Initialize empty board
void initBoard(char **board, int size){
    for(int i =0; i < size; i++)
        for(int j = 0; j < size; j++)
            board[i][j] = '-';
}

// Print board
void printBoard(char **board, int size){
    printf("\n  ");
    for (int c = 0; c < size; c++) printf(" %2d ", c+1);
    printf("\n");

    for (int r = 0; r < size; r++){
        printf(" %2d ", r+1);
        for (int c = 0; c < size; c++){
            printf(" %c ", board[r][c]);
            if(c < size-1) printf("|");
        }
        printf("\n");

        if(r < size-1){
            printf("  ");
            for(int c=0;c<size;c++){
                printf("---");
                if(c<size-1) printf("+");
            }
            printf("\n");
        }
    }
    printf("\n");
}

// Validate move
int validMove(char **board, int size, int row, int col){
    if(row < 0 || row >= size) return 0;
    if(col < 0 || col >= size) return 0;
    if(board[row][col] != '-') return 0;
    return 1;
}

// Check winner
int checkWinner(char **board, int size, char mark){
    // Rows
    for(int r=0;r<size;r++){
        int ok=1;
        for(int c=0;c<size;c++){
            if(board[r][c] != mark){ ok=0; break; }
        }
        if(ok) return 1;
    }

    // Columns
    for(int c=0;c<size;c++){
        int ok=1;
        for(int r=0;r<size;r++){
            if(board[r][c] != mark){ ok=0; break; }
        }
        if(ok) return 1;
    }

    // Main diagonal
    int ok=1;
    for(int i=0;i<size;i++){
        if(board[i][i] != mark){ ok=0; break; }
    }
    if(ok) return 1;

    // Anti-diagonal
    ok=1;
    for(int i=0;i<size;i++){
        if(board[i][size-1-i] != mark){ ok=0; break; }
    }
    return ok;
}

// Board filled
int boardFilled(char **board, int size){
    for(int r=0;r<size;r++)
        for(int c=0;c<size;c++)
            if(board[r][c] == '-') return 0;
    return 1;
}

// Human turn with logging
void humanTurn(char **board, int size, char mark, FILE *log){
    int r,c;
    while(1){
        printf("Enter row and column: ");
        scanf("%d %d", &r,&c);
        r--; c--;

        if(validMove(board,size,r,c)){
            board[r][c] = mark;
            if(log) fprintf(log, "Human (%c) plays: row=%d col=%d\n", mark,r+1,c+1);
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

// Computer turn with logging
void computerTurn(char **board,int size,char mark,char opponent, FILE *log){
    int r,c;

    // 1. Try to win
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(validMove(board,size,i,j)){
                board[i][j] = mark;
                if(checkWinner(board,size,mark)){
                    printf("Computer plays at (%d,%d) to WIN\n",i+1,j+1);
                    if(log) fprintf(log,"Computer (%c) plays to win: row=%d col=%d\n", mark,i+1,j+1);
                    return;
                }
                board[i][j] = '-';
            }
        }
    }

    // 2. Block opponent
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(validMove(board,size,i,j)){
                board[i][j] = opponent;
                if(checkWinner(board,size,opponent)){
                    board[i][j] = mark;
                    printf("Computer blocks at (%d,%d)\n", i+1,j+1);
                    if(log) fprintf(log,"Computer (%c) blocks opponent: row=%d col=%d\n", mark,i+1,j+1);
                    return;
                }
                board[i][j] = '-';
            }
        }
    }

    // 3. Random move
    do{
        r = rand()%size;
        c = rand()%size;
    }while(!validMove(board,size,r,c));

    board[r][c] = mark;
    printf("Computer chooses random (%d,%d)\n", r+1,c+1);
    if(log) fprintf(log,"Computer (%c) random move: row=%d col=%d\n", mark,r+1,c+1);
}

// Ask player type
int getPlayerType(char symbol){
    int type;
    while(1){
        printf("Player %c - 0=Human,1=Computer: ", symbol);
        scanf("%d",&type);
        if(type==0 || type==1) return type;
        printf("Invalid. Enter 0 or 1.\n");
    }
}
