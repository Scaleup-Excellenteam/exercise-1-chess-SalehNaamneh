#include "../include/Bishop.h"
#include <vector>
#include <utility>

using namespace std;

Bishop::Bishop()=default;

Bishop::Bishop(char color, std::pair<int, int> Cord,Chess * chessObj) : Piece(color, Cord,chessObj) {}

std::pair<int, int> Bishop::PiecePlace() const {
    return this->PieceCords;
}

std::vector<std::pair<int, int>> Bishop::PieceMoves() const {
    // This is vars for knowing were the lim of the col and the row
    int RightMaxColLim = 17;
    int LeftMaxColLim = 3;
    // vector for storing the moves of the piece
    vector<std::pair<int, int>> Moves;
        // offset to the next move
        int index = 2;
        // flags to exit if we hit all the possible moves
        bool flag = true;
        bool subFlag = true;
        bool subFlag2 = true;
        int Rrow,Rcol;
        while (flag) {
            // to get to the next position in the board
            // if it w piece we move down by adding to the row
            if (color == 'w') Rrow = this->PieceCords.first + index;
            // if it black piece we move up by decreeing for the row
            else Rrow = this->PieceCords.first - index;
            Rcol = this->PieceCords.second + index;
            // Assuming Chess::GetPieceAt is a function that returns the piece at the given coordinates
            char Rpiece = chess->GetPieceAt(Rrow, Rcol);
            if (Rpiece == ' ' && Rcol <= RightMaxColLim && subFlag) {
                Moves.emplace_back(Rrow, Rcol);
            } else {
                Moves.emplace_back(Rrow, Rcol);
                subFlag = false;
            }
            int Lcol = this->PieceCords.second - index;
            char Lpiece = chess->GetPieceAt(Rrow, Lcol);
            // if we hit an empty spot that in the move dir for the piece
            if (Lpiece == ' ' && Lcol <= LeftMaxColLim && subFlag2) {
                Moves.emplace_back(Rrow, Lcol);
                // if not also to add it and not proceed with this Path
            } else {
                Moves.emplace_back(Rrow, Lcol);
                subFlag2 = false;
            }
            index+=2;
            // if we don't have any position left to cover we exit
            if (!subFlag && !subFlag2) {
                flag = false;
            }
        }
    return Moves;
}
Piece& Bishop::operator=(const Piece& rhs) {
    if (this != &rhs) {
        Piece::operator=(rhs); // Call base class assignment operator
        this->PieceCords = rhs.PiecePlace(); // Assuming PiecePlace returns the coordinates
    }
    return *this;
}

void Bishop::SetPiecePlace(std::pair<int, int> newCords) {
    this->PieceCords.first = newCords.first;
    this->PieceCords.second = newCords.second;

}

char Bishop::getType() {
    if (this->color == 'w')
        return 'B';
    return 'b';
}
