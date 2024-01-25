#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece {
    public:
        Pawn(bool white);
        string getString();
        PieceType getType();

    private: 
        bool hasMoved;
};

#endif