#include <string>

#include "pawn.h"

Pawn::Pawn(bool white) {
    isWhite = white;
    hasMoved = false;
}

string Pawn::getString() {
    return "P";
}

PieceType Pawn::getType() {
    return PAWN;
}