#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include "Piece.h"
#include <vector>
#include <utility>

class Pawn : public Piece {
public:
    explicit Pawn(char color, std::pair<int, int> pawnCord,Chess * chessObj);
    Pawn();
    virtual std::pair<int, int> PiecePlace() const override;
    virtual std::vector<std::pair<int, int>> PieceMoves() const override;
    Piece& operator=(const Piece& rhs) override;
    void SetPiecePlace(std::pair<int,int> newCords) override;
    bool TouchTheLine();
    char getType() override;

};

#endif // CHESS_PAWN_H
