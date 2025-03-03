#include "Piece.h"

#include "Board.h"
#include "Queen.h"

Piece::Piece(char col, int row, char color) {
    this->row = row;
    this->col = col;
    if(color == 'w' or color == 'b') {
        this->color = color;
    } else {
        throw std::invalid_argument("Invalid color");
    }
    cout << col << endl;
    cout << row << endl;
    Board::getSquare(col, row)->setPiece(this);
}

void Piece::print() const {
    if (this != nullptr){
        cout << this->getName() <<" is on square " << col << " " << std::to_string(row) << endl;
    }
}

std::vector<Square*> Piece::getPossibleSquares() {
    this->fillPossibleSquares();
    return this->possibleSquares;  // Return vector
}

void Piece::fillPossibleSquares() {}

char Piece::getColor() const {
    return this->color;
}

void Piece::move(char col, int row) {
    this->getPossibleSquares();
    cout << "COLUMN: " << col << endl;
    cout << "ROW: " << row << endl;
    Square* square = Board::getSquare(col, row);
    cout << "got square" << endl;

    bool possible = false;


    for (Square* s: this->getPossibleSquares()) {
        //s->print();
        if (s == square) {
            cout << "GOOD CAN MOVE THERE" << endl;
            possible = true;
            break;
        }
    }

    if (possible) {
        Square* currentSquare = Board::getSquare(this->col, this->row);
        currentSquare->setPiece(nullptr);
        this->col = col;
        this->row = row;
        if ((row == 8 || row == 1) && this->getName() == "Pawn") {
            cout << "PROMOTION" << endl;
            new Queen(col, row, this->getColor());
            delete(this);
        } else {
            square->setPiece(this);
        }
    } else {
        throw std::invalid_argument("Invalid position");
    }

}

string Piece::getName() const{
    return this->name;
}

Piece::~Piece() {
    cout<<"damn my piece got captured"<<endl;
}

