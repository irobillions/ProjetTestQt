#pragma once
#include "Board.hpp"


class ChessController {

public:
	ChessController();
	void loadPieceFromBoard(QGridLayout* grid, int partyGame);

	void squareIsClicked(Square* square);
	bool isSquaredClicked() const;
	PieceColor::Color getCurrentPlayer()  const;

	std::array<int, 5> getCapturedPlayerPiece(PieceColor::Color p) const;
	void resetBoardGame();
	~ChessController();
private:
	inline static int nTours = 0;
	Board* gameBoard;
};