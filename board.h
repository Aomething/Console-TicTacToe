#include <iostream>

using namespace std;

class Board {
    public:
        // interact with individual slots of the board
        void setSlot(int slot);
        char getSlot(int slot);

        // after each move, determine which player won, or if there was a tie
        void winCheck();

        // reset slots 
        void resetBoard();

        // print the board to the terminal
        void printBoard();

        // start game - reset game info, then start the game over
        void startGame();

        bool gameEndCheck();

        int getWinner();

        bool isFull();
    private:
        char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
        int playerTurn = 0;
        bool gameEnd = false;
        int winner = 0;

};