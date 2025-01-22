#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Board {
    public:
        // interact with individual slots of the board
        void setSlot(int slot);

        // after each move, determine which player won, or if there was a tie
        int winCheck();

        // reset slots 
        void resetBoard();

        // print the board to the terminal
        void printBoard();

        // start game - reset game info, then start the game over
        void startGame(bool useBot);

        // return winner, used for printing results
        int getWinner();

        // return if all slots are full, used for checking ties
        bool isFull();

        // find best move for bot to make, return the index of the move
        int bestMove();

        // returns scores to help determine which moves are optimal
        int miniMax(int depth, bool isMaximiser);

    private:
        char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
        int playerTurn = 0;
        bool gameEnd = false;
        int winner = 0;
};