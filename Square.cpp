#include "Square.h"

#include <optional>

#include "Piece.h"

Square::Square(int row, char col) {
    //cout<<col<<endl;
    //cout<<to_string(row)<<endl;
    this->col = col;
    this->row = row;
    this->piece = nullptr;
}

Square::Square() {
    cout<<"DUD SQUARE"<<endl;
    this->col = 'a';
    this->row = 1;
    this->piece = nullptr;
}

Square::~Square() {
    if (this->piece != nullptr) {
        delete(this->piece);
    }
}

Piece* Square::getPiece() {
    return this->piece;
}

void Square::setPiece(Piece* piece) {
    cout << "COLUMN: " << this->col << endl;
    cout << "ROW: " << to_string(this->row) << endl;
    cout << "SETTING PIECE ON SQUARE " << (this->col) << " " + to_string(this->row) << endl;

    if (this->getPiece() != nullptr && piece != nullptr) {
        cout << "CAPPED A PIECE" << endl;
        delete(this->piece);
    }

    this->piece = piece;
}

void Square::print() {
    cout << "Square " << (this->col) << " " + to_string(this->row) << endl;
}
