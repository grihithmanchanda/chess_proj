#include <vector>

#include "piece.h"

using namespace std;

class Board {
    public:
        Board();

    private:
        vector<vector<Piece>> board;

};