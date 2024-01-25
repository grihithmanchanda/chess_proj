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
        case BISHOP:
            return bishopMoves((Bishop*) piece);
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

// Bishops

set< vector<int> > Board::bishopMoves(Bishop* bishop) {

    set< vector<int> > moves;

    // NE direction
    int newRank = bishop->getRank() + 1;
    int newFile = bishop->getFile() + 1;

    while (newRank < 8 && newFile < 8) {
        if (!getPiece(newRank, newFile)) {
            moves.insert({newRank, newFile});
        } else {
            if (getPiece(newRank, newFile)->getWhite() != bishop->getWhite()) {
                moves.insert({newRank, newFile});
            }
            break;
        }
        newRank++;
        newFile++;
    } 

    // NW 
    newRank = bishop->getRank() + 1;
    newFile = bishop->getFile() - 1;

    while (newRank < 8 && newFile >= 0) {
        if (!getPiece(newRank, newFile)) {
            moves.insert({newRank, newFile});
        } else {
            if (getPiece(newRank, newFile)->getWhite() != bishop->getWhite()) {
                moves.insert({newRank, newFile});
            }
            break;
        }
        newRank++;
        newFile--;
    } 

    // SE
    newRank = bishop->getRank() - 1;
    newFile = bishop->getFile() + 1;

    while (newRank >= 0 && newFile < 8) {
        if (!getPiece(newRank, newFile)) {
            moves.insert({newRank, newFile});
        } else {
            if (getPiece(newRank, newFile)->getWhite() != bishop->getWhite()) {
                moves.insert({newRank, newFile});
            }
            break;
        }
        newRank--;
        newFile++;
    } 

    // SW
    newRank = bishop->getRank() - 1;
    newFile = bishop->getFile() - 1;

    while (newRank >= 0 && newFile >= 0) {
        if (!getPiece(newRank, newFile)) {
            moves.insert({newRank, newFile});
        } else {
            if (getPiece(newRank, newFile)->getWhite() != bishop->getWhite()) {
                moves.insert({newRank, newFile});
            }
            break;
        }
        newRank--;
        newFile--;
    }

    return moves;
}
