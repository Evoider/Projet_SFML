#include "GameState.h"

GameState::GameState(sf::RenderWindow* window)
	:State(window)
{
}

GameState::~GameState()
{
}




//Functions

void GameState::endState()
{
	std::cout << "Ending game state" << "\n";
}

void GameState::updateKeyBinds(const float& dt)
{
	this->checkForQuit();

	//Check for key pressed
}

void GameState::update(const float& dt)
{
	this->updateKeyBinds(dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		std::cout << "A" << std::endl;
	}
}

void GameState::render(sf::RenderTarget* target)
{
}
