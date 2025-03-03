#include "Rook.h"
#include "Board.h"
#include <vector>

Rook::Rook(char col, int row, char color) : Piece(col, row, color) {
    this->name = "Rook";
}

void Rook::fillPossibleSquares() {
    std::cout << "Rook::fillPossibleSquares" << std::endl;
    this->possibleSquares.clear();  // Reset vector before populating

    int directions[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    for (const auto& direction : directions) {
        int squareCounter = 1;

        while (Board::getSquare(this->col + direction[0] * squareCounter, this->row+ direction[1] * squareCounter) != nullptr) {
            Square* square = Board::getSquare(this->col + direction[0] * squareCounter, this->row+ direction[1] * squareCounter);
            if (square->getPiece() != nullptr) {
                if (square->getPiece()->getColor() != this->getColor()) {
                    this->possibleSquares.push_back(square);
                }
                break;
            }

            this->possibleSquares.push_back(square);
            squareCounter++;
        }
    }

}

std::vector<Square*> Rook::getPossibleSquares() {
    this->fillPossibleSquares();
    return this->possibleSquares;  // Return vector
}

