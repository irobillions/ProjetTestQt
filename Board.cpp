///////////////////////////////////////////////////////////////////////////////////////////////////////
// Ce programme est un mini programme d'echecs avec interface graphique realise aevc Qt et utilisant //
// les utilisant les principes de l'oriente objet                                                    //																						 //
// Fichier: Board.cpp																			     //
// Auteur: Bouka Christ (2138567) 											                         //
// Date:  14 Avril 2023																			     //
///////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Position.hpp"
#include "Board.hpp"
#include "Pawn.hpp"
#include "king.hpp"
#include "Queen.hpp"
#include "Bishop.hpp"
#include "Knight.hpp"
#include "Rook.hpp"
#include <QColor>
#include <iostream>
#include <QGraphicsDropShadowEffect>
#include "DoubleInstanceOfKingError.hpp"
#include <QMessageBox>

Board::Board(QWidget* parent) : QWidget(parent), currentPlayer(PieceColor::WHITE) {};

QGridLayout* Board::loadPiece() {
    for (int y = 0; y < SIZE_BOARD; ++y)
    {
        for (int x = 0; x < SIZE_BOARD; ++x)
        {
            Square* cell = qobject_cast<Square*>(gridLayout->itemAtPosition(y, x)->widget());
            QString piece = INITIAL_POSITION[y * SIZE_BOARD + x];
            board[y][x] = std::unique_ptr<Square>(cell);
            if (piece.isEmpty())
                continue;

            try {
                if (piece == "P") {
                    cell->addPiece(std::make_unique<Pawn>(PieceType::PAWN, PieceColor::BLACK));
                    cell->setIconSquare(bPawn);
                }
                else if (piece == 'R') {
                    cell->addPiece(std::make_unique<Rook>(PieceType::ROOK, PieceColor::BLACK));
                    cell->setIconSquare(bRook);
                }
                else if (piece == 'K') {
                    cell->addPiece(std::make_unique<King>(PieceType::KING, PieceColor::BLACK));
                    cell->setIconSquare(bKing);
                }
                else if (piece == 'Q') {
                    cell->addPiece(std::make_unique<Queen>(PieceType::QUEEN, PieceColor::BLACK));
                    cell->setIconSquare(bQueen);
                }
                else if (piece == 'B') {
                    cell->addPiece(std::make_unique<Bishop>(PieceType::BISHOP, PieceColor::BLACK));
                    cell->setIconSquare(bBishop);
                }
                else if (piece == 'N') {
                    cell->addPiece(std::make_unique<Knight>(PieceType::KNIGHT, PieceColor::BLACK));
                    cell->setIconSquare(bKnight);
                }
                else if (piece == 'p') {
                    cell->addPiece(std::make_unique<Pawn>(PieceType::PAWN, PieceColor::WHITE));
                    cell->setIconSquare(wPawn);
                }
                else if (piece == 'r') {
                    cell->addPiece(std::make_unique<Rook>(PieceType::ROOK, PieceColor::WHITE));
                    cell->setIconSquare(wRook);
                }
                else if (piece == 'q') {
                    cell->addPiece(std::make_unique<Queen>(PieceType::QUEEN, PieceColor::WHITE));
                    cell->setIconSquare(wQueen);
                }
                else if (piece == 'k') {
                    cell->addPiece(std::make_unique<King>(PieceType::KING, PieceColor::WHITE));
                    cell->setIconSquare(wKing);
                }
                else if (piece == 'n') {
                    cell->addPiece(std::make_unique<Knight>(PieceType::KNIGHT, PieceColor::WHITE));
                    cell->setIconSquare(wKnight);
                }
                else {
                    cell->addPiece(std::make_unique<Bishop>(PieceType::BISHOP, PieceColor::WHITE));
                    cell->setIconSquare(wBishop);
                }
            }
            catch (DoubleInstanceOfKingError& DoubleKing) {
                QMessageBox messageBox;
                messageBox.critical(0, "Erreur lorsque le roi a ete creer", DoubleKing.what());
                return {};
            }

        }
    }

    return gridLayout;
}


std::array<std::array<int, SIZE_BOARD>, SIZE_BOARD> Board::getSimpleBoard() {
    std::array<std::array<int, SIZE_BOARD>, SIZE_BOARD> tab;

    for (int y = 0; y < SIZE_BOARD; ++y) {
        for (int x = 0; x < SIZE_BOARD; ++x) {
            tab[y][x] = board[y][x]->getPiece() == nullptr ? 0 : 1;
            if (board[y][x]->getPiece() != nullptr) {
                if (board[y][x]->getPiece()->getPtype() == PieceType::ROOK) {
                    tab[y][x] = ((Rook*)board[y][x]->getPiece())->getIsFirstMove() ? 2 : 1;
                }
            }

        }
    }

    return tab;
}

