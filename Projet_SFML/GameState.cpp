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
	:State(window,supportedKeys, states), player(), map()
{
	this->initKeyBinds();
	this->view.reset(sf::FloatRect(1*64,2 * 64,(window->getSize().x),(window->getSize().y)));

	this->map.initTab();
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
			if (map.checkcollision(player.getPositionX(), player.getPositionY() + 1) == 0)
			{
				this->player.move("Left", view);
			}
			
		}
	}if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_UP"))))
	{
		if (map.checkcollision(player.getPositionX() + 1, player.getPositionY()) == 0)
		{
			this->player.move("Up", view);
		}
	}if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_DOWN"))))
	{
		if (map.checkcollision(player.getPositionX() + 1, player.getPositionY() + 2) == 0)
		{
			this->player.move("Down", view);
		}
	}if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_RIGHT"))))
	{
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_UP"))) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_DOWN"))))
		{
			if (map.checkcollision(player.getPositionX() + 2, player.getPositionY() + 1) == 0)
			{
				this->player.move("Right", view);
			}
		}
	}
}

void GameState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);

	this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
	target->setView(this->view);
	this->map.render(target);
	this->player.render(target);
}
