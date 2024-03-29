#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece {
    public:
        King(bool white);
        string getString();
        PieceType getType();
        bool getMoved();

    private: 
        bool hasMoved;
};

#endif