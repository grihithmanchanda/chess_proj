#include "board.h"

using namespace std;

Board::Board() {
    board = vector<vector<Space> >(8, vector<Space>(8, Space()));
}

Piece* Board::getPiece(int rank, int file) {
    if (rank < 0 || rank > 7 ||
        file < 0 || file > 7 ||
        board[rank][file].getEmpty()) {

        return NULL;
    }
    return board[rank][file].getPiece();
}

void Board::setPiece(Piece* piece, int rank, int file) {
    board[rank][file].setPiece(piece);
    piece->setRank(rank);
    piece->setFile(file);
}

void Board::getMoves(Piece* piece, move_list* moves, bool careAboutCheck, bool attackMovesOnly) {
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
        case PAWN:
            pawnMoves((Pawn*) piece, moves, attackMovesOnly); // cast since pawns need to know if they moved
            break;
        case KING:
            kingMoves((King*) piece, moves, careAboutCheck);
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

// Pawns
void Board::pawnMoves(Pawn* pawn, move_list* moves, bool attackMovesOnly) {
    int direction = -1;
    if (pawn->getWhite()) {
        direction = 1;
    }

    int newRank = pawn->getRank() + direction;
    int newFile = pawn->getFile();

    if (!attackMovesOnly) {
        if (!getPiece(newRank, newFile)) {
            moves->insert({newRank, newFile});
            if (!pawn->getMoved() && !getPiece(newRank + direction, newFile)) {
                moves->insert({newRank + direction, newFile});
            }
        }
    }

    if (getPiece(newRank, newFile + 1) && getPiece(newRank, newFile + 1)->getWhite() != pawn->getWhite()) {
        moves->insert({newRank, newFile + 1});
    }
    if (getPiece(newRank, newFile - 1) && getPiece(newRank, newFile - 1)->getWhite() != pawn->getWhite()) {
        moves->insert({newRank, newFile - 1});
    }
}

// King
void Board::kingMoves(King* king, move_list* moves, bool careAboutCheck) {
    // N
    int newRank = king->getRank() + 1;
    int newFile = king->getFile();
    if (!getPiece(newRank, newFile) || getPiece(newRank, newFile)->getWhite() != king->getWhite()) {
        if (!careAboutCheck || !underAttack(newRank, newFile, king->getWhite())) {
            moves->insert({newRank, newFile});
        }
    }

    // S
    newRank = newRank - 2;
    if (!getPiece(newRank, newFile) || getPiece(newRank, newFile)->getWhite() != king->getWhite()) {
        if (!careAboutCheck || !underAttack(newRank, newFile, king->getWhite())) {
            moves->insert({newRank, newFile});
        }
    }

    // SW
    newFile--;
    if (!getPiece(newRank, newFile) || getPiece(newRank, newFile)->getWhite() != king->getWhite()) {
        if (!careAboutCheck || !underAttack(newRank, newFile, king->getWhite())) {
            moves->insert({newRank, newFile});
        }
    }

    // W
    newRank++;
    if (!getPiece(newRank, newFile) || getPiece(newRank, newFile)->getWhite() != king->getWhite()) {
        if (!careAboutCheck || !underAttack(newRank, newFile, king->getWhite())) {
            moves->insert({newRank, newFile});
        }
    }

    // NW
    newRank++;
    if (!getPiece(newRank, newFile) || getPiece(newRank, newFile)->getWhite() != king->getWhite()) {
        if (!careAboutCheck || !underAttack(newRank, newFile, king->getWhite())) {
            moves->insert({newRank, newFile});
        }
    }

    // NE
    newFile = newFile + 2;
    if (!getPiece(newRank, newFile) || getPiece(newRank, newFile)->getWhite() != king->getWhite()) {
        if (!careAboutCheck || !underAttack(newRank, newFile, king->getWhite())) {
            moves->insert({newRank, newFile});
        }
    }

    // E
    newRank--;
    if (!getPiece(newRank, newFile) || getPiece(newRank, newFile)->getWhite() != king->getWhite()) {
        if (!careAboutCheck || !underAttack(newRank, newFile, king->getWhite())) {
            moves->insert({newRank, newFile});
        }
    }

    // SE
    newRank--;
    if (!getPiece(newRank, newFile) || getPiece(newRank, newFile)->getWhite() != king->getWhite()) {
        if (!careAboutCheck || !underAttack(newRank, newFile, king->getWhite())) {
            moves->insert({newRank, newFile});
        }
    }
}

bool Board::underAttack(int rank, int file, bool isKingWhite) {
    move_list* moves = new move_list;
    Piece* curr_piece;
    for (int r = 0; r < 8; r++) {
        for (int f = 0; f < 8; f++) {
            curr_piece = board[r][f].getPiece();
            if (curr_piece && curr_piece->getWhite() != isKingWhite) {
                getMoves(curr_piece, moves, false, true);
                if (moves->find({rank, file}) != moves->end()) {
                    return true;
                }
                moves->clear();
            }
        }
    }
    return false;
}
