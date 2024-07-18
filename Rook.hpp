///////////////////////////////////////////////////////////////////////////////////////////////////////
// Jeu d'echecs                                                                                      //																						 //
// Fichier: Main.cpp                                                                                 //
// Auteurs: Bouka Christ (2138567)                           										 //
// Date:  20 Avril 2023																			     //
///////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#include "Piece.hpp"
#include "Position.hpp"

class Rook : public Piece {
public:
	Rook(PieceType::Type t, PieceColor::Color p);

	virtual std::vector<Position> getPossibleMove(const Position& p, const std::array<std::array<int, SIZE_BOARD>, SIZE_BOARD>& board) override;
	void hasMoved() {
		isFirstMove = false;
	}
	bool getIsFirstMove() const {
		return isFirstMove;
	}
private:
	bool isFirstMove = true;
};