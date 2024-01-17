#include "board.h"

using namespace std;

Board::Board() : kw(true), kb(false),
                 qw(true), qb(false),
                 rw(2, Rook(true)), rb(2, Rook(false)),
                 bw(2, Bishop(true)), bb(2, Bishop(false)),
                 nw(2, Knight(true)), nb(2, Knight(false)),
                 pw(8, Pawn(true)), pb(8, false)     
{
    board = vector<vector<Space> >(8, vector<Space>(8, Space()));

    board[0][0].setPiece(&rw[0]);
    board[0][1].setPiece(&nw[0]);
    board[0][2].setPiece(&bw[0]);
    board[0][3].setPiece(&qw);
    board[0][4].setPiece(&kw);
    board[0][5].setPiece(&bw[1]);
    board[0][6].setPiece(&nw[1]);
    board[0][7].setPiece(&rw[1]);
    
    board[7][0].setPiece(&rb[0]);
    board[7][1].setPiece(&nb[0]);
    board[7][2].setPiece(&bb[0]);
    board[7][3].setPiece(&qb);
    board[7][4].setPiece(&kb);
    board[7][5].setPiece(&bb[1]);
    board[7][6].setPiece(&nb[1]);
    board[7][7].setPiece(&rb[1]);

    for (int file = 0; file < 8; file++) {
        board[1][file].setPiece(&pw[file]);
        board[6][file].setPiece(&pb[file]);
    }

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