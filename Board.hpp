///////////////////////////////////////////////////////////////////////////////////////////////////////
// Jeu d'echecs                                                                                      //																						 //
// Fichier: Main.cpp                                                                                 //
// Auteurs: Bouka Christ (2138567)																	 //
// Date:  20 Avril 2023																			     //
///////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Square.hpp"
#include "Piece.hpp"
#include <array>
#include <QWidget>
#include <QGridLayout>


using CapturedPieceVectorMap = std::unordered_map<PieceType::Type, std::vector<Piece*>>;

using RandomPieceInfos = std::unordered_multimap<PieceType::Type, std::pair<PieceColor::Color, Position>>;
//Quesrion 1 TD6

// l'echiquier implemente deja le principe de RAII car lorsqu'un deplacement est fait la piece est supprimer de l'endroit ou elle se trouve
class Board : public QWidget {
	Q_OBJECT

public:
	Board(QWidget* parent = nullptr);

	void move(const Position& from, const Position& to);

	QGridLayout* initParty1();
	QGridLayout* initParty2();

	template <typename T>
	void addPieceToSquare(std::unique_ptr<T> piece, const Position& pos, QIcon icon);

	Piece* getPiece(Position& from);
	bool checkPromotion(Position* piece);

	std::array<std::array<int, SIZE_BOARD>, SIZE_BOARD> getSimpleBoard();

	bool isKingInCheck(PieceColor::Color);
	bool isCheckMate();

	void setChessGrid(QGridLayout* grid);
	void resetBoard();

	bool isSquareClicked() const;
	void changeCurrentPlayer();
	PieceColor::Color getCurrentPlayer() const;
	QGridLayout* loadPiece();

	PieceColor::Color isSquareOccupied(const Square* square) const;

	void addCapturedPiece(Piece* p);
	std::array<int, 5> getCapturedPieceVector(PieceColor::Color player) const;
public slots:
	void squareClicked(Square* square);


private:
	void clear();
	void showClickedAndMove();
	Position finKingPosition(PieceColor::Color player) const;
	std::vector<Position> validMovesOnBoard(std::vector<Position> possiblesMoves, Square* clickedSquare);
	std::vector<Position> validMovesOnBoardWithKing(std::vector<Position> possibles, Square* clickedSquare);
	bool canAttackKing(PieceColor::Color player, Position& kingPos);
	void managePlayerTurn(Square* clickedSquare);
	bool isCurrentPlayerCastling(const Position& to);

	std::array<std::array<std::unique_ptr<Square>, SIZE_BOARD>, SIZE_BOARD> board;

	std::array<int, 5> capturedWhitePiece = {};
	std::array<int, 5> capturedBlackPiece = {};

	QGridLayout* loadPieceAtPositions(RandomPieceInfos posVector);

	QGridLayout* gridLayout;
	Position selectedPieceOriginalPosition;
	Square* selectedPiece;
	bool isClicked = false;
	bool isWhitePlayer = true;
	PieceColor::Color currentPlayer;

	bool canRoc;
};