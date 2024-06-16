#include "../include/GameLogic.h"
#include "../include/Chess.h"
#include "../include/Pawn.h"
#include "../include/Knight.h"
#include "../include/Bishop.h"
#include "../include/Rock.h"
#include "../include/Queen.h"
#include "../include/King.h"
#include <sstream>
#include <string>


using namespace std;

enum behavior { Valid=41, SamePiece, MoveOutOfRange };
GameLogic::GameLogic(Chess *chess) : chess(chess)
{
    PiecesArrays();
}
void GameLogic::PiecesArrays()
{
    PawnArrays();
    BishopArrays();
    KnightArrays();
    RockArrays();
    QueenArrays();
    KingArrays();
}

int GameLogic::ProcessTheInput(const std::string& m_input)
{
    stringstream ss(m_input);
    string token;
    vector<pair<int, int>> ParsedInput;
    while (ss >> token) {
        pair<int, int> PlaceAsInteger = {0, 0};
        for (char ch : token) {
            if (isalpha(ch) && !islower(ch))
                PlaceAsInteger.first = ((ch - 'A') * 2) + 3;
            else if (isalpha(ch) && islower(ch))
                PlaceAsInteger.first = ((ch - 'a') * 2) + 3;
            else
            PlaceAsInteger.second = ((ch - '0') * 2) + 1;
        }
        ParsedInput.push_back(PlaceAsInteger);
    }

    int code =  CheckMovement(ParsedInput);
    codeResponseHandel(code, ParsedInput[0] ,ParsedInput[1], chess->GetPieceAt(ParsedInput[0].first, ParsedInput[0].second));
    return  code;
}

int GameLogic::CheckMovement(const std::vector<std::pair<int, int>>& cords)
{
    Piece* piece = SearchForPiece(cords[0]);
    Piece* target = SearchForPiece(cords[1]);

    if (piece)
    {

        if (chess->ReturnTurn() && piece->GetColor()=='b' || !chess->ReturnTurn() && piece->GetColor() =='w')
        {
            return 12;
        }
        if (target && piece->GetColor() == target->GetColor())
        {
            return 13;
        }
        vector<pair<int,int>> vec = piece->PieceMoves();
        for (auto & i : vec)
        {
            if (i.first == cords[1].first && i.second == cords[1].second)
            {
                King *WhiteKing = dynamic_cast<King *>(this->GetKing('w'));
                King *BlackKing = dynamic_cast<King *>(this->GetKing('b'));
                bool WhiteInDanger = false;
                bool BlackInDanger = false;
                chess->SetBoard(i,piece->getType());
                if (WhiteKing)
                    WhiteInDanger = WhiteKing->IsInDanger();

                if (BlackKing)
                    BlackInDanger = BlackKing->IsInDanger();

                if (WhiteInDanger && chess->ReturnTurn()) {
                    chess->SetBoard(cords[0],piece->getType());
                    chess->SetBoard(cords[1],' ');
                    return 31;
                }

                if (BlackInDanger && !chess->ReturnTurn()) {
                    chess->SetBoard(cords[0],piece->getType());
                    chess->SetBoard(cords[1],' ');

                    return 31;

                }
                if (WhiteInDanger && !chess->ReturnTurn())
                    return 41;
                if (BlackInDanger && chess->ReturnTurn())
                    return 41;
                if (target)
                {
                    target->SetIsDead(true);
                }
                return 42;
            }
        }
        return 21;
    }
    return 11;
}

Piece* GameLogic::SearchForPiece(pair<int, int> cords) {
    for (Piece* piece : pieces) {
        if (piece->PiecePlace() == cords && !piece->IsDead()) {
            return piece;
        }
    }
    return nullptr;
}



GameLogic::~GameLogic() {
    for (Piece* piece : pieces) {
        delete piece;
    }
}

void GameLogic::codeResponseHandel(int codeResponse,std::pair<int, int> &oldCords, std::pair<int, int> &newCords, char color) {
    if (codeResponse >= 41)
    {
        Piece * tmp = this->SearchForPiece(oldCords);
        if (tmp)
            tmp->SetPiecePlace(newCords);
    }
}


void GameLogic::PawnArrays() {
    for (int i = 1; i <= 8; i++) {
        pieces.push_back(new Pawn('w', {5, (i * 2) + 1},chess));
    }
    for (int i = 1; i <= 8; i++) {
        pieces.push_back(new Pawn('b', {15, (i * 2) + 1},chess));
    }
}
void GameLogic::KnightArrays() {
    pieces.push_back(new Knight('w', {3, 5},chess));
    pieces.push_back(new Knight('w', {3, 17},chess));
    pieces.push_back(new Knight('b', {17, 5},chess));
    pieces.push_back(new Knight('b', {17, 17},chess));
}

void GameLogic::BishopArrays() {
    pieces.push_back(new Bishop('w', {3, 7},chess));
    pieces.push_back(new Bishop('w', {3, 15},chess));
    pieces.push_back(new Bishop('b', {17, 7},chess));
    pieces.push_back(new Bishop('b', {17, 15},chess));
}

void GameLogic::QueenArrays()
{
    pieces.push_back(new Queen('w', {3, 9},chess));
    pieces.push_back(new Queen('b', {17, 9},chess));
}

void GameLogic::RockArrays()
{
    pieces.push_back(new Rock('w', {3, 3},chess));
    pieces.push_back(new Rock('w', {3, 17},chess));
    pieces.push_back(new Rock('b', {17, 3},chess));
    pieces.push_back(new Rock('b', {17, 17},chess));
}

void GameLogic::KingArrays() {
    pieces.push_back(new King('w', {3, 11},chess));
    pieces.push_back(new King('b', {17, 11},chess));

}

Piece *GameLogic::GetKing(char color) {
    for (Piece* piece : pieces) {
        if (color == 'w' && piece->getType() =='K')
            return piece;
        if (color == 'b' && piece->getType() =='k')
            return piece;
    }
    return nullptr;
}

