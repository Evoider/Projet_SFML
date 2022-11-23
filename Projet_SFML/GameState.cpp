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
}

void GameState::update(const float& dt)
{
	std::cout << "Hello from GameStat" << std::endl;
}

void GameState::render(sf::RenderTarget* target)
{
}