void Board::clear() {
    QColor squareColor = (selectedPiece->getPosition().y + selectedPiece->getPosition().x) % 2 ? QColor(165, 103, 40) : QColor(255, 229, 204);
    selectedPiece->setStyleSheet("background-color : " + squareColor.name() + "; ");
    std::vector<Position> posMoves = selectedPiece->getPiece()->getPossibleMove(selectedPiece->getPosition(), getSimpleBoard());
    for (const Position pos : posMoves) {
        Square* p = board[pos.y][pos.x].get();
        squareColor = (pos.y + pos.x) % 2 ? QColor(165, 103, 40) : QColor(255, 229, 204);
        p->setStyleSheet("background-color : " + squareColor.name() + "; ");
    }
}

void Board::showClickedAndMove() {
    QColor transparent = QColor(203, 220, 203);
    selectedPiece->setStyleSheet("color : " + transparent.name() + "; ");
    selectedPiece->setAttribute(Qt::WA_TranslucentBackground);
    selectedPiece->setAttribute(Qt::WA_NoSystemBackground);

    std::vector<Position> valMoves = validMovesOnBoardWithKing(selectedPiece->getPiece()->getPossibleMove(selectedPiece->getPosition(), getSimpleBoard()), selectedPiece);
    for (const Position pos : valMoves) {
        Square* p = board[pos.y][pos.x].get();
        p->setStyleSheet("background-color : red; ");
    }
}

void Board::managePlayerTurn(Square* clickedSquare) {
    assert(selectedPiece != nullptr);
    std::vector<Position> posMoves = selectedPiece->getPiece()->getPossibleMove(selectedPiece->getPosition(), getSimpleBoard());
    std::vector<Position> valMoves = validMovesOnBoardWithKing(posMoves, selectedPiece);
    for (Position p : valMoves) {

        if (p == clickedSquare->getPosition()) {

            if (isCurrentPlayerCastling(p)) {
                addCapturedPiece(getPiece(p));
            }
            /*  if (selectedPiece->getPiece()->getPtype() == PieceType::KING) {
                  auto king = dynamic_cast<King*>(selectedPiece->getPiece());
                  if (king->getCanRoc()) {
                      if (clickedSquare->getPosition() == Position{ 2, 7 }) {
                          move(Position{ 0, 7 }, Position{ 3, 7 });
                      }
                  }
              }*/
            move(selectedPiece->getPosition(), p);

            changeCurrentPlayer();

            if (board[p.y][p.x]->getPiece()->getPtype() == PieceType::PAWN) {
                ((Pawn*)board[p.y][p.x]->getPiece())->hasMoved();
            }
            else if (board[p.y][p.x]->getPiece()->getPtype() == PieceType::KING) {
                ((King*)board[p.y][p.x]->getPiece())->hasMoved();
            }
            else if (board[p.y][p.x]->getPiece()->getPtype() == PieceType::ROOK) {
                ((Rook*)board[p.y][p.x]->getPiece())->hasMoved();
            }

            bool kingCheck = isKingInCheck(board[p.y][p.x]->getPiece()->getPcolor() == PieceColor::WHITE ? PieceColor::BLACK : PieceColor::WHITE);
            if (kingCheck) {
                board[finKingPosition(currentPlayer).y][finKingPosition(currentPlayer).x]->setStyleSheet("background-color : blue; ");//pourquoi le click sur la reine enleve la couleur du roi
                if (isCheckMate()) {
                    QMessageBox messageBox;
                    QString player = currentPlayer == PieceColor::BLACK ? "white" : "black";
                    QString message = "Les " + player + " gagnent";

                    messageBox.critical(0, "Echec et Mat", message);
                }
                else {
                    QMessageBox messageBox;
                    messageBox.critical(0, "Roi en echec", "deplacer le Roi pour continuer");
                }
            }

            break;
        }
    }
}

void Board::squareClicked(Square* square) {
    std::cout << "(" << square->getPosition().x << " " << square->getPosition().y << ")" << std::endl;

    //clean previoulsy selected square
    if (selectedPiece != nullptr) {
        if (selectedPiece->getPiece() != nullptr) {
            clear();
        }

    }

    isClicked = !isClicked;
    // selectionnne la piece et applique la couleur
    if (isClicked) {
        selectedPiece = square;
        if (selectedPiece->getPiece() != nullptr) {
            showClickedAndMove();
        }
        else {
            isClicked = false;
        }
    }
    else {
        managePlayerTurn(square);
    }
}
PieceColor::Color Board::isSquareOccupied(const Square* square) const {
    if (square->getPiece() != nullptr) {
        return square->getPiece()->getPcolor();
    }
    return PieceColor::EMPTY;
}

