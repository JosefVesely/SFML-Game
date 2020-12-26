#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Entity.h"

Game::~Game()
{
	delete this->window;
}

void Game::initWindow(const char* title, int width, int height, bool maximize)
{
	this->title = title;
	this->videoMode.width = width;
	this->videoMode.height = height;

	// Create window
	char style = maximize ? sf::Style::Default : sf::Style::Close;
	this->window = new sf::RenderWindow(this->videoMode, this->title, style);
	this->window->setFramerateLimit(60);

	// Set window icon
	sf::Image icon;
	icon.loadFromFile("assets/icon.png");
	this->window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void Game::init()
{
	this->running = true;
	this->initWindow("Game", 960, 540, false);
}

void Game::run()
{
	this->init();

	player.setPosition(512, 256);
	player.setSpeed(314.f);

	while (this->running)
	{
		this->handleEvents();
		this->update();
		this->render();
	}
}

void Game::close()
{
	this->window->close();
	this->running = false;
}

void Game::handleEvents()
{
	while (this->window->pollEvent(this->evnt))
	{
		switch (this->evnt.type)
		{
		case sf::Event::Closed:
			this->close();
			break;
		}
	}

	player.handleEvents(this->dt);
}

void Game::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();
}

void Game::update()
{
	this->updateDt();

	// Update FPS
	int fps = 1 / this->dt;
	std::string title = this->title + " FPS: " + std::to_string(fps);
	this->window->setTitle(title);

	// Update
	player.update(sf::Mouse::getPosition(*this->window));
}

void Game::render()
{
	this->window->clear(sf::Color(0, 0, 255));

	// Render
	player.render(*this->window);

	this->window->display();
}