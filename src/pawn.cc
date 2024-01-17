#include <string>

#include "pawn.h"

Pawn::Pawn(bool white) {
    isWhite = white;
}

string Pawn::getString() {
    return "P";
}