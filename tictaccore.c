#include<stdio.h>
#include<stdlib.h>
#include<time.h> // to seed the rand() function

// function declarators
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
            PlayerMatrixEdit(matrixarg);
        }
        matrixarg[row][cols] = 1;
    } // if matrixarg == 0
    else{
        printf("value exists for the given coordinates \n");
        PlayerMatrixEdit(matrixarg);
    } 
}// PlayerMatrixEdit

int RandGen(){
    // random generator for computer's play
    int AiPlay = (rand() %2) + 1;
    return AiPlay; // returns 1,2,3 for ai's play
}

void AiMatrixEdit(int matrixarg[3][3]){
    // this function is used for ai's turn 
    int aiRows = RandGen();
    int aiCols = RandGen();
    int i, j;
    if(matrixarg[aiRows][aiCols] == 0) matrixarg[aiRows][aiCols] = 2;
    else {
        for (i=0; i<3; i++){
            for (j=0; j<3; j++){
                if (matrixarg[i][j] == 0){
                    matrixarg[i][j] = 2;
                    i=3, j=3; // to break out of the nested loop
                }
            }
        }
    }
    
} // AiMatrixEdit

int CheckMatrix(int matrixarg[3][3]){
    // this function is used to check the winning / losing condition

    // horizontal check
    for (int rowNo=0; rowNo<3; rowNo++){
        if ((matrixarg[0][rowNo] == matrixarg[1][rowNo] && matrixarg[1][rowNo] == matrixarg[2][rowNo])){
            if (matrixarg[0][rowNo] != 0) return matrixarg[0][rowNo];
        }
    }

    // vertical check
    for (int colNo=0; colNo<3; colNo++){
        if ((matrixarg[colNo][0] == matrixarg[colNo][1] && matrixarg[colNo][1] == matrixarg[colNo][2])){
            if (matrixarg[colNo][0] != 0) return matrixarg[colNo][0];
        }
    }

    // diagonal check
    if ((matrixarg[0][0] == matrixarg[1][1] && matrixarg[1][1] == matrixarg[2][2]) 
        || (matrixarg[0][2] == matrixarg[1][1] && matrixarg[1][1] == matrixarg[2][0])){
        if (matrixarg[1][1] != 0) return matrixarg[1][1];
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
