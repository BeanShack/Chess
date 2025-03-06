#include "Board.h"
#include <iomanip>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <vector>

#include "Piece.h"
#include <unordered_set>

vector<Piece*> Board::whitePieces;
vector<Piece*> Board::blackPieces;
Square* Board::squares[8][8];

void Board::setBoard(){
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            char colLetter = 'A' + (col);
            //cout << (colLetter) << " " << to_string(row+1) << endl;
            squares[row][col] = new Square((row + 1), colLetter);
        }
    }
}

Square* Board::getSquare(char col, int row) {
    int colIndex = col-97;
    //cout << to_string(colIndex) << "/" << col << " " << to_string(row) << endl;
    row = row - 1;

    if (colIndex < 0 || colIndex >= 8 || row < 0 || row >= 8) {
        //cout << "ERROR: Out of bounds access in getSquare! col " << colIndex << " row " << row <<  endl;
        return nullptr;
    }

    return squares[row][colIndex];
}

void Board::destroy() {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            delete squares[row][col];  // Free the memory allocated for each Square
        }
    }
}

void Board::printBoard() {
    cout << "   a   b   c   d   e   f   g   h" << endl; // Column labels
    cout << "  +---+---+---+---+---+---+---+---+" << endl;

    for (int row = 7; row >= 0; row--) {  // Print from row 8 to 1 (Chess board standard)
        cout << row + 1 << " |";  // Row label

        for (int col = 0; col < 8; col++) {
            char pieceSymbol = ' '; // Default to empty space
            if (squares[row][col]->getPiece() != nullptr) {
                pieceSymbol = squares[row][col]->getPiece()->getName()[0];
                if (squares[row][col]->getPiece()->getColor() == 'b') {
                   pieceSymbol = std::tolower(pieceSymbol);
                }
            }

            cout << " " << pieceSymbol << " |";
        }

        cout << " " << row + 1 << endl; // Right-side row label
        cout << "  +---+---+---+---+---+---+---+---+" << endl;
    }

    cout << "   a   b   c   d   e   f   g   h" << endl; // Column labels
}

/*
void Board::fillAttacked() {

    unordered_set<Square*> attackedSquaresBlack;
    unordered_set<Square*> attackedSquaresWhite;
    for (Piece* p: Board::whitePieces){
        if (p == nullptr) {continue;}
        vector<Square*> possibleSquares = p->getPossibleSquares();
        attackedSquaresWhite.insert(possibleSquares.begin(), possibleSquares.end());
    }

    for (Piece* p: Board::blackPieces){
        if (p == nullptr) {continue;}
        vector<Square*> possibleSquares = p->getPossibleSquares();
        attackedSquaresBlack.insert(possibleSquares.begin(), possibleSquares.end());
    }

    for (Square* s: attackedSquaresWhite){
        s->setAttacked('w', true);
    }

    for (Square* s: attackedSquaresBlack){
        s->setAttacked('b', true);
    }

    std::vector<Square*> whiteNotAttacked;
    std::vector<Square*> blackNotAttacked;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Square* sq = Board::squares[i][j];
            if (attackedSquaresWhite.find(sq) == attackedSquaresWhite.end()) {
                sq->setAttacked('w', false);
            }
            if (attackedSquaresBlack.find(sq) == attackedSquaresBlack.end()) {
                sq->setAttacked('b', false);
            }
        }
    }


}
 */