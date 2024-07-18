///////////////////////////////////////////////////////////////////////////////////////////////////////
// Jeu d'echecs                                                                                      //																						 //
// Fichier: Main.cpp                                                                                 //
// Auteurs: Bouka Christ (2138567)                      											 //
// Date:  20 Avril 2023																			     //
///////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

struct Position {
	int x;
	int y;

	bool operator==(const Position& autre) {
		return y == autre.y && x == autre.x;
	}
};