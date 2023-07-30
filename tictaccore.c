#include "tictaccore.h"

// function declarators, all functions in tictaccore.h
void PrintMatrix(int[3][3]);
void PlayerMatrixEdit(int[3][3]);
void AiMatrixEdit(int[3][3]);
int checkFreeCells(int[3][3]);
int CheckMatrix(int[3][3]);

// function main
int main(){
    int matrix[3][3] = { {0,0,0}, {0,0,0} ,{0,0,0} };
    int checkval, freeCheck;
    char Breaker;

    srand(time(0)); // seeding the AI generator to have randomness

    printf("welcome to my tic tac toe game\n");
    PrintMatrix(matrix);
    

    while (1){ // continous play till the player stops
        
        printf("player's turn\n");
        PlayerMatrixEdit(matrix);
        PrintMatrix(matrix);

        checkval = CheckMatrix(matrix);
        if (checkval == 1){
            printf("player wins\n");
            break;
        }

        printf("ai's turn \n");
        AiMatrixEdit(matrix);
        PrintMatrix(matrix);

        checkval = CheckMatrix(matrix);
        if (checkval == 2){
            printf("ai wins\n");
            break;
        }

        // to check free cells and exist if no free cells
        freeCheck = checkFreeCells(matrix);
        if (freeCheck == 0){
            printf("No free cells \n ");
            break;
        }

        // quitting condition
        printf("do you like to continue (y/n) : ");
        scanf(" %c", &Breaker);
        if(Breaker == 'n') break;
    } // while loop
    return 0;
} // main function
