#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece {
    public:
        Knight(bool white);
        string getString();
        PieceType getType();

    private:
        static vector< vector<int> > moveOffsets;
};

#endif