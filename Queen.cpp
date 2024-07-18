#include "Queen.hpp"


Queen::Queen(PieceType::Type t, PieceColor::Color p) : Piece(t, p) {};

std::vector<Position> Queen::getPossibleMove(const Position& p, const std::array<std::array<int, SIZE_BOARD>, SIZE_BOARD>& board) {
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