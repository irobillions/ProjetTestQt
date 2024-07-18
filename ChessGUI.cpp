#include "ChessGUI.hpp"
#include "Position.hpp"
#include <QLabel>
#include <QComboBox>
#include "DoubleInstanceOfKingError.hpp"
#include <cppitertools/range.hpp>

ChessGUI::ChessGUI(QWidget* parent) : QWidget(parent), chessController(ChessController()) {};


void ChessGUI::setUI() {

    QPalette palette;
    palette.setColor(QPalette::Window, QColor(211, 211, 211));

    //Labal pour le nom des joueurs qui joue
    verticalLayout = new QVBoxLayout(this);
    QLabel* playerTurns = new QLabel;
    playerTurns->setText("La partie peut commencer");
    playerTurns->setAlignment(Qt::AlignCenter);

    QFrame* horizontalFrameLine = new QFrame;
    horizontalFrameLine->setFrameShape(QFrame::HLine);

    verticalLayout->addWidget(playerTurns);
    verticalLayout->addWidget(horizontalFrameLine);

    QHBoxLayout* hLayout = new QHBoxLayout;

    QGridLayout* capturedWhitePieceTable = new QGridLayout;
    QGridLayout* capturedBlackPieceTable = new QGridLayout;

    QLabel* blackPiece[5];
    QLabel* countLabelBlack[5];


    QLabel* whitePiece[5];
    QLabel* countLabelWhite[5];

    blackPiece[0] = new QLabel;
    blackPiece[0]->setPixmap(QPixmap("images/bPawn.png").scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    blackPiece[1] = new QLabel;
    blackPiece[1]->setPixmap(QPixmap("images/bRook.png").scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    blackPiece[2] = new QLabel;
    blackPiece[2]->setPixmap(QPixmap("images/bKnight.png").scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    blackPiece[3] = new QLabel;
    blackPiece[3]->setPixmap(QPixmap("images/bBishop.png").scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    blackPiece[4] = new QLabel;
    blackPiece[4]->setPixmap(QPixmap("images/bQueen.png").scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    for (int i = 0; i < 5; i++) {
        countLabelBlack[i] = new QLabel("");
        capturedBlackPieceTable->addWidget(blackPiece[i], i, 0);
        capturedBlackPieceTable->addWidget(countLabelBlack[i], i, 1);
    }

    hLayout->addLayout(capturedBlackPieceTable);
    hLayout->addLayout(drawBoard());

    whitePiece[0] = new QLabel;
    whitePiece[0]->setPixmap(QPixmap("images/wPawn.png").scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    whitePiece[1] = new QLabel;
    whitePiece[1]->setPixmap(QPixmap("images/wRook.png").scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    whitePiece[2] = new QLabel;
    whitePiece[2]->setPixmap(QPixmap("images/wKnight.png").scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    whitePiece[3] = new QLabel;
    whitePiece[3]->setPixmap(QPixmap("images/wBishop.png").scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    whitePiece[4] = new QLabel;
    whitePiece[4]->setPixmap(QPixmap("images/wQueen.png").scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    capturedWhitePieceTable->setColumnMinimumWidth(1, 1);
    capturedWhitePieceTable->setColumnMinimumWidth(0, 1);

    for (int i = 0; i < 5; i++) {
        countLabelWhite[i] = new QLabel("");
        capturedWhitePieceTable->addWidget(whitePiece[i], i, 1);
        capturedWhitePieceTable->addWidget(countLabelWhite[i], i, 0);
    }
    hLayout->addLayout(capturedWhitePieceTable);

    verticalLayout->addLayout(hLayout);


    verticalLayout->setSpacing(5);
    verticalLayout->setContentsMargins(250, 30, 250, 20);
    this->setPalette(palette);
    this->setAutoFillBackground(true);
}
QGridLayout* ChessGUI::drawBoard() {

    QGridLayout* gridLayout = new QGridLayout;
    gridLayout->setSpacing(0);
    gridLayout->setContentsMargins(0, 0, 0, 0);
    Square* square;
    for (int y = 0; y < SIZE_BOARD; ++y)
    {
        for (int x = 0; x < SIZE_BOARD; ++x)
        {
            Position p{ x, y };
            QColor squareColor = (y + x) % 2 ? QColor(165, 103, 40) : QColor(255, 229, 204);
            square = new Square(squareColor, p, this);
            connect(square, &Square::clicked, this, [=]() { squareClicked(square); });
            gridLayout->addWidget(square, y, x);
        }
    }
    return gridLayout;
}


void ChessGUI::loadPiece(int n) {

    QHBoxLayout* hLay = dynamic_cast<QHBoxLayout*>(verticalLayout->itemAt(2));
    assert(hLay != nullptr);
    chessController.loadPieceFromBoard(dynamic_cast<QGridLayout*>(hLay->itemAt(1)), n);
}

void ChessGUI::squareClicked(Square* square) {
    auto label = dynamic_cast<QLabel*>(verticalLayout->itemAt(0)->widget());

    if (square->getPiece() == nullptr) {
        selectedSquare = square;
        chessController.squareIsClicked(selectedSquare);
        label->setText("");
    }
    else if (chessController.getCurrentPlayer() != square->getPiece()->getPcolor() && !chessController.isSquaredClicked()) {

        QString player = chessController.getCurrentPlayer() == PieceColor::BLACK ? "Noir" : "Blanc";
        QString message = "<font color='black'><b>C'est le tour du joueur" + player + "</b></font>" " ";
        label->setTextFormat(Qt::RichText);
        label->setText(message);
    }

    else {
        selectedSquare = square;
        chessController.squareIsClicked(selectedSquare);
    }

    updateCapturedBlackPieceTable(chessController.getCapturedPlayerPiece(PieceColor::WHITE));
    updateCapturedWhitePieceTable(chessController.getCapturedPlayerPiece(PieceColor::BLACK));
}

void ChessGUI::removeLayout() {
    if (!verticalLayout) {
        return;
    }

    while (QLayoutItem* item = verticalLayout->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            delete widget;
        }
        delete item;
    }

    delete verticalLayout;
}
void ChessGUI::initChessBoardUI(int n) {
    setUI();
    loadPiece(n);
}

void ChessGUI::resetGame(int n) {
    chessController.resetBoardGame();
    removeLayout();
}

void ChessGUI::updateCapturedWhitePieceTable(std::array<int, 5> captured) {
    QHBoxLayout* hLay = dynamic_cast<QHBoxLayout*>(verticalLayout->itemAt(2));

    auto capturedWhitePiece = dynamic_cast<QGridLayout*>(hLay->itemAt(2));

    QLabel* nBlackCaptured = dynamic_cast<QLabel*>(capturedWhitePiece->itemAtPosition(0, 0)->widget());
    nBlackCaptured->setText(QString::fromStdString(std::to_string((int)captured[PieceType::PAWN])));

    nBlackCaptured = dynamic_cast<QLabel*>(capturedWhitePiece->itemAtPosition(2, 0)->widget());
    nBlackCaptured->setText(QString::fromStdString(std::to_string((int)captured[PieceType::KNIGHT])));

    nBlackCaptured = dynamic_cast<QLabel*>(capturedWhitePiece->itemAtPosition(4, 0)->widget());
    nBlackCaptured->setText(QString::fromStdString(std::to_string((int)captured[PieceType::QUEEN])));

    nBlackCaptured = dynamic_cast<QLabel*>(capturedWhitePiece->itemAtPosition(1, 0)->widget());
    nBlackCaptured->setText(QString::fromStdString(std::to_string((int)captured[PieceType::ROOK])));

    nBlackCaptured = dynamic_cast<QLabel*>(capturedWhitePiece->itemAtPosition(3, 0)->widget());
    nBlackCaptured->setText(QString::fromStdString(std::to_string((int)captured[PieceType::BISHOP])));

}
void ChessGUI::updateCapturedBlackPieceTable(std::array<int, 5> captured) {
    QHBoxLayout* hLay = dynamic_cast<QHBoxLayout*>(verticalLayout->itemAt(2));

    auto capturedBlackPiece = dynamic_cast<QGridLayout*>(hLay->itemAt(0));

    QLabel* nBlackCaptured = dynamic_cast<QLabel*>(capturedBlackPiece->itemAtPosition(0, 1)->widget());
    nBlackCaptured->setText(QString::fromStdString(std::to_string((int)captured[PieceType::PAWN])));

    nBlackCaptured = dynamic_cast<QLabel*>(capturedBlackPiece->itemAtPosition(2, 1)->widget());
    nBlackCaptured->setText(QString::fromStdString(std::to_string((int)captured[PieceType::KNIGHT])));

    nBlackCaptured = dynamic_cast<QLabel*>(capturedBlackPiece->itemAtPosition(4, 1)->widget());
    nBlackCaptured->setText(QString::fromStdString(std::to_string((int)captured[PieceType::QUEEN])));

    nBlackCaptured = dynamic_cast<QLabel*>(capturedBlackPiece->itemAtPosition(1, 1)->widget());
    nBlackCaptured->setText(QString::fromStdString(std::to_string((int)captured[PieceType::ROOK])));

    nBlackCaptured = dynamic_cast<QLabel*>(capturedBlackPiece->itemAtPosition(3, 1)->widget());
    nBlackCaptured->setText(QString::fromStdString(std::to_string((int)captured[PieceType::BISHOP])));
}
