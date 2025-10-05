#include "tictactoe.h"

int main() {
    srand((unsigned int)time(NULL));  // Seed random for computer moves
    char playAgain;

    do {
        int size, mode, totalPlayers;
        char symbols[Max_Players] = {'X','O','Z'};
        int playerType[Max_Players];

        printf("   Welcome to Tic-Tac-Toe!   \n");
       
 	// Step 1: Board size
        while(1) {
            printf("\nStep 1: Choose the board size.\n");
            printf("Enter a number between 3 and 10: ");
            scanf("%d", &size);
            if(size >= 3 && size <= 10) break;
            printf("Invalid choice. Please choose a number between 3 and 10.\n");
        }

        // Step 2: Game mode
        while(1) {
            printf("\nStep 2: Select game mode.\n");
            printf("1. Human vs Human\n");
            printf("2. Human vs Computer\n");
            printf("3. Multi-player (up to 3 players)\n");
            printf("Enter 1, 2, or 3: ");
            scanf("%d", &mode);
            if(mode >= 1 && mode <= 3) break;
            printf("Invalid choice. Enter 1, 2, or 3.\n");
        }

        // Step 3: Set player types
        if(mode == 1) {
            totalPlayers = 2;
            printf("\nYou chose Human vs Human. Both players will be human.\n");
            playerType[0] = 0;
            playerType[1] = 0;
        } else if(mode == 2) {
            totalPlayers = 2;
            printf("\nYou chose Human vs Computer.\n");
            playerType[0] = 0; // Human
            playerType[1] = 1; // Computer
        } else {
            while(1) {
                printf("\nStep 3: How many players? Enter 2 or 3: ");
                scanf("%d", &totalPlayers);
                if(totalPlayers >= 2 && totalPlayers <= 3) break;
                printf("Invalid choice. Enter 2 or 3.\n");
            }

            for(int i = 0; i < totalPlayers; i++) {
                while(1) {
                    printf("Player %c: 0 = Human, 1 = Computer: ", symbols[i]);
                    scanf("%d", &playerType[i]);
                    if(playerType[i] == 0 || playerType[i] == 1) break;
                    printf("Invalid input. Enter 0 or 1.\n");
                }
            }
        }

        // Step 4: Allocate board memory
        char **board = (char **)malloc(size * sizeof(char *));
        for(int i = 0; i < size; i++)
            board[i] = (char *)malloc(size * sizeof(char));

        initBoard(board, size);

        int currentTurn = 0, gameOver = 0;

        // Step 5: Open log file
        FILE *log = fopen("tictactoe_log.txt", "a");
        if(log) fprintf(log, " New Game \n");

        // Step 6: Game loop
        while(!gameOver) {
            printBoard(board, size);
            printf("Player %d (%c)'s move\n", currentTurn + 1, symbols[currentTurn]);

            if(playerType[currentTurn] == 0)
                humanTurn(board, size, symbols[currentTurn], log);
            else
                computerTurn(board, size, symbols[currentTurn], symbols[(currentTurn+1) % totalPlayers], log);

            if(checkWinner(board, size, symbols[currentTurn])) {
                printBoard(board, size);
                printf("Player %d (%c) wins!\n", currentTurn + 1, symbols[currentTurn]);
                if(log) fprintf(log, "Player %d (%c) wins!\n", currentTurn + 1, symbols[currentTurn]);
                gameOver = 1;
            } else if(boardFilled(board, size)) {
                printBoard(board, size);
                printf("It's a draw!\n");
                if(log) fprintf(log, "Draw!\n");
                gameOver = 1;
            } else {
                currentTurn = (currentTurn + 1) % totalPlayers;
            }
        }

        if(log) fclose(log);

        // Free memory
        for(int i = 0; i < size; i++) free(board[i]);
        free(board);

        // Step 7: Play again?
        while(1) {
            printf("\nDo you want to play again? (y/n): ");
            scanf(" %c", &playAgain);
            if(playAgain == 'y' || playAgain == 'Y' || playAgain == 'n' || playAgain == 'N') break;
            printf("Invalid input. Enter 'y' for yes or 'n' for no.\n");
        }

    } while(playAgain == 'y' || playAgain == 'Y');

    printf("\nThank you for playing Tic-Tac-Toe!\n");
    return 0;
}
