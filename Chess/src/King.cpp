
#include "../include/King.h"
#include "../include/Chess.h"

King::King(char color, std::pair<int, int> KingCord, Chess *chessObj) : Piece(color, KingCord, chessObj) {
    this->color=color;
    this->PieceCords=KingCord;
}

King::King()=default;

std::pair<int, int> King::PiecePlace() const {
    return this->PieceCords;
}

std::vector<std::pair<int, int>> King::PieceMoves() const {
    std::vector<std::pair<int, int>> Moves;
    int max = 17;
    int min = 3;
    int DownRow = PieceCords.first+2;
    int UpRow = PieceCords.first-2;
    int LeftCol = PieceCords.second-2;
    int RightCol = PieceCords.second+2;

    if (UpRow > min  && this->chess->GetPieceAt(UpRow,PieceCords.second) == ' ')
        Moves.emplace_back(UpRow,PieceCords.second);

    if ( UpRow > min  && RightCol < max && this->chess->GetPieceAt(UpRow,RightCol) == ' ')
        Moves.emplace_back(UpRow,RightCol);

    if (UpRow > min  &&  LeftCol > min &&this->chess->GetPieceAt(UpRow,LeftCol) == ' ')
        Moves.emplace_back(UpRow,LeftCol);

    if ( RightCol < max && this->chess->GetPieceAt(PieceCords.first,RightCol) == ' ')
        Moves.emplace_back(PieceCords.first,RightCol);

    if ( LeftCol > min && this->chess->GetPieceAt(PieceCords.first,LeftCol) == ' ')
        Moves.emplace_back(PieceCords.first,LeftCol);

    if (DownRow < max  && this->chess->GetPieceAt(DownRow,PieceCords.second) == ' ')
        Moves.emplace_back(DownRow,PieceCords.second);
    if ( DownRow < max  && RightCol < max && this->chess->GetPieceAt(DownRow,RightCol) == ' ')
        Moves.emplace_back(DownRow,RightCol);

    if ( DownRow < max  && LeftCol > min && this->chess->GetPieceAt(DownRow,LeftCol) == ' ')
        Moves.emplace_back(DownRow,LeftCol);

    return Moves;
}

Piece &King::operator=(const Piece &rhs) {
    if (this != &rhs) {
        Piece::operator=(rhs);
    }
    return *this;
}

void King::SetPiecePlace(std::pair<int, int> newCords) {
    this->PieceCords.first = newCords.first;
    this->PieceCords.second = newCords.second;
}

