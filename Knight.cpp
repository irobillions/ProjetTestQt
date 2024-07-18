#include "Knight.hpp"



Knight::Knight(PieceType::Type t, PieceColor::Color p) : Piece(t, p) {};

std::vector<Position> Knight::getPossibleMove(const Position& p, const std::array<std::array<int, SIZE_BOARD>, SIZE_BOARD>& board) {
	std::vector<Position> possibleMoves;
	Position pos;
	int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	for (int i = 0; i < SIZE_BOARD; i++) {
		pos = { p.x + dx[i], p.y + (getPcolor() == PieceColor::WHITE ? dy[i] : -dy[i]) };
		if (validPositionForMove(pos)) {
			possibleMoves.push_back(pos);
		}
	}

	return possibleMoves;
}