#include <iostream>
#include <vector>

using namespace std;

// void printGameBoard() {
//     cout << "1 | 2 | 3 \n";
//     cout << "--------- \n";
//     cout << "4 | 5 | 6 \n";
//     cout << "--------- \n";
//     cout << "7 | 8 | 9 \n";
// }

void fillGameBoard(vector<char> &gameBoard) {
    for(int i = 0; i < 9; i++) {
        gameBoard.push_back(' ');
    }
}

void displayCurrentGameBoard(vector<char> gameboard) {
    cout << gameboard.at(0) << " | " << gameboard.at(1) << " | " << gameboard.at(2) << "      " << "1 | 2 | 3 " << "\n";
    cout << "---------" << "      " << "---------" << "\n";
    cout << gameboard.at(3) << " | " << gameboard.at(4) << " | " << gameboard.at(5) << "      " << "4 | 5 | 6 " << "\n";
    cout << "---------" << "      " << "---------" << "\n";
    cout << gameboard.at(6) << " | " << gameboard.at(7) << " | " << gameboard.at(8) << "      " << "7 | 8 | 9 " << "\n";
}

void playerXMakeMove(vector<char> gameboard, int gameOver, bool player1Won,bool player2Won){

}

void playerOMakeMove(vector<char> gameboard, int gameOver, bool player1Won,bool player2Won){

}

void makeAMove(vector<char> gameboard, int playersTurn, int gameOver, bool player1Won, bool player2Won){
    if(playersTurn == 0){
        playerXMakeMove(gameboard,gameOver,player1Won,player2Won);
        playersTurn = 1;
    } else if(playersTurn == 1){
        
        playersTurn = 0;
    }
}

int main() {
    int gameOver = 0;
    int playersTurn = 0;

    bool player1Won = false;
    bool player2Won = false;

    vector<char> gameBoard;

    fillGameBoard(gameBoard);

    while(gameOver == 0){
        displayCurrentGameBoard(gameBoard);
    }

    return 0;
}
