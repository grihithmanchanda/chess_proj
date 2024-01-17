#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece {
    public:
        Pawn(bool white);
        string getString();
        vector< vector<int> > getMoves();
};

#endif