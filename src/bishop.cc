#include <string>

#include "bishop.h"

Bishop::Bishop(bool white) {
    isWhite = white;
}

string Bishop::getString() {
    return "B";
}

vector< vector<int> > Bishop::getMoves() {
    vector< vector<int> > moves;
}