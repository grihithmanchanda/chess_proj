#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece {
    public:
        Queen(bool white);
        string getString();
        PieceType getType();
};

#endif