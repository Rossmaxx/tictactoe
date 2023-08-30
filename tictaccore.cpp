#include "tictaccore.h"
#include <iostream>

using std::cout;

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

    cout << "welcome to my tic tac toe game\n";
    PrintMatrix(matrix);
    

    while (1){ // continous play till the player stops
        
        cout << "player's turn\n" ;
        PlayerMatrixEdit(matrix);
        PrintMatrix(matrix);

        checkval = CheckMatrix(matrix);
        if (checkval == 1){
            cout << "player wins\n" ;
            break;
        }

        cout << "ai's turn \n" ;
        AiMatrixEdit(matrix);
        PrintMatrix(matrix);

        checkval = CheckMatrix(matrix);
        if (checkval == 2){
            cout << "ai wins\n" ;
            break;
        }

        // to check free cells and exist if no free cells
        freeCheck = checkFreeCells(matrix);
        if (freeCheck == 0){
            cout << "No free cells \n " ;
            break;
        }

        // quitting condition
        cout << "do you like to continue (y/n) : ";
        scanf(" %c", &Breaker);
        if(Breaker == 'n') break;
    } // while loop
    return 0;
} // main function
