#include "../include/Knight.h"

using namespace std;
Knight::Knight(char color,std::pair<int,int> Cord,Chess * chessObj) : Piece(color, Cord,chessObj) {
    this->color=color;
    this->PieceCords=Cord;
}
std::pair<int, int> Knight::PiecePlace() const {
    return Piece::PiecePlace();
}
std::vector<std::pair<int, int>> Knight::PieceMoves() const {
    int RightMaxColLim = 17;
    int LeftMaxColLim = 3;
    int maxRow = 17 ;
    int minRow = 3;
    std::vector<std::pair<int,int>> Moves;
    int knightCordRow = this->PieceCords.first;
    int knightCordCol = this->PieceCords.second;
    if (knightCordRow+2 <= maxRow)
    {
        if (knightCordCol+4 <= RightMaxColLim){Moves.emplace_back(knightCordRow+4,knightCordCol+2);}
        if (knightCordCol-4 >= LeftMaxColLim){Moves.emplace_back(knightCordRow+4,knightCordCol-2);}
    }
    if (knightCordRow-4 >= minRow)
    {
        if (knightCordCol+2 <= RightMaxColLim){Moves.emplace_back(knightCordRow-4,knightCordCol+2);}
        if (knightCordCol-2 >= LeftMaxColLim){Moves.emplace_back(knightCordRow-4,knightCordCol-2);}
    }
    if (knightCordCol+4 <= RightMaxColLim )
    {
        if (knightCordRow+2 <= maxRow){Moves.emplace_back(knightCordRow+2,knightCordCol+4);}
        if (knightCordRow-2 >= minRow){Moves.emplace_back(knightCordRow-2,knightCordCol+4);}
    }
    if (knightCordCol-4 >= LeftMaxColLim)
    {
        if (knightCordRow+2 <= maxRow){Moves.emplace_back(knightCordRow+2,knightCordCol-4);}
        if (knightCordRow-2 <= maxRow){Moves.emplace_back(knightCordRow-2,knightCordCol-4);}
    }
    return Moves;}

Piece &Knight::operator=(const Piece &rhs) {
    if (this != &rhs) {
        Piece::operator=(rhs);
    }
    return *this;}

void Knight::SetPiecePlace(std::pair<int, int> newCords) {

    this->PieceCords.first = newCords.first;
    this->PieceCords.second = newCords.second;
}

char Knight::getType() {
    if (this->color == 'w')
        return 'N';
    return 'n';
}


Knight::Knight()=default;

