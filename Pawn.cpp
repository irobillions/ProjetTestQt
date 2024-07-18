#include "Pawn.hpp"

Pawn::Pawn(PieceType::Type t, PieceColor::Color p) : Piece(t, p) {}

std::vector<Position> Pawn::getPossibleMove(const Position& p, const std::array<std::array<int, SIZE_BOARD>, SIZE_BOARD>& board) {
    std::vector<Position> possibleMoves;
    Position pos;

    if (isFirstMove) {
        // Mouvement vers le haut 2 fois 
        pos = { p.x + 2 * (getPcolor() == PieceColor::WHITE ? up.x : -up.x), p.y + 2 * (getPcolor() == PieceColor::WHITE ? up.y : -up.y) };
        if (board[pos.y + (getPcolor() == PieceColor::WHITE ? 1 : -1)][pos.x] == 0) {
            if (validPositionForMove(pos))
                possibleMoves.push_back(pos);
        }
    }

    //haut 1 fois
    pos = { p.x + (getPcolor() == PieceColor::WHITE ? up.x : -up.x), p.y + (getPcolor() == PieceColor::WHITE ? up.y : -up.y) };
    if (validPositionForMove(pos))
        possibleMoves.push_back(pos);

    //diag haut gauche
    pos = { p.x + (getPcolor() == PieceColor::WHITE ? diagonalUpLeft.x : -diagonalUpLeft.x), p.y + (getPcolor() == PieceColor::WHITE ? diagonalUpLeft.y : -diagonalUpLeft.y) };

    if (validPositionForMove(pos))
        possibleMoves.push_back(pos);

    //diag haut droit
    pos = { p.x + (getPcolor() == PieceColor::WHITE ? diagonalUpRight.x : -diagonalUpRight.x), p.y + (getPcolor() == PieceColor::WHITE ? diagonalUpRight.y : -diagonalUpRight.y) };

    if (validPositionForMove(pos))
        possibleMoves.push_back(pos);


    return possibleMoves;
}