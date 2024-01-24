#ifndef PIECE_H
#define PIECE_H

#include <vector>

#include <string>

using namespace std;

enum PieceType {
    KING,
    QUEEN,
    ROOK,
    BISHOP,
    KNIGHT,
    PAWN
};

class Piece {
    public:
        virtual string getString() = 0;
        void setRank(int r);
        void setFile(int f);
        virtual PieceType getType() = 0;

    protected:
        bool isWhite;
        int rank;
        int file;
};

#endif