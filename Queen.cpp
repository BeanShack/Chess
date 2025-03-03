#include "Queen.h"
#include "Board.h"
#include <vector>

Queen::Queen(char col, int row, char color) : Piece(col, row, color) {
    this->name = "Queen";
}

void Queen::fillPossibleSquares() {
    std::cout << "Queen::fillPossibleSquares" << std::endl;
    this->possibleSquares.clear();  // Reset vector before populating

    int directions[8][2] = {
        {1, 1},
        {1, -1},
        {-1, 1},
        {-1, -1},
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

std::vector<Square*> Queen::getPossibleSquares() {
    this->fillPossibleSquares();
    return this->possibleSquares;  // Return vector
}

