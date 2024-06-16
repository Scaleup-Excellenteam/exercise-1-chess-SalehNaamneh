#include "../include/Queen.h"
#include "../include/Chess.h"
Queen::Queen(char color, std::pair<int, int> QueenCord, Chess *chessObj) : Piece(color, QueenCord, chessObj) {
    this->color= color;
    this->PieceCords = QueenCord;
}
Queen::Queen() = default;
std::pair<int, int> Queen::PiecePlace() const {
    return Piece::PiecePlace();
}

std::vector<std::pair<int, int>> Queen::PieceMoves() const {
    std::vector<std::pair<int, int>> Moves;
    int max = 17; // Assuming this is the max board boundary
    int min = 3;  // Assuming this is the min board boundary

    // Directions: (rowDelta, colDelta)
    std::vector<std::pair<int, int>> directions = {
            {2, 0}, {0, 2}, {-2, 0}, {0, -2},  // Vertical and horizontal
            {2, 2}, {2, -2}, {-2, 2}, {-2, -2} // Diagonal
    };

    for (const auto& direction : directions) {
        int rowDelta = direction.first;
        int colDelta = direction.second;
        int newRow = this->PieceCords.first;
        int newCol = this->PieceCords.second;

        while (true) {
            newRow += rowDelta;
            newCol += colDelta;

            // Check if new position is within board boundaries
            if (newRow >= min && newRow < max && newCol >= min && newCol < max) {
                char pieceAtNewPos = chess->GetPieceAt(newRow, newCol);
                if (pieceAtNewPos == ' ') {
                    Moves.emplace_back(newRow, newCol);
                } else {
                    // If an opponent's piece is encountered
                    if (pieceAtNewPos != this->color) {
                        Moves.emplace_back(newRow, newCol);
                    }
                    break; // Stop in this direction
                }
            } else {
                break; // Out of board boundaries
            }
        }
    }

    return Moves;
}

Piece &Queen::operator=(const Piece &rhs) {
    if (this != &rhs) {
        Piece::operator=(rhs);
    }
    return *this;
}
void Queen::SetPiecePlace(std::pair<int, int> newCords) {
    this->PieceCords.first = newCords.first;
    this->PieceCords.second = newCords.second;
}

char Queen::getType() {
    if (this->color == 'w')
        return 'Q';
    return 'q';
}
