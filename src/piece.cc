#include "piece.h"

int Piece::getRank() {
    return rank;
}

void Piece::setRank(int r) {
    rank = r;
}

int Piece::getFile() {
    return file;
}

void Piece::setFile(int f) {
    file = f;
}

bool Piece::getWhite() {
    return isWhite;
}
