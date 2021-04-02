//Tic Tac Toe Game in C++

#include <iostream>
#include <stdlib.h>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

int choice;
int row, column;
char turn = 'X';
bool draw = false;


void DisplayBoard() {

    cout << "PLAYER - 1 [X]\t PLAYER - 2 [O]\n\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << " \n";
    cout << "\t_____|_____|_____\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << " \n";
    cout << "\t_____|_____|_____\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << " \n";
    cout << "\t     |     |     \n";
}


void PlayerTrun() {
    if (turn == 'X') {
        cout << "\n\tPlayer - 1 [X] turn : ";
    }
    else if (turn == 'O') {
        cout << "\n\tPlayer - 2 [O] turn : ";
    }

    cin >> choice;

    switch (choice) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        
        default:
            cout << "Invalid Move";
    }

    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O') {
        //updating the position for 'X' symbol if
        //it is not already occupied
        board[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O') {
        //updating the position for 'O' symbol if
        //it is not already occupied
        board[row][column] = 'O';
        turn = 'X';
    }
    else {
        cout << "Box already filled in. Please choose another one!!\n";
        PlayerTrun();
    }
    DisplayBoard();
}

//Function to get the game status e.g. GAME WON, GAME DRAW GAME IN CONTINUE MODE
bool isGameOver() {
    //checking the win for Simple Rows and Simple Column
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || 
            board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return true;

    //checking the win for both diagonal
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || 
        board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return true;

    //Checking the game is in continue mode or not
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;

    //Checking the if game already draw
    draw = true;

    return true;
}

//Program Main Method

int main() {
    cout << " === T I C K - T A C - T O E - G A M E ===\n";
    cout << "\tFOR 2 PLAYERS\n\t";

    while (!isGameOver()) {
        DisplayBoard();
        PlayerTrun();
        isGameOver();
    }

    if (turn == 'X' && draw == false) {
        cout << "\n\nCongratulations! Player with 'O' has won the game\n";
    }
    
    else if (turn == 'O' && draw == false) {
        cout << "\n\nCongratulations! Player with 'X' has won the game\n";
    }

    else
        cout << "\n\nGAME DRAW!!!\n\n";
}