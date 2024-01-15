#include "board.h"

using namespace std;

Board::Board() : kw(true), kb(false),
                 qw(true), qb(false)              
                {
    board = vector<vector<Space> >(8, vector<Space>(8, Space()));
    board[0][4].setPiece(&kw);
    board[7][4].setPiece(&kb);
    board[0][3].setPiece(&qw);
    board[7][3].setPiece(&qb);
}

int main() {
    Board game;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (game.board[i][j].getEmpty()) {
                cout << "_";
            } else {
                cout << game.board[i][j].getPiece()->getString();
            }
        }
        cout << endl;
    }

    return 0;
}