#include "Game.h"


//Static Functions

//Initializer Functions

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Pok�mon Cynthia", sf::Style::Default);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

//Constructor/Destructor
Game::Game()
{
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}


//Functions

void Game::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();	

}

void Game::updateSFMLEvents()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::update()
{
	/*Update dt variable with the time elapsed to update and render in one frame*/

	this->updateSFMLEvents();

}

void Game::render()
{
	this->window->clear();
	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}

