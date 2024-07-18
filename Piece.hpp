
///////////////////////////////////////////////////////////////////////////////////////////////////////
// Jeu d'echecs                                                                                      //																						 //
// Fichier: Main.cpp                                                                                 //
// Auteurs: Bouka Christ (2138567)											                         //
// Date:  20 Avril 2023																			     //
///////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once


#include "Position.hpp"
#include "constantes.hpp"
#include <vector>
//using Direction;
class Piece {

public:
	Piece(PieceType::Type t, PieceColor::Color p) : pType(t), pColor(p) {};

	virtual std::vector<Position> getPossibleMove(const Position& p, const std::array<std::array<int, SIZE_BOARD>, SIZE_BOARD>& board) = 0;

	std::string toString() const;

	PieceType::Type getPtype() const;
	PieceColor::Color getPcolor() const;
	virtual ~Piece();

protected:
	static bool validPositionForMove(Position& p);
	static const VectorDir::Direction up;
	static const VectorDir::Direction diagonalUpLeft;
	static const VectorDir::Direction diagonalUpRight;
	static const VectorDir::Direction diagonalDownLeft;
	static const VectorDir::Direction diagonalDownRight;
	static const VectorDir::Direction down;
	static const VectorDir::Direction left;
	static const VectorDir::Direction right;
private:
	PieceType::Type pType;
	PieceColor::Color pColor;
	std::unordered_map < std::string, VectorDir::Direction> direction;
};


