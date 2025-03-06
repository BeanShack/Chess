#include "King.h"
#include "Board.h"
#include <vector>

King::King(char col, int row, char color) : Piece(col, row, color) {
    this->name = "King";
}

void King::fillPossibleSquares() {
    std::cout << "King::fillPossibleSquares" << std::endl;
    this->possibleSquares.clear();  // Reset vector before populating

    vector<Square*> checkingSquares;

    int offsets[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, 1},
            {1, 1}, {1, 0}, {1, -1}, {0, -1}
    };

    for (const auto& offset : offsets) {
        Square* square = Board::getSquare(this->col + offset[0], this->row + offset[1]);
        if (square != nullptr){
            checkingSquares.push_back(Board::getSquare(this->col + offset[0], this->row + offset[1]));
        }
    }

    char attackingColor;

    if (this->color == 'w') {
        attackingColor = 'b';
    } else {
        attackingColor = 'w';
    }


    for (Square* s: checkingSquares) {
        if (s != nullptr) {
            Piece* piece = s->getPiece();
            if (true) {
                if (piece == nullptr) {
                    possibleSquares.push_back(s);
                } else {
                    if (piece->getColor() != this->color) {
                        // NEED TO CHECK IF PIECE IS DEFENDED
                        possibleSquares.push_back(s);
                    }
                }
            }
        }
    }

}

std::vector<Square*> King::getPossibleSquares() {
    this->fillPossibleSquares();
    return this->possibleSquares;  // Return vector
}

bool King::isCheckmated() {
    cout << "King::isCheckmated" << endl;
    char attackingColor;
    if (this->color == 'w') {
        attackingColor = 'b';
    } else {
        attackingColor = 'w';
    }
    if (this->getPossibleSquares().empty()){
        return true;
    }
    return false;
}

