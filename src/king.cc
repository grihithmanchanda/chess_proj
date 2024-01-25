#include <string>

#include "king.h"

King::King(bool white) {
    isWhite = white;
    hasMoved = false;
}

string King::getString() {
    return "K";
}

PieceType King::getType() {
    return KING;
}

bool King::getMoved() {
    return hasMoved;
}
