#include "Game.h"

Game::Game()
{
	this->init("Title", 800, 600, false);
}

Game::~Game()
{
	delete this->window;
}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	this->window = nullptr;
	this->window = new sf::RenderWindow(sf::VideoMode(width, height), title);
}

void Game::handleEvents()
{
	while (this->window->pollEvent(this->evnt))
	{
		switch (evnt.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;

		case sf::Event::KeyPressed:
			if (evnt.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::update()
{

}

void Game::render()
{
	this->window->clear(sf::Color(0, 0, 255));

	// render

	this->window->display();
}

void Game::clean()
{

}

bool Game::running()
{
	return isRunning;
}
