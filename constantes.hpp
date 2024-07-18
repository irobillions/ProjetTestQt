///////////////////////////////////////////////////////////////////////////////////////////////////////
// Jeu d'echecs                                                                                      //																						 //
// Fichier: Main.cpp                                                                                 //
// Auteurs: Bouka Christ (2138567) 											                         //
// Date:  20 Avril 2023																			     //
///////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <QObject>
#include "Position.hpp"

const int SIZE_BOARD = 8;

//namespace pour les vecteurs directions
namespace VectorDir {
	struct Direction {
		int x;
		int y;
	};
}
// enum pour les couleurs possibles dans l'echiquier

//namesoace pour les couleur des pieces
namespace PieceColor {
	enum Color {
		WHITE,
		BLACK,
		EMPTY
	};
}

//namespace pour les types de Piece
// enum pour les types possibles de pions
namespace PieceType {
	enum Type {
		PAWN,
		BISHOP,
		KNIGHT,
		QUEEN,
		ROOK,
		KING,
	};
}

//Structure d'objets representants les vecteurs de directions possibles dans l'echiquier
//struct Direction {
//	int x;
//	int y;
//};

//tableau d'une representation simple d'un plateau d'echecs avec des caracteres
const QVector<QString> INITIAL_POSITION = {
	"R", "N", "B", "Q", "K", "B", "N", "R",
	"P", "P", "P", "P", "P", "P", "P", "P",
	"",  "",  "",  "",  "",  "",  "",  "",
	"",  "",  "",  "",  "",  "",  "",  "",
	"",  "",  "",  "",  "",  "",  "",  "",
	"",  "",  "",  "",  "",  "",  "",  "",
	"p", "p", "p", "p", "p", "p", "p", "p",
	"r", "n", "b", "q", "k", "b", "n", "r"
};



//structure qui renseigne sur les informations d'une piece
struct PieceInfos {
	PieceType::Type t;
	QString path;
};

const QString wPawn = "images/wPawn.png";
const QString bPawn = "images/bPawn.png";

const QString wQueen = "images/wQueen.png";
const QString wBishop = "images/wBishop.png";
const QString wKnight = "images/wKnight.png";
const QString wRook = "images/wRook.png";
const QString wKing = "images/wKing.png";

const QString bQueen = "images/bQueen.png";
const QString bBishop = "images/bBishop.png";
const QString bKnight = "images/bKnight.png";
const QString bRook = "images/bRook.png";
const QString bKing = "images/bKing.png";


static const std::unordered_multimap<PieceType::Type, std::pair<PieceColor::Color, Position>> vectorGame1 = {

	{PieceType::KNIGHT, std::pair<PieceColor::Color, Position>(PieceColor::BLACK, {4, 0})},
	{PieceType::KING, std::pair<PieceColor::Color, Position>(PieceColor::BLACK, {0, 0})},
	{PieceType::QUEEN, std::pair<PieceColor::Color, Position>(PieceColor::WHITE, {1, 2})},
	{PieceType::KING, std::pair<PieceColor::Color, Position>(PieceColor::WHITE, {3, 3})},
	{PieceType::BISHOP, std::pair<PieceColor::Color, Position>(PieceColor::BLACK, {6, 3})},
	{PieceType::PAWN, std::pair<PieceColor::Color, Position>(PieceColor::BLACK, {1, 3})},
	{PieceType::PAWN, std::pair<PieceColor::Color, Position>(PieceColor::WHITE, {4, 2})}
};


static const std::unordered_multimap<PieceType::Type, std::pair<PieceColor::Color, Position>> vectorGame2 = {
	{PieceType::KING, std::pair<PieceColor::Color, Position>(PieceColor::BLACK, {3, 2})},
	{PieceType::QUEEN, std::pair<PieceColor::Color, Position>(PieceColor::BLACK, {4, 1})},
	{PieceType::QUEEN, std::pair<PieceColor::Color, Position>(PieceColor::WHITE, {2, 5})},
	{PieceType::KING, std::pair<PieceColor::Color, Position>(PieceColor::WHITE, {3, 5})},
	{PieceType::BISHOP, std::pair<PieceColor::Color, Position>(PieceColor::BLACK, {6, 3})},
	{PieceType::PAWN, std::pair<PieceColor::Color, Position>(PieceColor::WHITE, {4, 5})}
};

//
//static const std::unordered_multimap<PieceType::Type, std::pair<PieceColor::Color, Position>> vectorGame3 = {
//	{PieceType::KING, std::pair<PieceColor::Color, Position>(PieceColor::BLACK, {3, 2})},
//	{PieceType::QUEEN, std::pair<PieceColor::Color, Position>(PieceColor::BLACK, {4, 1})},
//	{PieceType::QUEEN, std::pair<PieceColor::Color, Position>(PieceColor::WHITE, {2, 5})},
//	{PieceType::KING, std::pair<PieceColor::Color, Position>(PieceColor::WHITE, {3, 5})},
//	{PieceType::KING, std::pair<PieceColor::Color, Position>(PieceColor::BLACK, {3, 2})},
//	{PieceType::QUEEN, std::pair<PieceColor::Color, Position>(PieceColor::BLACK, {4, 1})},
//	{PieceType::QUEEN, std::pair<PieceColor::Color, Position>(PieceColor::WHITE, {2, 5})},
//	{PieceType::KING, std::pair<PieceColor::Color, Position>(PieceColor::WHITE, {3, 5})},
//	{PieceType::BISHOP, std::pair<PieceColor::Color, Position>(PieceColor::BLACK, {6, 3})},
//	{PieceType::PAWN, std::pair<PieceColor::Color, Position>(PieceColor::WHITE, {4, 5})}
//};