#pragma once
#include <QMainWindow>
#include <QVBoxLayout>
#include <QWidget>
#include "constantes.hpp"
#include "Square.hpp"
#include "ChessController.hpp"

class ChessGUI : public QWidget {
	Q_OBJECT
public:

	ChessGUI(QWidget* parent = nullptr);
	void setUI();
	QGridLayout* drawBoard();
	void loadPiece(int n);
	void initChessBoardUI(int n);
	void resetGame(int n);
	void removeLayout();

public slots:
	void squareClicked(Square* square);
private:
	void updateCapturedWhitePieceTable(std::array<int, 5> captured);
	void updateCapturedBlackPieceTable(std::array<int, 5> captured);
	QVBoxLayout* verticalLayout;
	ChessController chessController;
	Position selectedPieceOriginalPosition;
	Square* selectedSquare;
	bool isClicked = false;
	bool isWhitePlayer = true;
};