bool King::IsInDanger() {
    int max = 17;
    int min = 3;
    bool BlackWhite = (color == 'b');

    for (int i = 1; i < 7; ++i) {
        int DownRow = PieceCords.first + (i * 2);
        int UpRow = PieceCords.first - (i * 2);
        int LeftCol = PieceCords.second - (i * 2);
        int RightCol = PieceCords.second + (i * 2);

        if (DownRow < max) {
            char piece = chess->GetPieceAt(DownRow, PieceCords.second);
            if ((piece == 'R' || piece == 'Q' || piece == 'K' || piece == 'r' || piece == 'q' || piece == 'k') &&
                ((BlackWhite && (piece == 'R' || piece == 'Q' || piece == 'K')) ||
                 (!BlackWhite && (piece == 'r' || piece == 'q' || piece == 'k'))))
                return true;
        }

        if (UpRow > min) {
            char piece = chess->GetPieceAt(UpRow, PieceCords.second);
            if ((piece == 'R' || piece == 'Q' || piece == 'K' || piece == 'r' || piece == 'q' || piece == 'k') &&
                ((BlackWhite && (piece == 'R' || piece == 'Q' || piece == 'K')) ||
                 (!BlackWhite && (piece == 'r' || piece == 'q' || piece == 'k'))))
                return true;
        }

        if (LeftCol > min) {
            char piece = chess->GetPieceAt(PieceCords.first, LeftCol);
            if ((piece == 'R' || piece == 'Q' || piece == 'K' || piece == 'r' || piece == 'q' || piece == 'k') &&
                ((BlackWhite && (piece == 'R' || piece == 'Q' || piece == 'K')) ||
                 (!BlackWhite && (piece == 'r' || piece == 'q' || piece == 'k'))))
                return true;
        }

        if (RightCol < max) {
            char piece = chess->GetPieceAt(PieceCords.first, RightCol);
            if ((piece == 'R' || piece == 'Q' || piece == 'K' || piece == 'r' || piece == 'q' || piece == 'k') &&
                ((BlackWhite && (piece == 'R' || piece == 'Q' || piece == 'K')) ||
                 (!BlackWhite && (piece == 'r' || piece == 'q' || piece == 'k'))))
                return true;
        }

        if (DownRow < max && LeftCol > min) {
            char piece = chess->GetPieceAt(DownRow, LeftCol);
            if ((piece == 'B' || piece == 'Q' || piece == 'K' || piece == 'b' || piece == 'q' || piece == 'p' || piece == 'k') &&
                ((BlackWhite && (piece == 'B' || piece == 'Q' || piece == 'K')) ||
                 (!BlackWhite && (piece == 'b' || piece == 'q' || piece == 'p' || piece == 'k'))))
                return true;
        }

        if (DownRow < max && RightCol < max) {
            char piece = chess->GetPieceAt(DownRow, RightCol);
            if ((piece == 'B' || piece == 'Q' || piece == 'K' || piece == 'b' || piece == 'q' || piece == 'p' || piece == 'k') &&
                ((BlackWhite && (piece == 'B' || piece == 'Q' || piece == 'K')) ||
                 (!BlackWhite && (piece == 'b' || piece == 'q' || piece == 'p' || piece == 'k'))))
                return true;
        }

        if (UpRow > min && LeftCol > min) {
            char piece = chess->GetPieceAt(UpRow, LeftCol);
            if ((piece == 'B' || piece == 'Q' || piece == 'K' || piece == 'b' || piece == 'q' || piece == 'P' || piece == 'k') &&
                ((BlackWhite && (piece == 'B' || piece == 'Q' || piece == 'K')) ||
                 (!BlackWhite && (piece == 'b' || piece == 'q' || piece == 'P' || piece == 'k'))))
                return true;
        }

        if (UpRow > min && RightCol < max) {
            char piece = chess->GetPieceAt(UpRow, RightCol);
            if ((piece == 'B' || piece == 'Q' || piece == 'K' || piece == 'b' || piece == 'q' || piece == 'P' || piece == 'k') &&
                ((BlackWhite && (piece == 'B' || piece == 'Q' || piece == 'K')) ||
                 (!BlackWhite && (piece == 'b' || piece == 'q' || piece == 'P' || piece == 'k'))))
                return true;
        }
    }

    // Check for Knight danger
    std::vector<std::pair<int, int>> knightMoves = {
            {PieceCords.first + 2, PieceCords.second + 1},
            {PieceCords.first + 2, PieceCords.second - 1},
            {PieceCords.first - 2, PieceCords.second + 1},
            {PieceCords.first - 2, PieceCords.second - 1},
            {PieceCords.first + 1, PieceCords.second + 2},
            {PieceCords.first + 1, PieceCords.second - 2},
            {PieceCords.first - 1, PieceCords.second + 2},
            {PieceCords.first - 1, PieceCords.second - 2}
    };

    for (const auto& move : knightMoves) {
        int row = move.first;
        int col = move.second;
        if (row > min && row < max && col > min && col < max) {
            char piece = chess->GetPieceAt(row, col);
            if ((piece == 'N' && BlackWhite) || (piece == 'n' && !BlackWhite)) {
                return true;
            }
        }
    }

    return false;
}


char King::getType() {
    if (this->color == 'w')
        return 'K';
    return 'k';
}
