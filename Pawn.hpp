
///////////////////////////////////////////////////////////////////////////////////////////////////////
// Jeu d'echecs                                                                                      //																						 //
// Fichier: Main.cpp                                                                                 //
// Auteurs: Bouka Christ (2138567)                      											 //
// Date:  20 Avril 2023																			     //
///////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Piece.hpp"

class Pawn : public Piece {

public:
	Pawn(PieceType::Type t, PieceColor::Color p);

	virtual std::vector<Position> getPossibleMove(const Position& p, const std::array<std::array<int, SIZE_BOARD>, SIZE_BOARD>& board) override;
	void hasMoved() {
		isFirstMove = false;
	}
	bool getIsFirstMove() const {
		return isFirstMove;
	}
private:
	bool isFirstMove = true;
	bool byPass = false;
	bool bePromoted = false;
};