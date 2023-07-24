#include<stdio.h>
#include<stdlib.h>
#include<time.h> // to seed the rand() function

// global variables
int matrix[3][3] = { {0,0,0}, {0,0,0} ,{0,0,0} };

// function declarators
void PrintMatrix(int[3][3]);
void PlayerMatrixEdit(int[3][3]);
void AiMatrixEdit(int[3][3]);
int checkFreeCells(int[3][3]);
int CheckMatrix(int[3][3]);

// function main
int main(){
    printf("welcome to my tic tac toe game\n");
    PrintMatrix(matrix);
    int checkval, freeCheck;
    char Breaker;

    while (1){ // continous play till the player stops
        
        printf("player's turn\n");
        PlayerMatrixEdit(matrix);
        PrintMatrix(matrix);

        checkval = CheckMatrix(matrix);
        if (checkval == 1){
            printf("player wins");
            break;
        }

        printf("ai's turn \n");
        AiMatrixEdit(matrix);
        PrintMatrix(matrix);

        checkval = CheckMatrix(matrix);
        if (checkval == 2){
            printf("ai wins");
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


// all non main functions

void PrintMatrix(int matrixarg[3][3]){
    //this function is used to print the matrix
    printf(" %d | %d | %d \n", matrixarg[0][0], matrixarg[0][1], matrixarg[0][2]); 
    printf("-------------\n");
    printf(" %d | %d | %d \n", matrixarg[1][0], matrixarg[1][1], matrixarg[1][2]);
    printf("-------------\n");
    printf(" %d | %d | %d \n", matrixarg[2][0], matrixarg[2][1], matrixarg[2][2]);
}

void PlayerMatrixEdit(int matrixarg[3][3]){
    // this function is made to allow the player to edit the matrix
    int row,cols;
    printf("enter row no: between 1 and 3 : ");
    scanf("%d",&row);
    printf("enter column no: between 1 and 3 : ");
    scanf("%d",&cols);
    --row, --cols;
    fflush(stdin); // to fix scanf issues
    if (matrixarg[row][cols] == 0){
        if (row >=3 || cols >=3){
            printf("invalid coordinates, try again\n");
            PlayerMatrixEdit(matrix);
        }
        matrixarg[row][cols] = 1;
    } // if matrixarg == 0
    else{
        printf("value exists for the given coordinates \n");
        PlayerMatrixEdit(matrix);
    } 
}// PlayerMatrixEdit

int RandGen(){
    // random generator for computer's play
    srand(time(0));
    int AiPlay = (rand() %2) + 1;
    return AiPlay; // returns 1,2,3 for ai's play
}

void AiMatrixEdit(int matrixarg[3][3]){
    // this function is used for ai's turn 
    int aiRows = RandGen();
    int aiCols = RandGen();
    if(matrixarg[aiRows][aiCols] == 0) matrixarg[aiRows][aiCols] = 2;
    else AiMatrixEdit(matrix);
}

int CheckMatrix(int matrixarg[3][3]){
    // this function is used to check the winning / losing condition
    // incomplete

    /*
    // horizontal check
    int xcordcheck = 0, ycordcheck = 0, checkvalarr[3];
    for (;xcordcheck <= 3; xcordcheck++) {
        for (;ycordcheck <= 3; ycordcheck++) checkvalarr[ycordcheck] = matrixarg[xcordcheck][ycordcheck];
        if (checkvalarr[0] == checkvalarr[1] == checkvalarr[2] == 1) return 1;
        else if (checkvalarr[0] == checkvalarr[1] == checkvalarr[2] == 2) return 2;
    }

    // vertical check
    xcordcheck = 0, ycordcheck = 0; // reset
    for (;ycordcheck <=  3; ycordcheck++){
        for (;xcordcheck <= 3; xcordcheck++) checkvalarr[xcordcheck] = matrixarg[xcordcheck][ycordcheck];
        if (checkvalarr[0] == checkvalarr[1] == checkvalarr[2] == 1) return 1;
        else if (checkvalarr[0] == checkvalarr[1] == checkvalarr[2] == 2) return 2;
    }

    */

    // diagonal check
    if ((matrixarg[0][0] == matrixarg[1][1] && matrixarg[1][1] == matrixarg[2][2]) 
        || (matrixarg[0][2] == matrixarg[1][1] && matrixarg[1][1] == matrixarg[2][0])){
        if (matrixarg[1][1] == 1) return 1;
        else if (matrixarg[1][1] == 2) return 2;
    }

    return 0;
} // checkmatrix


int checkFreeCells(int matrixarg[3][3]){
    // this function is used to check for empty cells, returns 0 if no empty cells
    int freeCells = 0, i, j;
    for (i=0; i<3; i++){
        for (j=0; j<3; j++){
            if (matrixarg[i][j] == 0){
                freeCells++;
            }
        }
    }
    return freeCells;
}
