#include <iostream>
#include <vector>

#include "bishop.h"
#include "king.h"
#include "knight.h"
#include "pawn.h"
#include "rook.h"
#include "space.h"
#include "queen.h"

using namespace std;

class Board {
    public:
        Board();
        vector< vector<Space> > board;
        King kw;
        King kb;
        Queen qw;
        Queen qb;
        vector<Rook> rw;
        vector<Rook> rb;
        vector<Bishop> bw;
        vector<Bishop> bb;
        vector<Knight> nw;
        vector<Knight> nb;
        vector<Pawn> pw;
        vector<Pawn> pb;
};

int main();