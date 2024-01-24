#include <string>

#include "queen.h"

Queen::Queen(bool white) {
    isWhite = white;
}

string Queen::getString() {
    return "Q";
}

PieceType Queen::getType() {
    return QUEEN;
}