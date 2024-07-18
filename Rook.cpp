#include "Rook.hpp"

Rook::Rook(PieceType::Type t, PieceColor::Color p) : Piece(t, p) {}

std::vector<Position> Rook::getPossibleMove(const Position& p, const std::array<std::array<int, SIZE_BOARD>, SIZE_BOARD>& board) {
	std::vector<Position> possibleMoves;
	Position pos;

	// up
	for (int i = 1; i < SIZE_BOARD; i++) {
		pos = { p.x + i * up.x, p.y + i * up.y };
		if (validPositionForMove(pos)) {
			possibleMoves.push_back(pos);
			if (board[pos.y][pos.x] != 0) {
				break;
			}
		}
		else {
			break;
		}
	}
	// down
	for (int i = 1; i < SIZE_BOARD; i++) {
		pos = { p.x + i * down.x, p.y + i * down.y };
		if (validPositionForMove(pos)) {
			possibleMoves.push_back(pos);
			if (board[pos.y][pos.x] != 0) {
				break;
			}
		}
		else {
			break;
		}

	}
	// left
	for (int i = 1; i < SIZE_BOARD; i++) {
		pos = { p.x + i * left.x, p.y + i * left.y };
		if (validPositionForMove(pos)) {
			possibleMoves.push_back(pos);
			if (board[pos.y][pos.x] != 0) {
				break;
			}
		}
		else {
			break;
		}
	}
	// right
	for (int i = 1; i < SIZE_BOARD; i++) {
		pos = { p.x + i * right.x, p.y + i * right.y };

		if (validPositionForMove(pos)) {
			possibleMoves.push_back(pos);
			if (board[pos.y][pos.x] != 0) {
				break;
			}
		}
		else {
			break;
		}
	}
	return possibleMoves;
}