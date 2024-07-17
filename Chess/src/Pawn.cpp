#include "../include/Pawn.h"
#include <vector>
#include <iostream>
#include "../include/Chess.h"
using namespace std;

Pawn::Pawn(char color, std::pair<int, int> pawnCord,Chess * chessObj) : Piece(color, pawnCord,chessObj)
{
    this->PieceCords=pawnCord;
    this->color = color;
}

Pawn::Pawn() : Piece() {}

std::pair<int, int> Pawn::PiecePlace() const {
    return PieceCords;
}

std::vector<std::pair<int, int>> Pawn::PieceMoves() const {
    vector<pair<int, int>> vec;
    pair<int, int> newCords;

    if (color == 'w') {
        // Forward movement by 1 square
        newCords.first = PieceCords.first + 2;
        newCords.second = PieceCords.second;
        vec.push_back(newCords);

        // Initial double-step forward movement
        if (PieceCords.first == 5) {
            newCords.first = PieceCords.first + 4;
            vec.push_back(newCords);
        }
        if (islower(chess->GetPieceAt(PieceCords.first+2,PieceCords.second+2)))
        {
            vec.emplace_back(PieceCords.first+2,PieceCords.second+2);
        }
        if (islower(chess->GetPieceAt(PieceCords.first+2,PieceCords.second-2)))
        {
            vec.emplace_back(PieceCords.first+2,PieceCords.second-2);
        }

    }
    else if (color == 'b') {
        // Forward movement by 1 square
        newCords.first = PieceCords.first - 2;
        newCords.second = PieceCords.second;
        vec.push_back(newCords);

        // Initial double-step forward movement
        if (PieceCords.first == 15) {
            newCords.first = PieceCords.first - 4;
            vec.push_back(newCords);
        }
        if (!islower(chess->GetPieceAt(PieceCords.first-2,PieceCords.second+2)))
        {
            vec.emplace_back(PieceCords.first-2,PieceCords.second+2);
        }
        if (!islower(chess->GetPieceAt(PieceCords.first-2,PieceCords.second-2)))
        {
            vec.emplace_back(PieceCords.first-2,PieceCords.second-2);
        }
    }

    return vec;
}

Piece& Pawn::operator=(const Piece& rhs) {
    if (this != &rhs) {
        Piece::operator=(rhs); // Call base class assignment operator
    }
    return *this;
}


void Pawn::SetPiecePlace(std::pair<int, int> newCords) {
    this->PieceCords.first = newCords.first;
    this->PieceCords.second = newCords.second;
}

bool Pawn::TouchTheLine() {
    if (color == 'w' )
        return PieceCords.first == 17;
    return PieceCords.first == 3;
}

char Pawn::getType() {
    if (this->color == 'w')
        return 'p';
    return 'P';
}