std::vector<Position> Board::validMovesOnBoard(std::vector<Position> possiblesMoves, Square* clickedSquare) {
    std::vector<Position> validesMoves;

    for (Position pos : possiblesMoves) {
        Square* targetSquare = board[pos.y][pos.x].get();
        if (isSquareOccupied(targetSquare) != clickedSquare->getPiece()->getPcolor()) {
            if (clickedSquare->getPiece()->getPtype() == PieceType::PAWN) {
                auto isDiagonal = [](Position from, Position to) { return std::abs(to.x - from.x) == std::abs(to.y - from.y); };

                if (isSquareOccupied(targetSquare) != PieceColor::EMPTY && isDiagonal(clickedSquare->getPosition(), pos)) {
                    validesMoves.push_back(pos);
                }
                if (isSquareOccupied(targetSquare) == PieceColor::EMPTY && !isDiagonal(clickedSquare->getPosition(), pos)) {
                    validesMoves.push_back(pos);
                }
            }
            else {
                validesMoves.push_back(pos);
            }
        }
    }
    return validesMoves;
}

template<typename T>
void Board::addPieceToSquare(std::unique_ptr<T> piece, const Position& pos, QIcon icon) {
    board[pos.y][pos.x]->addPiece(std::move(piece));
    board[pos.y][pos.x]->setIconSquare(icon);
}

void Board::move(const Position& from, const Position& to) {
    Square* fromSquare = qobject_cast<Square*>(gridLayout->itemAtPosition(from.y, from.x)->widget());
    Square* toSquare = qobject_cast<Square*>(gridLayout->itemAtPosition(to.y, to.x)->widget());

    toSquare->setIconSquare(fromSquare->icon());
    fromSquare->setIconSquare(QIcon());
    board[to.y][to.x]->addPiece(board[from.y][from.x]->removePiece());//suppresion de la piece de la case precedente lorsqie le mouvement est effectuer

}

