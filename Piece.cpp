#include "Piece.hpp"
#include "cppitertools/range.hpp"



const VectorDir::Direction Piece::up = { 0, -1 };
const VectorDir::Direction Piece::diagonalUpLeft = { -1, -1 };
const VectorDir::Direction Piece::diagonalUpRight = { 1, -1 };
const VectorDir::Direction Piece::diagonalDownLeft = { -1, 1 };
const VectorDir::Direction Piece::diagonalDownRight = { 1, 1 };
const VectorDir::Direction Piece::down = { 0, 1 };
const VectorDir::Direction Piece::left = { -1, 0 };
const VectorDir::Direction Piece::right = { 1, 0 };


PieceType::Type Piece::getPtype() const {
    return pType;
}

bool Piece::validPositionForMove(Position& p) {
    return p.y >= 0 && p.y < SIZE_BOARD && p.x >= 0 && p.x < SIZE_BOARD;
}
std::string Piece::toString() const {


    if (pType == PieceType::PAWN) {

        return "PAWN";

    }
    else if (pType == PieceType::KNIGHT) {
        return "KNIGHT";
    }
    else if (pType == PieceType::QUEEN) {
        return "QUEEN";
    }
    else if (pType == PieceType::ROOK) {
        return "ROOK";
    }
    else if (pType == PieceType::BISHOP) {
        return "BISHOP";
    }
    else
        return "KING";
}

PieceColor::Color Piece::getPcolor() const {
    return pColor;
}
Piece::~Piece() {
    //echoue
}

