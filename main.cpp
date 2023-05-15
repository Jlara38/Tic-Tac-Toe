#include <iostream>
#include <vector>

using namespace std;

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
    cout << "\n";
}


void retryAfterWin(vector<char> &gameboard, int &turns, int &playersTurn, int &gameOver, bool &player1Won, bool &player2Won){
    char response;
    cout << "Would you like to play again? (y/n): ";
    cin >> response;
    cout << "\n";

    if(toupper(response) == 'Y'){
        gameboard.clear();
        cout << "Welcome to Tic-Tac-Toe" << "\n";
        fillGameBoard(gameboard);
        playersTurn = 0;
        gameOver = 0;
        turns = 0;
        player1Won = false;
        player2Won = false;
    } else if(toupper(response) == 'N') {
        gameOver = 1;
        cout << "Thank you for playing!" << "\n";
    } else {
        cout << "Please enter a valid input" << "\n";
        retryAfterWin(gameboard, turns, playersTurn, gameOver, player1Won, player2Won);
    }
}

void retryAfterTie(vector<char> &gameboard, int &turns, int &playersTurn, int &gameOver, bool &player1Won, bool &player2Won){
    char response;
    cout << "A tie was reached, would you like to play again? (y/n): ";
    cin >> response;
    cout << "\n";

    if(toupper(response) == 'Y'){
        gameboard.clear();
        cout << "Welcome to Tic-Tac-Toe" << "\n";
        fillGameBoard(gameboard);
        playersTurn = 0;
        gameOver = 0;
        turns = 0;
        player1Won = false;
        player2Won = false;
    } else if(toupper(response) == 'N') {
        gameOver = 1;
        cout << "Thank you for playing!" << "\n";
    } else {
        cout << "Please enter a valid input" << "\n";
        retryAfterTie(gameboard, turns, playersTurn, gameOver, player1Won, player2Won);
    }
}

void playerXMakeMove(vector<char> &gameboard, int &gameOver, bool &player1Won,bool &player2Won){
    int position;
    cout << "Choose a position from 1-9 to place the X: ";
    cin >> position;
    cout << "\n";

    position -= 1;

    if (position < 0 || position >= 9) {
        cout << "Position is invalid, please pick another postion" << "\n";
        playerXMakeMove(gameboard,gameOver,player1Won,player2Won);
    } else if(gameboard.at(position) != 'X' && gameboard.at(position) != 'O') {
        gameboard.at(position) = 'X'; 
    } else if(gameboard.at(position) == 'X' || gameboard.at(position) == 'O'){
        cout << "Position is occupied, please pick another postion" << "\n";
        playerXMakeMove(gameboard,gameOver,player1Won,player2Won);
    } else {
        cout << "Invalid input for position" << "\n";
        playerXMakeMove(gameboard,gameOver,player1Won,player2Won);
    }
}

void playerOMakeMove(vector<char> &gameboard, int &gameOver, bool &player1Won,bool &player2Won){
    int position;
    cout << "Choose a position from 1-9 to place the O: ";
    cin >> position;
    cout << "\n";

    position -= 1;

    if (position < 0 || position >= 9) {
        cout << "Position is invalid, please pick another postion" << "\n";
        playerOMakeMove(gameboard,gameOver,player1Won,player2Won);
    } else if(gameboard.at(position) != 'X' && gameboard.at(position) != 'O') {
        gameboard.at(position) = 'O'; 
    } else if(gameboard.at(position) == 'X' || gameboard.at(position) == 'O'){
        cout << "Position is occupied, please pick another postion" << "\n";
        playerOMakeMove(gameboard,gameOver,player1Won,player2Won);
    } else {
        cout << "Invalid input for position" << "\n";
        playerOMakeMove(gameboard,gameOver,player1Won,player2Won);
    }
}


void callForWinMessage(char symbol){
    cout << "Congrats!! player (";
    cout << symbol;
    cout << ") you have won" << "\n";
}

