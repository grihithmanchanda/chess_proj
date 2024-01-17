#include "board.h"

int main() {
    Board board;
    King kw(true);
    King kb(false);
    Queen qw(true);
    Queen qb(false);
    vector<Rook> rw(2, Rook(true));
    vector<Rook> rb(2, Rook(false));
    vector<Bishop> bw(2, Bishop(true));
    vector<Bishop> bb(2, Bishop(false));
    vector<Knight> nw(2, Knight(true));
    vector<Knight> nb(2, Knight(false));
    vector<Pawn> pw(8, Pawn(true));
    vector<Pawn> pb(8, Pawn(false));

    board.setPiece(&rw[0], 0, 0);
    board.setPiece(&nw[0], 0, 1);
    board.setPiece(&bw[0], 0, 2);
    board.setPiece(&qw, 0, 3);
    board.setPiece(&kw, 0, 4);
    board.setPiece(&bw[1], 0, 5);
    board.setPiece(&nw[1], 0, 6);
    board.setPiece(&rw[1], 0, 7);
    
    board.setPiece(&rb[0], 7, 0);
    board.setPiece(&nb[0], 7, 1);
    board.setPiece(&bb[0], 7, 2);
    board.setPiece(&qb, 7, 3);
    board.setPiece(&kb, 7, 4);
    board.setPiece(&bb[1], 7, 5);
    board.setPiece(&nb[1], 7, 6);
    board.setPiece(&rb[1], 7, 7);

    for (int file = 0; file < 8; file++) {
        board.setPiece(&pw[file], 1, file);
        board.setPiece(&pb[file], 6, file);
    }

    // check setup
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece* piece = board.getPiece(i, j);
            if (piece) {
                cout << piece->getString();
            } else {
                cout << "_";
            }
        }
        cout << endl;
    }

    for (auto move : nb[1].getMoves()) {
        cout << move[0] << ", " << move[1] << endl;
    }

    return 0;
}