#include <utility>

#include "../include/Piece.h"

Piece::Piece() : color(' '), PieceCords({0, 0}), chess(nullptr) {}
std::pair<int, int> Piece::PiecePlace() const {
    return PieceCords;
}

Piece& Piece::operator=(const Piece& rhs) {
    if (this != &rhs) {
        color = rhs.color;
        PieceCords = rhs.PieceCords;
        chess = rhs.chess;

    }
    return *this;
}

Piece::Piece(char color, std::pair<int, int> Cord, Chess* chess)
        : color(color), PieceCords(std::move(Cord)), chess(chess) {
}
