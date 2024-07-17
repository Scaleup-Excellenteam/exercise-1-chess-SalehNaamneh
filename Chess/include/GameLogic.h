#ifndef CHESS_GAMELOGIC_H
#define CHESS_GAMELOGIC_H

#include <string>
#include <vector>

class Bishop;
class Knight;
class Piece;
class Chess;
class GameLogic {
    std::vector<Piece*> pieces;
    void PiecesArrays();
    void PawnArrays();
    void BishopArrays();
    void KnightArrays();
    void QueenArrays();
    void RockArrays();
    void KingArrays();
    int CheckMovement(const std::vector<std::pair<int, int>>& Cords);
    Piece* SearchForPiece(std::pair<int, int> Cords);
    Chess* chess;
    void codeResponseHandel(int codeResponse,std::pair<int, int> &oldCords,std::pair<int, int> &newCords, char i);
    Piece * GetKing(char color);

public:
    GameLogic(Chess *chess);
    ~GameLogic();
    int ProcessTheInput(const std::string& m_input);
};

#endif // CHESS_GAMELOGIC_H
