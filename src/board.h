#include <iostream>
#include <vector>

#include "king.h"
#include "space.h"

using namespace std;

class Board {
    public:
        Board();
        vector< vector<Space> > board;
        King kw;
        King kb;
};

int main();