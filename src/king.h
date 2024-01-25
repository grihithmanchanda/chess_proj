#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece {
    public:
        King(bool white);
        string getString();
        PieceType getType();

    private: 
        bool hasMoved;
};

#endif