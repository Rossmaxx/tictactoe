#include <QtWidgets>

#include "tt_core.h"


class TicTacToe : public QWidget {
    Q_OBJECT

public:
    TicTacToe(QWidget *parent = nullptr) : QWidget(parent) {
        // Set up your game board UI (buttons, layout)
        // For example:
        QGridLayout *gridLayout = new QGridLayout(this);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                QPushButton *button = new QPushButton("");
                gridLayout->addWidget(button, i, j);
                buttons[i][j] = button;
                connect(button, &QPushButton::clicked, this, [=]() { playerClick(i, j); });
            }
        }
    }

    // Function to handle button clicks
    void playerClick(int row, int col) {
        // Call your game logic functions from ttt_core.h here
        // For example:
        // Make a move in the game matrix using ttt_core functions
        // Update the button text or icon based on the game state
    }

    void runGame(){
        while (1){ break; }
    }



private:
    // Define other necessary members, like the game matrix, buttons, etc.
    // ...
    QPushButton *buttons[3][3];
}; // class TicTacToe

int main() {
    QApplication app(0, 0);
    TicTacToe game;
    game.show();
    return app.exec();
}

#include "qt_main.moc"
