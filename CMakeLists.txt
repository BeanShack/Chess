cmake_minimum_required(VERSION 3.29)
project(Chess)

set(CMAKE_CXX_STANDARD 20)

add_executable(Chess main.cpp
        Piece.h
        Board.h
        Square.h
        Pawn.h
        Pawn.cpp
        Board.cpp
        Square.cpp
        Piece.cpp
        Knight.cpp
        Knight.h
        rOOK.cpp
        Rook.h
        Bishop.cpp
        Bishop.h
        Queen.cpp
        Queen.h)
