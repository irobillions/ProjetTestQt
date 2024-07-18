#include "MainGUI.hpp"
#include <QLabel>
#include <QComboBox>
#include <iostream>

MainGUI::MainGUI(QWidget* parent) :QMainWindow(parent), chessUI(nullptr) {
    setMainGUI();
};


void MainGUI::changePage(QStackedWidget* stackedWidget) {
    int currentIndex = stackedWidget->currentIndex();

    if (currentIndex + 1 < stackedWidget->count())
    {
        stackedWidget->setCurrentIndex(currentIndex + 1);
        chessUI->initChessBoardUI(indexGame);
    }
    else
    {
        chessUI->resetGame(indexGame);
        stackedWidget->setCurrentIndex(0);
    }
}
void MainGUI::setMainGUI() {
    QWidget* mainUI = new QWidget;
    chessUI = new ChessGUI;


    QVBoxLayout* vLayoutMain = new QVBoxLayout;
    QPalette palette;
    palette.setColor(QPalette::Window, QColor(153, 121, 80));
    QLabel* label = new QLabel;
    QPixmap pixmap("images/chessGame.jpg");


    label->setPixmap(pixmap.scaled(800, 500, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    label->setAlignment(Qt::AlignCenter);
    //label->setStyleSheet("border: 1px solid black; padding: 10px;");
    //label->setFixedSize(800, 400);
    QComboBox* listOfParties = new QComboBox(this);
    listOfParties->addItems({ "Normal Game","Game 1", "Game 2" });

    connect(listOfParties, SIGNAL(currentIndexChanged(int)), this, SLOT(initTheGame(int)));
    vLayoutMain->addWidget(label);
    vLayoutMain->addWidget(listOfParties);
    mainUI->setPalette(palette);
    mainUI->setLayout(vLayoutMain);

    QStackedWidget* stackedWidget = new QStackedWidget;

    stackedWidget->addWidget(mainUI);
    stackedWidget->addWidget(chessUI);

    QPushButton* toGame = new QPushButton;

    toGame->setText("new Game");
    toGame->setStyleSheet("background-color: light gray;");
    ///toGame->setFixedWidth(200);

    connect(toGame, &QPushButton::clicked, this, [=] { changePage(stackedWidget); });
    QVBoxLayout* vLayout = new QVBoxLayout;
    vLayout->addWidget(stackedWidget);
    vLayout->addWidget(toGame);

    QWidget* g = new QWidget;
    g->setLayout(vLayout);
    g->setPalette(palette);
    setCentralWidget(g);

}

void MainGUI::initTheGame(int currentIndex) {
    indexGame = currentIndex;
}