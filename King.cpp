

#include "DoubleInstanceOfKingError.hpp"
#include "King.hpp"


King::King(PieceType::Type t, PieceColor::Color p) : Piece(t, p) {
	nInstanceOfKing_++;

	if (nInstanceOfKing_ > 2) {
		throw DoubleInstanceOfKingError("il ne peut avoir deux instance du Roi dan le jeu le dernier sera supprimer et la partie continuera");
	}
};

int King::nInstanceOfKing_ = 0;
int King::getNinstanceOfKing() { return nInstanceOfKing_; };

std::vector<Position> King::getPossibleMove(const Position& p, const std::array<std::array<int, SIZE_BOARD>, SIZE_BOARD>& board) {
	std::vector<Position> possibleMoves = {};
	Position pos;

	//up
	pos = { p.x + up.x, p.y + up.y };
	if (validPositionForMove(pos)) {
		possibleMoves.push_back(pos);
	}

	// down
	pos = { p.x + down.x, p.y + down.y };
	if (validPositionForMove(pos)) {
		possibleMoves.push_back(pos);
	}
	// left
	pos = { p.x + left.x, p.y + left.y };
	if (validPositionForMove(pos)) {
		possibleMoves.push_back(pos);
	}
	// right
	pos = { p.x + right.x, p.y + right.y };

	if (validPositionForMove(pos)) {
		possibleMoves.push_back(pos);
	}
	// diagonal up left
	pos = { p.x + diagonalUpLeft.x, p.y + diagonalUpLeft.y };
	if (validPositionForMove(pos)) {
		possibleMoves.push_back(pos);
	}
	// diagonal up right
	pos = { p.x + diagonalUpRight.x, p.y + diagonalUpRight.y };
	if (validPositionForMove(pos)) {
		possibleMoves.push_back(pos);
	}
	// diagonal down left
	pos = { p.x + diagonalDownLeft.x, p.y + diagonalDownLeft.y };
	if (validPositionForMove(pos)) {
		possibleMoves.push_back(pos);
	}
	// diagonal down right
	pos = { p.x + diagonalDownRight.x, p.y + diagonalDownRight.y };
	if (validPositionForMove(pos)) {
		possibleMoves.push_back(pos);
	}

	//rrr
	return possibleMoves;
}

King::~King() {
	--nInstanceOfKing_;
}