void Board::setChessGrid(QGridLayout* grid) {
    gridLayout = grid;
}
bool Board::canAttackKing(PieceColor::Color player, Position& kingPos) {
    // Verifier si le roi est attaque
    for (int i = 0; i < SIZE_BOARD; i++) {
        for (int j = 0; j < SIZE_BOARD; j++) {
            Position position{ i, j };
            Piece* piece = board[position.y][position.x].get()->getPiece();

            // Si la piece appartient a l'adversaire, verifiez si elle peut attaquer le roi
            if (piece != nullptr) {
                if (piece->getPcolor() != player && piece->getPtype() != PieceType::KING) {
                    std::vector<Position> validMoves = validMovesOnBoard(piece->getPossibleMove(position, getSimpleBoard()), board[position.y][position.x].get());
                    for (const Position& move : validMoves) {
                        if (move.x == kingPos.x && move.y == kingPos.y) {
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}
bool Board::isKingInCheck(PieceColor::Color player) {
    Position kingPos = finKingPosition(player);
    return canAttackKing(player, kingPos);
}

void Board::changeCurrentPlayer() {
    if (currentPlayer == PieceColor::WHITE)
        currentPlayer = PieceColor::BLACK;
    else
        currentPlayer = PieceColor::WHITE;
}

PieceColor::Color Board::getCurrentPlayer() const {
    return currentPlayer;
}

bool Board::isSquareClicked() const {
    return isClicked;
}

std::vector<Position> Board::validMovesOnBoardWithKing(std::vector<Position> possibles, Square* clickedSquare) {

    std::vector<Position> validMoves = validMovesOnBoard(possibles, clickedSquare);

    auto endIterator = std::remove_if(validMoves.begin(), validMoves.end(), [=](auto pos) {
        auto iconSquare = board[pos.y][pos.x]->icon();
        auto piece = board[pos.y][pos.x]->removePiece();

        move(clickedSquare->getPosition(), pos);
        bool shouldDelete = isKingInCheck(getCurrentPlayer());
        move(pos, clickedSquare->getPosition());
        addPieceToSquare(std::move(piece), pos, iconSquare);

        return shouldDelete;
        });
    validMoves.erase(endIterator, validMoves.end());

    return validMoves;
}

Piece* Board::getPiece(Position& from) {
    return board[from.y][from.x]->getPiece();
}

bool Board::isCheckMate() {
    for (int i = 0; i < SIZE_BOARD * SIZE_BOARD; ++i) {
        int x = i / SIZE_BOARD;
        int y = i % SIZE_BOARD;
        Position pos{ x, y };

        if (isSquareOccupied(board[y][x].get()) == PieceColor::EMPTY)
            continue;

        if (board[y][x]->getPiece()->getPcolor() == currentPlayer) {
            bool isVectorPieceMovesEmpty = validMovesOnBoardWithKing(board[y][x]->getPiece()->getPossibleMove(pos, getSimpleBoard()), board[y][x].get()).empty();
            if (!isVectorPieceMovesEmpty) {
                return false;
            }
        }
    }
    return true;
}

Position Board::finKingPosition(PieceColor::Color player) const {
    Position kingPos = {};
    for (int i = 0; i < SIZE_BOARD * SIZE_BOARD; ++i) {
        int x = i / SIZE_BOARD;
        int y = i % SIZE_BOARD;

        Position pos{ x, y };

        Square* p = board[pos.y][pos.x].get();
        if (isSquareOccupied(p) != PieceColor::EMPTY && player == p->getPiece()->getPcolor()) {
            if (p->getPiece()->getPtype() == PieceType::KING) {
                kingPos = pos;
                break;
            }
        }
    }

    return kingPos;
}

void Board::resetBoard() {
    board = {};
    capturedBlackPiece = {};
    capturedWhitePiece = {};
}

bool Board::isCurrentPlayerCastling(const Position& to) {
    Square* toSquare = qobject_cast<Square*>(gridLayout->itemAtPosition(to.y, to.x)->widget());
    if (toSquare->getPiece() != nullptr) {
        return toSquare->getPiece()->getPcolor() != currentPlayer;
    }
    return false;
}

void Board::addCapturedPiece(Piece* p) {

    if (getCurrentPlayer() == PieceColor::WHITE) {
        capturedBlackPiece[p->getPtype()]++;
        std::cout << "Les pieces noirs captures de type " + p->toString() + " " << capturedBlackPiece[p->getPtype()] << std::endl;
    }

    else {
        capturedWhitePiece[p->getPtype()]++;
        std::cout << "Les pieces blanches captures de type " + p->toString() + " " << capturedWhitePiece[p->getPtype()] << std::endl;
    }

}

std::array<int, 5> Board::getCapturedPieceVector(PieceColor::Color player) const {
    if (player == PieceColor::WHITE)
        return capturedBlackPiece;
    else
        return capturedWhitePiece;
}

QGridLayout* Board::loadPieceAtPositions(RandomPieceInfos posVector) {
    ;
    for (int y = 0; y < SIZE_BOARD; ++y)
    {
        for (int x = 0; x < SIZE_BOARD; ++x)
        {
            Square* cell = qobject_cast<Square*>(gridLayout->itemAtPosition(y, x)->widget());
            board[y][x] = std::unique_ptr<Square>(cell);
        }
    }
    for (auto it : posVector) {

        Square* square = qobject_cast<Square*>(gridLayout->itemAtPosition(it.second.second.y, it.second.second.x)->widget());

        if (it.first == PieceType::PAWN) {
            square->addPiece(std::make_unique<Pawn>(it.first, it.second.first));
            if (it.second.first == PieceColor::WHITE) {
                square->setIconSquare(wPawn);
            }
            else
                square->setIconSquare(bPawn);

        }
        else if (it.first == PieceType::KING) {
            square->addPiece(std::make_unique<King>(it.first, it.second.first));
            if (it.second.first == PieceColor::WHITE) {
                square->setIconSquare(wKing);
            }
            else
                square->setIconSquare(bKing);

        }
        else if (it.first == PieceType::BISHOP) {
            square->addPiece(std::make_unique<Bishop>(it.first, it.second.first));
            if (it.second.first == PieceColor::WHITE) {
                square->setIconSquare(wBishop);
            }
            else
                square->setIconSquare(bBishop);

        }
        else if (it.first == PieceType::KNIGHT) {
            square->addPiece(std::make_unique<Knight>(it.first, it.second.first));
            if (it.second.first == PieceColor::WHITE) {
                square->setIconSquare(wKnight);
            }
            else
                square->setIconSquare(bKnight);

        }
        else if (it.first == PieceType::QUEEN) {
            square->addPiece(std::make_unique<Queen>(it.first, it.second.first));
            if (it.second.first == PieceColor::WHITE) {
                square->setIconSquare(wQueen);
            }
            else
                square->setIconSquare(bQueen);
        }
        else if (it.first == PieceType::ROOK) {
            square->addPiece(std::make_unique<Rook>(it.first, it.second.first));
            if (it.second.first == PieceColor::WHITE) {
                square->setIconSquare(wRook);
            }
            else
                square->setIconSquare(bRook);
        }

    }
    return gridLayout;
}


QGridLayout* Board::initParty1() {
    return loadPieceAtPositions(vectorGame1);
};
QGridLayout* Board::initParty2() {
    return loadPieceAtPositions(vectorGame2);
};