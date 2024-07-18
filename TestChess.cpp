///////////////////////////////////////////////////////////////////////////////////////////////////////
// Ce programme est un mini programme d'echecs avec interface graphique realise aevc Qt et utilisant //
// les utilisant les principes de l'oriente objet                                                    //																						 //
// Fichier: TestChess.cpp																			 //
// Auteur: Bouka Christ (2138567) 											                         //
// Date:  14 Avril 2023																			     //
///////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Pawn.hpp"
#include "Square.hpp"
#include "Queen.hpp"
#include "Board.hpp"

#if __has_include("gtest/gtest.h")
#include "gtest/gtest.h"
#endif
#ifdef TEST

//
// test doivent etre reecris
//
//TEST(Pawn, getPossibleMoves) {
//	Pawn pPawn(PAWN, WHITE);
//	Position pos = { 4, 6 };
//	std::vector<Position> moves = pPawn.getPossibleMove(pos);
//	size_t taille = 4;
//	EXPECT_EQ(moves.size(), taille);
//	Position p1{ 4, 4 };
//	Position p2{ 4, 5 };
//	Position p3{ 3, 5 };
//	Position p4{ 5, 5 };
//	bool resultWanted = moves[0] == p1 && moves[1] == p2 && moves[2] == p3 && moves[3] == p4;
//	EXPECT_EQ(resultWanted, true);
//
//}
//
//TEST(Square, addPiece) {
//	Board b(nullptr);
//	QColor c = QColor(128, 128, 128);
//	Position p = { 3, 4 };
//	Square sq = Square(c, p, &b);
//	Player pl(WHITE, "hhh");
//	Pawn pW = Pawn(PAWN, &pl);
//
//	sq.addPiece(std::make_unique<Pawn>(pW));
//	bool verif = *sq.getPiece() == pW;
//	EXPECT_EQ(verif, true);
//}
//
//
//TEST(Queen, getPossibleMoves) {
//	Player p(WHITE, "hhh");
//	Queen q(QUEEN, &p);
//	Position pos = { 4, 4 };
//	std::vector<Position> moves = q.getPossibleMove(pos);
//	size_t taille = 8;
//	EXPECT_EQ(moves.size(), taille);
//	Position up{ 4, 3 };
//	Position upLeft{ 3, 3 };
//	Position left{ 3, 4 };
//	Position downLeft{ 3, 5 };
//	Position down{ 4, 5 };
//	Position downRight{ 5, 5 };
//	Position right{ 5, 4 };
//	Position upRight{ 5, 3 };
//
//	bool resultWanted = moves[0] == up && moves[1] == down && moves[2] == upLeft && moves[3] == upRight && 
//		moves[4] == downLeft && moves[5] == downRight && moves[6] == left && moves[7] == right;
//	EXPECT_EQ(resultWanted, true);
//}
#endif