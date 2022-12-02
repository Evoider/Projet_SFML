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
	this->keyBinds["COMBAT"] = this->supportedKeys->at("C");
}

GameState::GameState(sf::RenderWindow* window, GraphicsSettings& graphSettings, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, sf::Font font, float scale)
	:State(window, supportedKeys, states), graphSettings(graphSettings), scale(scale),font(font), pmenu(window,graphSettings, font, scale, states, supportedKeys), map(),player()
{
	this->initKeyBinds();
	this->view.reset(sf::FloatRect(0, 0 , (window->getSize().x), (window->getSize().y)));
	this->view.setCenter(this->player.getPositionX() * 64 + 32, this->player.getPositionY() * 64 + 64);

	this->view.zoom(0.5f);
	this->map.initTab();
	
}

GameState::~GameState()
{
}




//Functions

void GameState::endState()
{
	this->quit = true;

	std::cout << "Ending game state" << states->size() << "\n";
}

void GameState::updateWindow(sf::RenderWindow* window)
{
	this->window = window;
	this->scale = this->window->getSize().x / 1920.f;
	this->initKeyBinds();
	this->view.reset(sf::FloatRect(0, 0, (window->getSize().x), (window->getSize().y)));
	this->view.setCenter(this->player.getPositionX() * 64 + 32, this->player.getPositionY() * 64 + 64);
	this->view.zoom(0.5f);
	this->pmenu.updateWindow(window,this->scale);
}

void GameState::updateInput(const float& dt)
{
	

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
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_UP"))))
	{
		if (map.checkcollision(player.getPositionX() + 1, player.getPositionY()) == 0)
		{
			this->player.move("Up", view);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_DOWN"))))
	{
		if (map.checkcollision(player.getPositionX() + 1, player.getPositionY() + 2) == 0)
		{
			this->player.move("Down", view);


		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_RIGHT"))))
	{
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_UP"))) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_DOWN"))))
		{
			if (map.checkcollision(player.getPositionX() + 2, player.getPositionY() + 1) == 0)
			{
				this->player.move("Right", view);
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("COMBAT"))))

	{
		this->window->setView(this->window->getDefaultView());
		this->states->push(new CombatState(this->window, this->graphSettings, this->supportedKeys, this->states, this->font, this->scale, 417,443));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("CLOSE"))) && this->getKeytime())
	{
		if (!this->pmenu.getPauseState())
		{
			this->pmenu.pauseState();

		}
		else
		{
			this->pmenu.unpauseState();
		}
	}
}

void GameState::update(const float& dt)
{
	this->updateKeytime(dt);
	

	if (!this->pmenu.getPauseState())
	{
		this->updateMousePosition();
		this->updateInput(dt);
		this->player.update(dt);
	}
	else //Pause update
	{

		this->window->setView(this->window->getDefaultView());
		this->pmenu.update(this->mousePosView,dt);
		
	}
	if (this->pmenu.getQuit())
	{
		this->endState();
	}
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
	if (this->pmenu.getPauseState()) // Pause menu render
	{
		target->setView(target->getDefaultView());
		this->updateMousePosition();
		this->pmenu.render(target);

		
	}
	
}
