///////////////////////////////////////////////////////////////////////////////////////////////////////
// Jeu d'echecs                                                                                      //																						 //
// Fichier: Main.cpp                                                                                 //
// Auteurs: Bouka Christ (2138567)                      											 //
// Date:  20 Avril 2023																			     //
///////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Piece.hpp"

class Queen : public Piece {
public:
	Queen(PieceType::Type t, PieceColor::Color p);

	virtual std::vector<Position> getPossibleMove(const Position& p, const std::array<std::array<int, SIZE_BOARD>, SIZE_BOARD>& board) override;
};