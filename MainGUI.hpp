#pragma once

#include <Qwidget>
#include <QStackedWidget>
#include <QMainWindow>
#include "ChessGUI.hpp"

class MainGUI :public QMainWindow {
	Q_OBJECT
public:
	MainGUI(QWidget* parent = nullptr);
	void changePage(QStackedWidget* stackedWidget);
	void setMainGUI();

public slots:
	void initTheGame(int currentIndex);
private:
	ChessGUI* chessUI;
	int indexGame = 0;
};