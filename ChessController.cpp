#include "ChessController.hpp"

ChessController::ChessController() : gameBoard(new Board()) {
}

void ChessController::loadPieceFromBoard(QGridLayout* grid, int partyGame) {
	switch (partyGame) {

	case 1: {
		gameBoard->setChessGrid(grid);
		grid = gameBoard->initParty1();
		break;
	}case 2: {
		gameBoard->setChessGrid(grid);
		grid = gameBoard->initParty2();
		break;
	}
	default:
		gameBoard->setChessGrid(grid);
		grid = gameBoard->loadPiece();
		break;
	}

}

void ChessController::squareIsClicked(Square* square) {
	gameBoard->squareClicked(square);
}

ChessController::~ChessController() {
	delete gameBoard;
}

PieceColor::Color ChessController::getCurrentPlayer() const {
	return gameBoard->getCurrentPlayer();
}

bool ChessController::isSquaredClicked() const {
	return gameBoard->isSquareClicked();
}

void ChessController::resetBoardGame() {
	gameBoard->resetBoard();
}

std::array<int, 5> ChessController::getCapturedPlayerPiece(PieceColor::Color p) const {
	return gameBoard->getCapturedPieceVector(p);
}