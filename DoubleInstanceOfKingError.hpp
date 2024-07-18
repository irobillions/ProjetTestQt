#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Jeu d'echecs                                                                                      //																						 //
// Fichier: Main.cpp                                                                                 //
// Auteurs: Bouka Christ (2138567)                      											 //
// Date:  20 Avril 2023																			     //
///////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>


class DoubleInstanceOfKingError : public std::runtime_error {

public:
	using runtime_error::runtime_error;
};