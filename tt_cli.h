#include<cstdio>

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