void checkIfGameIsWon(vector<char> &gameboard, int &turns, int playersTurn, char symbol, int &gameOver, bool &playerWon, bool &player1Won, bool &player2Won){
    if(gameboard.at(0) == symbol && gameboard.at(4) == symbol && gameboard.at(8) == symbol){
        callForWinMessage(symbol);
        playerWon = true;
        gameOver = 1;
        displayCurrentGameBoard(gameboard);
        retryAfterWin(gameboard,turns,playersTurn,gameOver,player1Won,player2Won);
    } else if (gameboard.at(2) == symbol && gameboard.at(4) == symbol && gameboard.at(6) == symbol){
        callForWinMessage(symbol);
        playerWon = true;
        gameOver = 1;
        displayCurrentGameBoard(gameboard);
        retryAfterWin(gameboard,turns,playersTurn,gameOver,player1Won,player2Won);
    } else if (gameboard.at(0) == symbol && gameboard.at(1) == symbol && gameboard.at(2) == symbol){
        callForWinMessage(symbol);
        playerWon = true;
        gameOver = 1;
        displayCurrentGameBoard(gameboard);
        retryAfterWin(gameboard,turns,playersTurn,gameOver,player1Won,player2Won);
    } else if (gameboard.at(3) == symbol && gameboard.at(4) == symbol && gameboard.at(5) == symbol){
        callForWinMessage(symbol);
        playerWon = true;
        gameOver = 1;
        displayCurrentGameBoard(gameboard);
        retryAfterWin(gameboard,turns,playersTurn,gameOver,player1Won,player2Won);
    } else if (gameboard.at(6) == symbol && gameboard.at(7) == symbol && gameboard.at(8) == symbol){
        callForWinMessage(symbol);
        playerWon = true;
        gameOver = 1;
        displayCurrentGameBoard(gameboard);
        retryAfterWin(gameboard,turns,playersTurn,gameOver,player1Won,player2Won);
    } else if (gameboard.at(0) == symbol && gameboard.at(3) == symbol && gameboard.at(6) == symbol){
        callForWinMessage(symbol);
        playerWon = true;
        gameOver = 1;
        displayCurrentGameBoard(gameboard);
        retryAfterWin(gameboard,turns,playersTurn,gameOver,player1Won,player2Won);
    } else if (gameboard.at(1) == symbol && gameboard.at(4) == symbol && gameboard.at(7) == symbol){
        callForWinMessage(symbol);
        playerWon = true;
        gameOver = 1;
        displayCurrentGameBoard(gameboard);
        retryAfterWin(gameboard,turns,playersTurn,gameOver,player1Won,player2Won);
    } else if (gameboard.at(2) == symbol && gameboard.at(5) == symbol && gameboard.at(8) == symbol){
        callForWinMessage(symbol);
        playerWon = true;
        gameOver = 1;
        displayCurrentGameBoard(gameboard);
        retryAfterWin(gameboard,turns,playersTurn,gameOver,player1Won,player2Won);
    } else{
        playerWon = false;
        gameOver = 0;
    }
}


void makeAMove(vector<char> &gameboard, int &turns, int &playersTurn, int &gameOver, bool &player1Won, bool &player2Won){
    char xSym = 'X';
    char ySym = 'O';
    if(playersTurn == 0 && gameOver != 1){
        playerXMakeMove(gameboard,gameOver,player1Won,player2Won);
        checkIfGameIsWon(gameboard, turns,playersTurn,xSym,gameOver,player1Won,player1Won,player2Won);
        playersTurn = 1;
    } else if(playersTurn == 1 && gameOver != 1){
        playerOMakeMove(gameboard,gameOver,player1Won,player2Won);
        checkIfGameIsWon(gameboard, turns,playersTurn,ySym,gameOver,player1Won,player1Won,player2Won);
        playersTurn = 0;
    }
}


int main() {
    int turns = 0;
    int gameOver = 0;
    int playersTurn = 0;

    bool player1Won = false;
    bool player2Won = false;

    vector<char> gameBoard;

    cout << "Welcome to Tic-Tac-Toe" << "\n";
    fillGameBoard(gameBoard);

    while(gameOver != 1){
        if(turns == 9){
            displayCurrentGameBoard(gameBoard);
            retryAfterTie(gameBoard,turns,playersTurn,gameOver,player1Won,player2Won);
        }
        displayCurrentGameBoard(gameBoard);
        makeAMove(gameBoard, turns,playersTurn, gameOver, player1Won, player2Won);
        turns += 1;
    }


    return 0;
}
