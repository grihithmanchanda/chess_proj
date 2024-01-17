#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece {
    public:
        Rook(bool white);
        string getString();
        vector< vector<int> > getMoves();
};

#endif