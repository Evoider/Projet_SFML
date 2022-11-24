#include "GameState.h"

void GameState::initKeyBinds()
{
	this->keyBinds.emplace("MOVE_LEFT", this->supportedKeys->at("Q"));
	this->keyBinds.emplace("MOVE_UP", this->supportedKeys->at("Z"));
	this->keyBinds.emplace("MOVE_DOWN", this->supportedKeys->at("S"));
	this->keyBinds.emplace("MOVE_RIGHT", this->supportedKeys->at("D"));
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
	:State(window,supportedKeys)
{
	this->initKeyBinds();
}

GameState::~GameState()
{
}




//Functions

void GameState::endState()
{
	std::cout << "Ending game state" << "\n";
}

void GameState::updateInput(const float& dt)
{
	this->checkForQuit();

	//Check for key pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_LEFT"))))
	{
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_UP"))) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_DOWN"))))
		{
			this->player.move(dt, -1.f, 0.f);
		}
	}if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_UP"))))
	{
		this->player.move(dt, 0.f, -1.f);
	}if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_DOWN"))))
	{
		this->player.move(dt, 0.f, 1.f);
	}if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_RIGHT"))))
	{
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_UP"))) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_DOWN"))))
		{
			this->player.move(dt, 1.f, 0.f);
		}
	}
}

void GameState::update(const float& dt)
{
	this->updateInput(dt);

	this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
	this->player.render(target);
}
