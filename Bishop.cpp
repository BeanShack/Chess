#include "Bishop.h"
#include "Board.h"
#include <vector>

Bishop::Bishop(char col, int row, char color) : Piece(col, row, color) {
    this->name = "Bishop";
}

void Bishop::fillPossibleSquares() {
    std::cout << "Bishop::fillPossibleSquares" << std::endl;
    this->possibleSquares.clear();  // Reset vector before populating

    int directions[4][2] = {
        {1, 1},   // up right
        {1, -1},  // down right
        {-1, 1},   // up left
        {-1, -1}   // down left
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

std::vector<Square*> Bishop::getPossibleSquares() {
    this->fillPossibleSquares();
    return this->possibleSquares;  // Return vector
}

