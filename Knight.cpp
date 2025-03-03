#include "Knight.h"
#include "Board.h"
#include <vector>

Knight::Knight(char col, int row, char color) : Piece(col, row, color) {
    this->name = "Night";
}

void Knight::fillPossibleSquares() {
    std::cout << "Knight::fillPossibleSquares" << std::endl;
    this->possibleSquares.clear();  // Reset vector before populating

    vector<Square*> checkingSquares;

    int offsets[8][2] = {
        {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
        {1, -2}, {1, 2}, {2, -1}, {2, 1}
    };

    for (const auto& offset : offsets) {
        checkingSquares.push_back(Board::getSquare(this->col + offset[0], this->row + offset[1]));
    }

    for (Square* s: checkingSquares) {
        if (s != nullptr) {
            Piece* piece = s->getPiece();
            if (piece == nullptr) {
                possibleSquares.push_back(s);
            } else {
                if (piece->getColor() != this->color) {
                    possibleSquares.push_back(s);
                }
            }
        }
    }

}

std::vector<Square*> Knight::getPossibleSquares() {
    this->fillPossibleSquares();
    return this->possibleSquares;  // Return vector
}

