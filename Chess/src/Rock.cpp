#include "../include/Rock.h"
#include "../include/Chess.h"
Rock::Rock(char color, std::pair<int, int> rockCord,Chess * chessObj) : Piece(color, rockCord,chessObj){
    this->color = color;
    this->PieceCords = rockCord;
}

Rock::Rock()=default;

std::pair<int, int> Rock::PiecePlace() const {
    return this->PieceCords;
}

Piece &Rock::operator=(const Piece &rhs){
    if (this != &rhs) {
        Piece::operator=(rhs);
    }
    return *this;
}

void Rock::SetPiecePlace(std::pair<int, int> newCords){
    this->PieceCords.first = newCords.first;
    this->PieceCords.second = newCords.second;
}

std::vector<std::pair<int, int>> Rock::PieceMoves() const {
    std::vector<std::pair<int, int>> Moves;
    int max = 17; // Assuming this is the max board boundary
    int min = 3; // Assuming this is the min board boundary

    // Moving along rows (horizontal moves)
    for (int i = 1; i < 7; i++) {
        // Move right
        int newCol = this->PieceCords.second + i * 2;
        if (newCol < max) {
            if (chess->GetPieceAt(this->PieceCords.first, newCol) == ' ') {
                Moves.emplace_back(this->PieceCords.first, newCol);
            } else {
                if (chess->GetPieceAt(this->PieceCords.first, newCol) != this->color)
                    Moves.emplace_back(this->PieceCords.first, newCol);
                break;
            }
        }

        // Move left
        newCol = this->PieceCords.second - i * 2;
        if (newCol > min) {
            if (chess->GetPieceAt(this->PieceCords.first, newCol) == ' ') {
                Moves.emplace_back(this->PieceCords.first, newCol);
            } else {
                if (chess->GetPieceAt(this->PieceCords.first, newCol) != this->color)
                    Moves.emplace_back(this->PieceCords.first, newCol);
                break;
            }
        }
    }

    // Moving along columns (vertical moves)
    for (int i = 1; i < 7; i++) {
        // Move down
        int newRow = this->PieceCords.first + i * 2;
        if (newRow < max) {
            if (chess->GetPieceAt(newRow, this->PieceCords.second) == ' ') {
                Moves.emplace_back(newRow, this->PieceCords.second);
            } else {
                if (chess->GetPieceAt(newRow, this->PieceCords.second) != this->color)
                    Moves.emplace_back(newRow, this->PieceCords.second);
                break;
            }
        }

        // Move up
        newRow = this->PieceCords.first - i * 2;
        if (newRow > min) {
            if (chess->GetPieceAt(newRow, this->PieceCords.second) == ' ') {
                Moves.emplace_back(newRow, this->PieceCords.second);
            } else {
                if (chess->GetPieceAt(newRow, this->PieceCords.second) != this->color)
                    Moves.emplace_back(newRow, this->PieceCords.second);
                break;
            }
        }
    }

    return Moves;
}

char Rock::getType() {
    if (this->color == 'w')
        return 'R';
    return 'r';
}