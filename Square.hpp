///////////////////////////////////////////////////////////////////////////////////////////////////////
// Jeu d'echecs                                                                                      //																						 //
// Fichier: Main.cpp                                                                                 //
// Auteurs: Bouka Christ (2138567)                      											 //
// Date:  20 Avril 2023																			     //
///////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <QPushButton>
#include "Position.hpp"
#include "Piece.hpp"

class Square : public QPushButton {

	Q_OBJECT

public:
	Square(QColor c, Position& pos, QWidget* parent);

	void setIconSquare(QString path);
	void setIconSquare(QIcon icon);
	void addPiece(std::unique_ptr<Piece> p);
	std::unique_ptr<Piece> removePiece();
	Piece* getPiece() const;
	Position getPosition() const;

private:
	QColor c;
	Position position;
	std::unique_ptr<Piece> piece;
};