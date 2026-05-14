#include <iostream>
using namespace std;

char board[4][4] = {
    {'1','2','3','4'},
    {'5','6','7','8'},
    {'9','0','1','2'},
    {'3','4','5','6'}
};

char player = 'X';

// Function to draw board
void drawBoard() {
    cout << "\n";
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            cout << board[i][j];
            if(j<3) cout << " | ";
        }
        cout << "\n";
        if(i<3) cout << "--|---|---|---\n";
    }
    cout << "\n";
}

// Function to mark board
void markBoard(int choice) {
    int row = (choice-1)/4;
    int col = (choice-1)%4;

    if(board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = player;
    } else {
        cout << "Invalid move! Try again.\n";
        int newChoice;
        cin >> newChoice;
        markBoard(newChoice);
    }
}

// Function to check winner
bool checkWin() {
    for(int i=0; i<4; i++) {
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player)
            return true;
        if(board[0][i]==player && board[1][i]==player && board[2][i]==player)
            return true;
    }
    if(board[0][0]==player && board[1][1]==player && board[2][2]==player)
        return true;
    if(board[0][2]==player && board[1][1]==player && board[2][0]==player)
        return true;

    return false;
}

// Main function
int main() {
    int choice;
    int turns = 0;

    while(true) {
        drawBoard();
        cout << "Player " << player << ", enter your choice: ";
        cin >> choice;

        markBoard(choice);
        turns++;

        if(checkWin()) {
            drawBoard();
            cout << "Player " << player << " wins!\n";
            break;
        }

        if(turns == 9) {
            drawBoard();
            cout << "It's a draw!\n";
            break;
        }

        // Switch player
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}