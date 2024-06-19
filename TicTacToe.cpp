#include <iostream>
#include <string>
using namespace std;

char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

bool gameOver = false;

string lastPlayer = " ";

void printBoard() {
    cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "----------" << endl;
    cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "----------" << endl;
    cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

void checkGame() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] & board[i][1] == board[i][2] & board[i][0] != ' ') {
            gameOver = true;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] & board[1][i] == board[2][i] & board[0][i] != ' ') {
            gameOver = true;
        }
    }
    if (board[0][0] == board[1][1] & board[1][1] == board[2][2] & board[0][0] != ' ') {
        gameOver = true;
    }
    if (board[0][2] == board[1][1] & board[1][1] == board[2][0] & board[0][2] != ' ') {
        gameOver = true;
    }
}

void XTurn() {
    cout << "\n\n";
    int choice;
    cout << "\n\nX's turn!\n\nEnter your row and column number: ";
    cin >> choice;
    int row = (choice / 10) - 1;
    int column = (choice % 10) - 1;
    if (board[row][column] != ' ') {
        cout << "That space is already taken!!! Pick another...";
        XTurn();
    } else {
        board[row][column] = 'X';
        printBoard();
    }
    lastPlayer = "X";
    checkGame();
}

void OTurn() {
    cout << "\n\n";
    int choice;
    cout << "\n\nO's turn!\n\nEnter your row and column number: ";
    cin >> choice;
    int row = (choice / 10) - 1;
    int column = (choice % 10) - 1;
    if (board[row][column] != ' ') {
        cout << "That space is already taken!!! Pick another...";
        OTurn();
    } else {
        board[row][column] = 'O';
        cout << "\n\n";
        printBoard();
    }
    lastPlayer = "O";
    checkGame();
}

int main() {
    cout << "\n\n";

    printBoard();
    while (!gameOver) {
        OTurn();
        if (gameOver) {
            break;
        }
        XTurn();
    }
    cout << "\n\n" + lastPlayer + " is the winner!!!\n\n";
    return 0;
}