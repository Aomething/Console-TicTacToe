#include "board.h"

int main() {

    Board TTT;
    char cmd;
    bool useBot;
    bool startGame = false;
    while (!startGame) {
        cout << "\nEnable Bot for Player 2? [Y/N]" << endl;
        cin >> cmd;
        switch(cmd) {
            case 'y':
            case 'Y':
                useBot = true;
                startGame = true;
            break;

            case 'n':
            case 'N':
                useBot = false;
                startGame = true;
            break;
            default:
                cout << "[ERROR] : Invalid input. Answer Y [yes] or N [no]" << endl;
            break;
        }
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
    TTT.startGame(useBot);

    return 0;
}