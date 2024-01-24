#include <string>

#include "king.h"

King::King(bool white) {
    isWhite = white;
}

string King::getString() {
    return "K";
}

PieceType King::getType() {
    return KING;
}