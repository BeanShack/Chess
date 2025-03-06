#include <iostream>

#include "Board.h"
#include "Knight.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include <unordered_set>

using namespace std;

int main() {
    Board::setBoard();
    // Piece* p = new Pawn('e', 2, 'w');

    for (int x = 0; x < 8; x++) {
        new Pawn('a' + x, 2, 'w');
        new Pawn('a' + x, 7, 'b');
    }

    new Knight('b', 1, 'w');
    new Rook('a', 1, 'w');
    new Rook('b', 3, 'w');
    new Bishop('g', 1, 'w');
    new Bishop('g', 8, 'b');
    new Queen('d', 1, 'w');
    new Rook('f', 1, 'b');
    King* whiteKing = new King('e', 1, 'w');
    King* blackKing = new King('e', 8, 'b');


    string firstPos;
    string secondPos;

    //Board::getSquare('a', 2)->getPiece()->print();

    string turn = "White";
    while (true) {
        Board::printBoard();


        cout << turn << " please input your move in the format 'moving_piece_position moving_to'. For example (e2 e4): ";
        cin >> firstPos;

        if (firstPos == "exit") {
            break;
        }
        cin >> secondPos;

        cout << firstPos << " " << secondPos << endl;

        cout << firstPos[0] << " " << firstPos[1] - '0' << endl;

        try {
            if (firstPos.empty() or secondPos.empty() or firstPos == secondPos) {
                throw runtime_error("not proper coords");
            }
            Square* square = Board::getSquare(firstPos[0], firstPos[1] - '0');
            if (square == nullptr) {
                throw runtime_error("Square is out of bounds");
            }
            Piece* movingPiece = square->getPiece();
            if (movingPiece == nullptr) {
                throw runtime_error("no piece there");
            }
            movingPiece->print();
            if (movingPiece->getColor() != tolower(turn[0])) {
                throw runtime_error("not your turn");
            }

            movingPiece->move(secondPos[0], secondPos[1] - '0');


            if (whiteKing->isCheckmated()){
                cout << "White is checkmated" << endl;
                break;
            }

            if (blackKing->isCheckmated()){
                cout << "Black is checkmated" << endl;
                break;
            }


            if (turn == "White") {
                turn = "Black";
            } else {
                turn = "White";
            }
        } catch (const exception& e){
            cout << e.what() << ", try again" << endl;
        }
    }


    Board::destroy();
}
