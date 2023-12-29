#include <QtWidgets>

#include "tt_core.h"


class TicTacToe : public QWidget {
    Q_OBJECT

public:
    TicTacToe(QWidget *parent = nullptr) : QWidget(parent) {
        // Set up your game board UI (buttons, layout)
        // For example:
        QGridLayout *gridLayout = new QGridLayout(this);

        // initialize an empty matrix
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                matrix[i][j]=0;
            }
        }

        // loop to create button
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                QPushButton *button = new QPushButton("");
                gridLayout->addWidget(button, i, j);
                buttons[i][j] = button;
                connect(button, &QPushButton::clicked, this, [=]() { playerClick(i, j, buttons); });
            }
        }
    }

    // Function to handle button clicks
    void playerClick(int row, int col, QPushButton *buttons[3][3]) {
        // Make a move in the game matrix
        // Update the button text or icon based on the game state

        // return if cell not empty
        if (matrix[row][col]){ return; }
        
        // actual player click handling
        matrix[row][col] = 1;
        buttons[row][col]->setText("X");
        buttons[row][col]->setDisabled(true);

        // checking winning condition for player
        if(CheckMatrix(matrix) == 1){
            QMessageBox::information(this, "Game over", "You win");
            QApplication::quit();
        }

        // checks if matrix is full
        if (!checkFreeCells(matrix)){
            QMessageBox::information(this, "Game over", "Grid is full");
            QApplication::quit();
        }

        // shift control to AI
        makeAiMove();
    }

    void makeAiMove(){
        int row = (dist(gen))%3;
        int col = (dist(gen))%3;

        // actual AI gameplay
        if (matrix[row][col]==0){
            matrix[row][col] = 2;
            buttons[row][col]->setText("O");
            buttons[row][col]->setDisabled(true);
        } else makeAiMove(); // to handle replay

        // checking winning condition for AI
        if(CheckMatrix(matrix) == 2){
            QMessageBox::information(this, "Game over", "AI wins");
            QApplication::quit();
        }

        // checks if matrix is full
        if (!checkFreeCells(matrix)){
            QMessageBox::information(this, "Game over", "Grid is full");
            QApplication::quit();
        }
    }



private:
    // Define other necessary members, like the game matrix, buttons, etc.
    QPushButton *buttons[3][3];
    int matrix[3][3];
}; // class TicTacToe

int main() {
    int argc=0;
    QApplication app(argc, 0);
    TicTacToe game;
    game.show();
    return app.exec();
}

#include "qt_main.moc"
