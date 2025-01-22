#include "board.h"

#define player 'X'
#define bot 'O'

// interact with individual slots of the board
void Board::setSlot(int slot) {
    // error handling

    //if slot is not in range
    if (slot > 9 || slot < 1) {
        cout << "[ERROR] : Invalid slot. Chosen slot must be between 1 and 9" << endl;
        return;
    }

    // if slot was already written in    
    if (board[slot-1] == player || board[slot-1] == bot) {
        cout << "[ERROR] : Invalid Slot. Chosen slot must be empty" << endl;
        return;
    }

    if (playerTurn == 1) {
        board[slot-1] = player;
        playerTurn = 2;
    }
    else if (playerTurn == 2) {
        board[slot-1] = bot;
        playerTurn = 1;
    }

    return;
}

char Board::getSlot(int slot) {
    // error handling

    //if slot is not in range
    if (slot > 9 || slot < 1) {
        cout << "[ERROR] : Invalid slot. Slot must be between 0 and 8" << endl;
        return 'F';
    }

    return board[slot];
}

// after each move, determine which player won, or if there was a tie
void Board::winCheck() {
    /*
        Win Conditions:
            0 1 2
            3 4 5
            6 7 8
            0 3 6
            1 4 7
            2 5 8
            0 4 8
            2 4 6
    */

    // win condition 1
    if (board[0] == board[1] && board[1] == board[2]) {
        gameEnd = true;
        if (board[0] == player) {
            winner = 1;
        }
        else if (board[0] == bot) {
            winner = 2;
        } 
    }

    // win condition 2
    else if (board[3] == board[4] && board[4] == board[5]) {
        gameEnd = true;
        if (board[3] == player) {
            winner = 1;
        }
        else if (board[3] == bot) {
            winner = 2;
        } 
    }

    // win condition 3
    else if (board[6] == board[7] && board[7] == board[8]) {
        gameEnd = true;
        if (board[6] == player) {
            winner = 1;
        }
        else if (board[6] == bot) {
            winner = 2;
        } 
    }

    // win condition 4
    else if (board[0] == board[3] && board[3] == board[6]) {
        gameEnd = true;
        if (board[0] == player) {
            winner = 1;
        }
        else if (board[0] == bot) {
            winner = 2;
        } 
    }

    // win condition 5
    else if (board[1] == board[4] && board[4] == board[7]) {
        gameEnd = true;
        if (board[1] == player) {
            winner = 1;
        }
        else if (board[1] == bot) {
            winner = 2;
        } 
    }

    // win condition 6
    else if (board[2] == board[5] && board[5] == board[8]) {
        gameEnd = true;
        if (board[2] == player) {
            winner = 1;
        }
        else if (board[2] == bot) {
            winner = 2;
        } 
    }

    // win condition 7
    else if (board[0] == board[4] && board[4] == board[8]) {
        gameEnd = true;
        if (board[0] == player) {
            winner = 1;
        }
        else if (board[0] == bot) {
            winner = 2;
        } 
    }

    // win condition 8
    else if (board[2] == board[4] && board[4] == board[6]) {
        gameEnd = true;
        if (board[2] == player) {
            winner = 1;
        }
        else if (board[2] == bot) {
            winner = 2;
        } 
    }
    else {
        if (isFull()) {
            gameEnd = true;
            winner = 3;
        }
        else {
            winner = 0;
        }
    }
    return;
}

bool Board::isFull() {
    for (int i = 0; i < 9; i++) {
        if (board[i] != player && board[i] != bot) {
            return false;
        }
    }
    return true;
}

// reset slots 
void Board::resetBoard() {
    board[0] = '1';
    board[1] = '2';
    board[2] = '3';
    board[3] = '4';
    board[4] = '5';
    board[5] = '6';
    board[6] = '7';
    board[7] = '8';
    board[8] = '9';
    return;
}

// print the board to the terminal
void Board::printBoard() {
    cout << endl;
    cout << board[0] << " | " << board[1] << " | " << board[2] << endl; 
    cout << "--+---+--" << endl;
    cout << board[3] << " | " << board[4] << " | " << board[5] << endl; 
    cout << "--+---+--" << endl;
    cout << board[6] << " | " << board[7] << " | " << board[8] << endl; 
    cout << endl;
}

// start game - set up everything
void Board::startGame() {
    resetBoard();
    gameEnd = false;
    winner = 0;
    playerTurn = 1;
    int inputSlot;
    while (!gameEndCheck()) {
        printBoard();
        if (playerTurn == 1) {
            cout << "\nChoose a slot (X)" << endl;
        }
        else {
            cout << "\nChoose a slot (O)" << endl;
        }
        cin >> inputSlot;
        setSlot(inputSlot);
        winCheck();
    }
    printBoard();
    cout << "Game Over!";
    switch(winner) {
        case 1:
            cout << " Player 1 (X) Wins!" << endl;
        break;
        case 2:
            cout << " Player 2 (O) Wins!" << endl;
        break;  
        case 3:
            cout << " Nobody Wins! (Tie)" << endl;
        break;
    }

    cout << "\nGAME EXITING...\n";
}

bool Board::gameEndCheck() {
    return gameEnd;
}

int Board::getWinner() {
    
    /*
        0 : no winner   (game in progress)
        1 : player 1    (player)
        2 : player 2    (bot)
        3 : tie         (game over, no winner)
    */

    return winner;
}