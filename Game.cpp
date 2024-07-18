#include "Game.hpp"


Game::Game() : game(new MainGUI) {};

void Game::run() {
	game->show();
}

Game::~Game() {
	delete game;
}