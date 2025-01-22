#include "board.h"

#define player 'X'
#define bot 'O'

// weights for W/L/T, used for minimax algorithm
#define win 1
#define tie 0
#define loss -1

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

// after each move, determine which player won, or if there was a tie
int Board::winCheck() {
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
        if (board[0] == player) {
            winner = 1;
            gameEnd = true;
        }
        else if (board[0] == bot) {
            winner = 2;
            gameEnd = true;
        } 
    }

    // win condition 2
    else if (board[3] == board[4] && board[4] == board[5]) {
        if (board[3] == player) {
            winner = 1;
            gameEnd = true;
        }
        else if (board[3] == bot) {
            winner = 2;
            gameEnd = true;
        } 
    }

    // win condition 3
    else if (board[6] == board[7] && board[7] == board[8]) {
        if (board[6] == player) {
            winner = 1;
            gameEnd = true;
        }
        else if (board[6] == bot) {
            winner = 2;
            gameEnd = true;
        } 
    }

    // win condition 4
    else if (board[0] == board[3] && board[3] == board[6]) {
        if (board[0] == player) {
            winner = 1;
            gameEnd = true;
        }
        else if (board[0] == bot) {
            winner = 2;
            gameEnd = true;
        } 
    }

    // win condition 5
    else if (board[1] == board[4] && board[4] == board[7]) {
        if (board[1] == player) {
            winner = 1;
            gameEnd = true;
        }
        else if (board[1] == bot) {
            winner = 2;
            gameEnd = true;
        } 
    }

    // win condition 6
    else if (board[2] == board[5] && board[5] == board[8]) {
        if (board[2] == player) {
            winner = 1;
            gameEnd = true;
        }
        else if (board[2] == bot) {
            winner = 2;
            gameEnd = true;
        } 
    }

    // win condition 7
    else if (board[0] == board[4] && board[4] == board[8]) {
        if (board[0] == player) {
            winner = 1;
            gameEnd = true;
        }
        else if (board[0] == bot) {
            winner = 2;
            gameEnd = true;
        } 
    }

    // win condition 8
    else if (board[2] == board[4] && board[4] == board[6]) {
        if (board[2] == player) {
            winner = 1;
            gameEnd = true;
        }
        else if (board[2] == bot) {
            winner = 2;
            gameEnd = true;
        } 
    }
    else {
        // tie condition (board is full, but no win conditions triggered)
        if (isFull()) {
            gameEnd = true;
            winner = 3;
        }

        // game isnt over yet
        else {
            winner = 0;
            gameEnd = false;
        }
    }
    return winner;
}

// return if all slots are full, used for checking ties
bool Board::isFull() {
    //check every slot, and if any are empty, the board is not full
    for (int i = 0; i < 9; i++) {
        if (board[i] != player && board[i] != bot) {
            return false;
        }
    }
    return true;
}

// reset slots 
void Board::resetBoard() {
    board[0] = ' ';
    board[1] = ' ';
    board[2] = ' ';
    board[3] = ' ';
    board[4] = ' ';
    board[5] = ' ';
    board[6] = ' ';
    board[7] = ' ';
    board[8] = ' ';
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
void Board::startGame(bool useBot) {
    resetBoard();
    gameEnd = false;
    winner = 0;
    playerTurn = 2;
    int inputSlot;

    if (useBot) {
        // keep asking for inputs, swapping between player and bot each time
        while (!gameEnd) {
            printBoard();
            if (playerTurn == 1) {
                cout << "\nChoose a slot (X)" << endl;
                cin >> inputSlot;
                setSlot(inputSlot);
            }
            else {
                //cout << "\nChoose a slot (O)" << endl;
                //cin >> inputSlot;
                inputSlot = bestMove();
                setSlot(inputSlot);
            }
            winCheck();
        }
    }
    else {
        // keep asking for inputs, swapping between players each time
        while (!gameEnd) {
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
    }

    //game over, print results
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
    return;
}

// return winner, used for printing results
int Board::getWinner() {
    
    /*
        0 : no winner   (game in progress)
        1 : player 1    (game over, player1 wins)
        2 : player 2    (game over, player2/bot wins)
        3 : tie         (game over, no winner)
    */

    return winner;
}

// find best move for bot to make, return the index of the move
int Board::bestMove() {
    int bestScore = -1000;
    int move;
    int score;
    // for every slot
    for (int i = 0; i < 9; i++) {
        // if the slot is open
        if (board[i] == ' ') {
            // make a move at that spot
            board[i] = bot;
            // check to see if future outcomes are optimal
            score = miniMax(1, false);
            //undo move
            board[i] = ' ';
            if (score > bestScore) {
                move = i+1;
            }
        }
    }
    cout << "move: " << move << endl;
    return move;
}

// returns scores to help determine which moves are optimal
int Board::miniMax(int depth, bool isMaximiser) {
    // check win conditions
    winCheck();
    // if current board setup is a win/lose/tie condition, return score to previous iteration
    //printBoard();
    switch(winner) { 
        case 0:
            //cout << "GAME NOT DONE" << endl;
        break;

        case 1:
            gameEnd = false;
            //cout << "LOSE CONDITION" << endl;
            return -1;
        break;

        case 2:
            gameEnd = false;
            //cout << "WIN CONDITION" << endl;
            return 1;
        break;

        case 3:
            gameEnd = false;
            //cout << "TIE CONDITION" << endl;
            return 0;
        break;
    }  
    // if not a W/L/T condition, continue recursion
    if (isMaximiser) {
        int bestScore = -1000;
        int score;
        for (int i = 0; i < 9; i++) {
            // if the slot is open
            if (board[i] == ' ') {
                // make a move at that spot
                board[i] = bot;
                // go down a depth, assume opponent make optimal decision
                score = miniMax(depth + 1, false);
                // undo move
                board[i] = ' ';
                // if current iteration is best so far, save that value and continue
                if (score > bestScore) {
                    bestScore = score;
                }
            }
            cout << "Current Depth: " << depth << endl;
            cout << "\tScore " << score << endl;
            cout << "\tbestScore " << bestScore << endl;
        }
        //cout << "SCORE (Bot)\t: " << bestScore << endl;
        return bestScore;
    }
    else {
        //minimizer
        int bestScore = 1000;
        int score = -1000;
        for (int i = 0; i < 9; i++) {
            // if the slot is open
            if (board[i] == ' ') {
                // make a move at that spot
                board[i] = player;
                // go down a depth, assume opponent make optimal decision
                score = miniMax(depth + 1,true);
                // undo move
                board[i] = ' ';
                // if current iteration is best so far, save that value and continue
                if (score < bestScore) {
                    bestScore = score;
                }
            }
            cout << "Current Depth: " << depth << endl;
            cout << "\tScore " << score << endl;
            cout << "\tbestScore " << bestScore << endl;
        }
        //cout << "SCORE (Player)\t: " << bestScore << endl;
        return bestScore;
    }   
}