#include <iostream>
#include <vector>

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
        void startGame(bool useBot);

        // check if game is over, used for exiting
        bool gameEndCheck();

        // return winner, used for printing results
        int getWinner();

        // return if all slots are full, used for checking ties
        bool isFull();

        // return best move for the bot to make
        int findBest(int path, int depth);

        // debug function, prints bot's vector of available moves
        void _printAvailable();

    private:
        char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
        int playerTurn = 0;
        bool gameEnd = false;
        int winner = 0;
        vector<int> AvailableMoves;
};