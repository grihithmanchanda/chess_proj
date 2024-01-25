#include "board.h"

using namespace std;

Board::Board() {
    board = vector<vector<Space> >(8, vector<Space>(8, Space()));
}

Piece* Board::getPiece(int rank, int file) {
    if (board[rank][file].getEmpty()) {
        return NULL;
    }
    return board[rank][file].getPiece();
}

void Board::setPiece(Piece* piece, int rank, int file) {
    board[rank][file].setPiece(piece);
    piece->setRank(rank);
    piece->setFile(file);
}

set< vector<int> > Board::getMoves(Piece* piece) {
    switch (piece->getType()) {
        case KNIGHT:
            return knightMoves((Knight*) piece);
        default:
            cout << "ERROR: Piece not found" << endl;
    }
}

// Knights
vector< vector<int> > Board::knightMoveOffsets = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                                             {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

set< vector<int> > Board::knightMoves(Knight* knight) {
    set< vector<int> > moves;
    for (auto offset : Board::knightMoveOffsets) {
        int newRank = knight->getRank() + offset[0];
        int newFile = knight->getFile() + offset[1];
        if (newRank >= 0 && newRank < 8) {
            if (newFile >= 0 && newFile < 8) {
                if (!getPiece(newRank, newFile) || getPiece(newRank, newFile)->getWhite() != knight->getWhite()) {
                    moves.insert({newRank, newFile});
                }
            }
        }
    }
    return moves;
}
