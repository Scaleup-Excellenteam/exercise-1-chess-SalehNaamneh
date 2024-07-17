#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H
#include "Piece.h"

class Queen : public Piece{
public:
    explicit Queen(char color, std::pair<int, int> pawnCord,Chess * chessObj);
    Queen();
    virtual std::pair<int, int> PiecePlace() const override;
    virtual std::vector<std::pair<int, int>> PieceMoves() const override;
    Piece& operator=(const Piece& rhs) override;
    void SetPiecePlace(std::pair<int,int> newCords) override;
    char getType() override;


};


#endif //CHESS_QUEEN_H
