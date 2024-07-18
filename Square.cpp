#include "Square.hpp"
#include <iostream>

Square::Square(QColor c, Position& pos, QWidget* parent = nullptr) : QPushButton(parent), c(c), position(pos), piece(nullptr) {
	this->setStyleSheet("QPushButton { background-color:" + c.name() + "; }");
	setFixedSize(50, 50);
}

void Square::setIconSquare(QString path) {
	if (path != "") {
		QPixmap image(path);
		QIcon icon(image);
		this->setIcon(icon);
		this->setIconSize(QSize(30, 30));
	}
	else {
		this->setIcon(QIcon());
		this->setIconSize(QSize(30, 30));
	}

}

void Square::setIconSquare(QIcon icon) {
	this->setIcon(icon);
	this->setIconSize(QSize(30, 30));
}

void Square::addPiece(std::unique_ptr<Piece> p) {
	piece = std::move(p);
}
std::unique_ptr<Piece> Square::removePiece() {
	return std::move(piece);
}
Piece* Square::getPiece() const {
	return piece.get();
}
Position Square::getPosition() const {
	return position;
}