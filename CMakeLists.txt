cmake_minimum_required(VERSION 3.28)
project(Chess)

set(CMAKE_CXX_STANDARD 17)

add_executable(Chess
        exercise-1-chess-SalehNaamneh/Chess/src/Chess.cpp
        exercise-1-chess-SalehNaamneh/Chess/src/main.cpp
        exercise-1-chess-SalehNaamneh/Chess/src/GameLogic.cpp
        exercise-1-chess-SalehNaamneh/Chess/include/GameLogic.h
        exercise-1-chess-SalehNaamneh/Chess/src/Pawn.cpp
        exercise-1-chess-SalehNaamneh/Chess/include/Pawn.h
        exercise-1-chess-SalehNaamneh/Chess/src/Bishop.cpp
        exercise-1-chess-SalehNaamneh/Chess/include/Bishop.h
        exercise-1-chess-SalehNaamneh/Chess/src/Knight.cpp
        exercise-1-chess-SalehNaamneh/Chess/include/Knight.h
        exercise-1-chess-SalehNaamneh/Chess/src/Piece.cpp
        exercise-1-chess-SalehNaamneh/Chess/include/Piece.h
        exercise-1-chess-SalehNaamneh/Chess/src/Rock.cpp
        exercise-1-chess-SalehNaamneh/Chess/include/Rock.h
        exercise-1-chess-SalehNaamneh/Chess/src/Queen.cpp
        exercise-1-chess-SalehNaamneh/Chess/include/Queen.h
        exercise-1-chess-SalehNaamneh/Chess/src/King.cpp
        exercise-1-chess-SalehNaamneh/Chess/include/King.h
)
