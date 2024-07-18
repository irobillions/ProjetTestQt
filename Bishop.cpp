#include "Bishop.hpp"

Bishop::Bishop(PieceType::Type t, PieceColor::Color p) : Piece(t, p) {}

std::vector<Position> Bishop::getPossibleMove(const Position& p, const std::array<std::array<int, SIZE_BOARD>, SIZE_BOARD>& board) {
	std::vector<Position> possibleMoves;
	Position pos;

	// diagonal up left
	for (int i = 1; i < SIZE_BOARD; i++) {
		pos = { p.x + i * diagonalUpLeft.x, p.y + i * diagonalUpLeft.y };
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
	// diagonal up right
	for (int i = 1; i < SIZE_BOARD; i++) {
		pos = { p.x + i * diagonalUpRight.x, p.y + i * diagonalUpRight.y };
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
	// diagonal down left
	for (int i = 1; i < SIZE_BOARD; i++) {
		pos = { p.x + i * diagonalDownLeft.x, p.y + i * diagonalDownLeft.y };
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
	// diagonal down right
	for (int i = 1; i < SIZE_BOARD; i++) {
		pos = { p.x + i * diagonalDownRight.x, p.y + i * diagonalDownRight.y };
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