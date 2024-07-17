
#ifndef CHESS_ROCK_H
#define CHESS_ROCK_H
#include "Piece.h"
class Rock : public Piece{
public:
    explicit Rock(char color , std::pair<int,int> rockCord , Chess *chessObj);
    Rock();
    virtual std::pair<int, int> PiecePlace() const override;
    std::vector<std::pair<int, int>> PieceMoves() const override;
    Piece& operator=(const Piece& rhs) override;
    void SetPiecePlace(std::pair<int,int> newCords) override;
    char getType() override;

};


#endif //CHESS_ROCK_H
