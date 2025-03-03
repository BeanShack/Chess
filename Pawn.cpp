#include "Pawn.h"
#include "Board.h"
#include <vector>

Pawn::Pawn(char col, int row, char color) : Piece(col, row, color) {
    this->name = "Pawn";
}

void Pawn::fillPossibleSquares() {
    std::cout << "Pawn::fillPossibleSquares" << std::endl;
    this->possibleSquares.clear();  // Reset vector before populating

    int direction = (this->color == 'b') ? -1 : 1;
    bool canMoveTwo = ((this->row == 2 && this->color == 'w') ||
                       (this->row == 7 && this->color == 'b'));

    Square* forwardOneSquare = Board::getSquare(this->col, this->row + direction);
    std::cout << "\nforwardOneSquare" << std::endl;
    if (forwardOneSquare) forwardOneSquare->print();

    if (forwardOneSquare && forwardOneSquare->getPiece() == nullptr) {
        possibleSquares.push_back(forwardOneSquare);
        std::cout << "can move forward 1!" << std::endl;

        if (canMoveTwo) {
            Square* forwardTwoSquare = Board::getSquare(this->col, this->row + 2 * direction);
            std::cout << "\nforwardTwoSquare" << std::endl;
            if (forwardTwoSquare) forwardTwoSquare->print();

            if (forwardTwoSquare && forwardTwoSquare->getPiece() == nullptr) {
                possibleSquares.push_back(forwardTwoSquare);
                std::cout << "can move forward 2!" << std::endl;
            }
        }
    }

    // Check diagonal captures
    Square* forwardRightDiagonalSquare = Board::getSquare(this->col + 1, this->row + direction);
    Square* forwardLeftDiagonalSquare = Board::getSquare(this->col - 1, this->row + direction);

    std::cout << "\nforwardRightDiagonalSquare" << std::endl;
    if (forwardRightDiagonalSquare) forwardRightDiagonalSquare->print();
    else std::cout << "null" << std::endl;

    std::cout << "\nforwardLeftDiagonalSquare" << std::endl;
    if (forwardLeftDiagonalSquare) forwardLeftDiagonalSquare->print();
    else std::cout << "null" << std::endl;

    if (forwardRightDiagonalSquare && forwardRightDiagonalSquare->getPiece() &&
        forwardRightDiagonalSquare->getPiece()->getColor() != this->color) {
        possibleSquares.push_back(forwardRightDiagonalSquare);
        std::cout << "can move right diag!" << std::endl;
    }

    if (forwardLeftDiagonalSquare && forwardLeftDiagonalSquare->getPiece() &&
        forwardLeftDiagonalSquare->getPiece()->getColor() != this->color) {
        possibleSquares.push_back(forwardLeftDiagonalSquare);
        std::cout << "can move left diag!" << std::endl;
    }
}

std::vector<Square*> Pawn::getPossibleSquares() {
    this->fillPossibleSquares();
    return this->possibleSquares;  // Return vector
}

