#include "GameState.h"

void GameState::initKeyBinds()
{

	std::ifstream ifs("Config/gamestate_keybinds.ini");
	if (ifs.is_open())
	{
		std::string key = "";
		std::string key_name = "";

		while (ifs >> key >> key_name)
		{
			this->keyBinds[key] = this->supportedKeys->at(key_name);
		}
	}

	ifs.close();

	this->keyBinds["CLOSE"] = this->supportedKeys->at("Escape");
	this->keyBinds["MOVE_LEFT"] = this->supportedKeys->at("Q");
	this->keyBinds["MOVE_UP"] = this->supportedKeys->at("Z");
	this->keyBinds["MOVE_DOWN"] = this->supportedKeys->at("S");
	this->keyBinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	:State(window,supportedKeys, states),pmenu(*window)
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

	//Check for key pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_LEFT"))))
	{
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_UP"))) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_DOWN"))))
		{
			this->player.move(dt, -1.f, 0.f);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_UP"))))
	{
		this->player.move(dt, 0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_DOWN"))))
	{
		this->player.move(dt, 0.f, 1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_RIGHT"))))
	{
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_UP"))) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_DOWN"))))
		{
			this->player.move(dt, 1.f, 0.f);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("CLOSE"))))
	{
		if (!this->pause)
		{
			this->pauseState();
		}
		/*else
		{
			this->unpauseState();
		}*/
	}
}

void GameState::update(const float& dt)
{
	if (!this->pause) 
	{
		this->updateMousePosition();
		this->updateInput(dt);

		this->player.update(dt);
	}
	else //Pause update
	{
		this->pmenu.update();
	}
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
	this->player.render(target);

	if (this->pause) // Pause menu render
	{
		this->pmenu.render(target);
	}
}
