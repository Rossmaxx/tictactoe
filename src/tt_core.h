#include<random>

// some stuff needed for random number generation
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dist(0,2);


void AiMatrixEdit(int matrixarg[3][3]){
    // this function is used for ai's turn 
    int aiRows = dist(gen);
    int aiCols = dist(gen);
    aiRows = aiRows % 3;
    aiCols = aiCols % 3;

    if(matrixarg[aiRows][aiCols] == 0) { 
        matrixarg[aiRows][aiCols] = 2;
        return;
    }
    
    int i, j;
    for (i=0; i<3; i++){
        for (j=0; j<3; j++){
            if (matrixarg[i][j] == 0){
                matrixarg[i][j] = 2;
                return; // to break out of the nested loop
            }
        }
    }
} // AiMatrixEdit

int CheckMatrix(int matrixarg[3][3]){
    // this function is used to check the winning / losing condition

    // horizontal check
    for (int rowNo=0; rowNo<3; rowNo++){
        if ((matrixarg[0][rowNo] == matrixarg[1][rowNo] && matrixarg[1][rowNo] == matrixarg[2][rowNo])){
            if (matrixarg[0][rowNo] != 0) { return matrixarg[0][rowNo]; }
        }
    }

    // vertical check
    for (int colNo=0; colNo<3; colNo++){
        if ((matrixarg[colNo][0] == matrixarg[colNo][1] && matrixarg[colNo][1] == matrixarg[colNo][2])){
            if (matrixarg[colNo][0] != 0) { return matrixarg[colNo][0]; }
        }
    }

    // diagonal check
    if ((matrixarg[0][0] == matrixarg[1][1] && matrixarg[1][1] == matrixarg[2][2]) 
        || (matrixarg[0][2] == matrixarg[1][1] && matrixarg[1][1] == matrixarg[2][0])){
        if (matrixarg[1][1] != 0) { return matrixarg[1][1]; }
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
