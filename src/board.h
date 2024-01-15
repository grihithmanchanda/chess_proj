#include <iostream>
#include <vector>

#include "king.h"
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
};

int main();