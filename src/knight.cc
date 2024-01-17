#include <string>

#include "knight.h"

Knight::Knight(bool white) {
    isWhite = white;
}

string Knight::getString() {
    return "N";
}

// vector< vector<int> > Knight::getMoves(Board board) {
//     vector< vector<int> > moves;
//     for (auto offset : Knight::moveOffsets) {
//         int newRank = rank + offset[0];
//         int newFile = file + offset[1];
//         if (newRank >= 0 && newRank < 8) {
//             if (newFile >0 && newFile < 8) {
//                 if (board.isSpaceEmpty(newRank, newFile)) {
//                     moves.push_back({newRank, newFile});
//                 }
//             }
//         }
//     }
// }