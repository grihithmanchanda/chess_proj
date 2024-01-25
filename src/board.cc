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

void Board::getMoves(Piece* piece, move_list* moves) {
    switch (piece->getType()) {
        case KNIGHT:
            knightMoves(piece, moves);
            break;
        case BISHOP:
            bishopMoves(piece, moves);
            break;
        case ROOK:
            rookMoves(piece, moves);
            break;
        case QUEEN:
            bishopMoves(piece, moves);
            rookMoves(piece, moves);
            break;
        default:
            cout << "ERROR: Piece not found" << endl;
    }
}

// Knights
vector< vector<int> > Board::knightMoveOffsets = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                                             {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

void Board::knightMoves(Piece* piece, move_list* moves) {
    for (auto offset : Board::knightMoveOffsets) {
        int newRank = piece->getRank() + offset[0];
        int newFile = piece->getFile() + offset[1];
        if (newRank >= 0 && newRank < 8) {
            if (newFile >= 0 && newFile < 8) {
                if (!getPiece(newRank, newFile) || getPiece(newRank, newFile)->getWhite() != piece->getWhite()) {
                    moves->insert({newRank, newFile});
                }
            }
        }
    }
}

// Bishops
void Board::bishopMoves(Piece* piece, move_list* moves) {
    // NE direction
    int newRank = piece->getRank() + 1;
    int newFile = piece->getFile() + 1;

    while (newRank < 8 && newFile < 8) {
        if (!getPiece(newRank, newFile)) {
            moves->insert({newRank, newFile});
        } else {
            if (getPiece(newRank, newFile)->getWhite() != piece->getWhite()) {
                moves->insert({newRank, newFile});
            }
            break;
        }
        newRank++;
        newFile++;
    } 

    // NW 
    newRank = piece->getRank() + 1;
    newFile = piece->getFile() - 1;

    while (newRank < 8 && newFile >= 0) {
        if (!getPiece(newRank, newFile)) {
            moves->insert({newRank, newFile});
        } else {
            if (getPiece(newRank, newFile)->getWhite() != piece->getWhite()) {
                moves->insert({newRank, newFile});
            }
            break;
        }
        newRank++;
        newFile--;
    } 

    // SE
    newRank = piece->getRank() - 1;
    newFile = piece->getFile() + 1;

    while (newRank >= 0 && newFile < 8) {
        if (!getPiece(newRank, newFile)) {
            moves->insert({newRank, newFile});
        } else {
            if (getPiece(newRank, newFile)->getWhite() != piece->getWhite()) {
                moves->insert({newRank, newFile});
            }
            break;
        }
        newRank--;
        newFile++;
    } 

    // SW
    newRank = piece->getRank() - 1;
    newFile = piece->getFile() - 1;

    while (newRank >= 0 && newFile >= 0) {
        if (!getPiece(newRank, newFile)) {
            moves->insert({newRank, newFile});
        } else {
            if (getPiece(newRank, newFile)->getWhite() != piece->getWhite()) {
                moves->insert({newRank, newFile});
            }
            break;
        }
        newRank--;
        newFile--;
    }
}

// Rooks 
void Board::rookMoves(Piece* piece, move_list* moves) {
    // N
    int newRank = piece->getRank() + 1;
    int newFile = piece->getFile();
    while (newRank < 8) {
        if (!getPiece(newRank, newFile)) {
            moves->insert({newRank, newFile});
        } else {
            if (getPiece(newRank, newFile)->getWhite() != piece->getWhite()) {
                moves->insert({newRank, newFile});
            }
            break;
        }
        newRank++;
    }

    // S
    newRank = piece->getRank() - 1;
    while (newRank >= 0) {
        if (!getPiece(newRank, newFile)) {
            moves->insert({newRank, newFile});
        } else {
            if (getPiece(newRank, newFile)->getWhite() != piece->getWhite()) {
                moves->insert({newRank, newFile});
            }
            break;
        }
        newRank--;
    }

    // E
    newRank = piece->getRank();
    newFile = piece->getFile() + 1;
    while (newFile < 8) {
        if (!getPiece(newRank, newFile)) {
            moves->insert({newRank, newFile});
        } else {
            if (getPiece(newRank, newFile)->getWhite() != piece->getWhite()) {
                moves->insert({newRank, newFile});
            }
            break;
        }
        newFile++;
    }

    // W
    newFile = piece->getFile() - 1;
    while (newFile >= 0) {
        if (!getPiece(newRank, newFile)) {
            moves->insert({newRank, newFile});
        } else {
            if (getPiece(newRank, newFile)->getWhite() != piece->getWhite()) {
                moves->insert({newRank, newFile});
            }
            break;
        }
        newFile--;
    }
}
