#include "CombatState.h"

void CombatState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Pokemon-Solid.ttf"))
	{
		std::cout << "ERROR::MAINMENUSTATE::COULD NOT LOAD FONT" << "\n";
	}
}


void CombatState::initGui()
{
	this->buttons["ATTACK"] = new  gui::Button(this->window->getSize().x - 600, this->window->getSize().y - 200, 600, 100,
		this->font, "Attack", 30,
		sf::Color(255, 0, 0, 150),
		sf::Color(240, 0, 0, 255),
		sf::Color(235, 0, 0, 200)
	);

	this->buttons["POKEMON"] = new  gui::Button(this->window->getSize().x - 600, this->window->getSize().y - 100, 300, 100,
		this->font, "Pokemon", 30,
		sf::Color(255, 0, 0, 150),
		sf::Color(240, 0, 0, 255),
		sf::Color(235, 0, 0, 200)
	);

	this->buttons["FUITE"] = new  gui::Button(this->window->getSize().x - 300, this->window->getSize().y - 100, 300, 100,
		this->font, "Fuite", 30,
		sf::Color(255, 0, 0, 150),
		sf::Color(0, 240, 0, 255),
		sf::Color(0, 0, 235, 200)
	);


}

void CombatState::initKeyBinds()
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
}

CombatState::CombatState(sf::RenderWindow* window, GraphicsSettings& graphSettings, std::map<std::string, int>* supportedKeys, std::stack<State*>* states,sf::Font font, float scale)
	: State(window, supportedKeys, states),graphSettings(graphSettings),scale(scale),font(font), pmenu(window, graphSettings, font, scale, states, supportedKeys)
{
	this->initFonts();
	this->initGui();
	this->rectBlack.setSize(sf::Vector2f(600 * this->scale, 200 * this->scale));
	this->rectBlack.setPosition(this->window->getSize().x - 610 * this->scale, this->window->getSize().y - 210 * this->scale);
	this->rectBlack.setFillColor(sf::Color::Blue);
}

void CombatState::endState()
{
	this->quit = true;

	std::cout << "Ending Combat state" << states->size() << "\n";
}

void CombatState::updateWindow(sf::RenderWindow* window)
{
	this->window = window;
	this->scale = this->window->getSize().x / 1920.f;
	this->initGui();
	this->rectBlack.setSize(sf::Vector2f(600 * this->scale, 200 * this->scale));
	this->rectBlack.setPosition(this->window->getSize().x - 610 * this->scale, this->window->getSize().y - 210 * this->scale);
	
}

void CombatState::updateInput(const float& dt)
{
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


void CombatState::updateGui()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}
	for (auto& it : this->lifeBar)
	{
		it.second->update(this->mousePosView);
	}
}

void CombatState::update(const float& dt)
{
	this->updateGui();
	this->updateMousePosition();
	if (!this->pmenu.getPauseState())
	{

		this->updateInput(dt);
	}
	else //Pause update
	{
		this->pmenu.update(this->mousePosView, dt);
	}
	if (this->pmenu.getQuit())
	{
		this->endState();
	}

}

void CombatState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
	this->window->draw(rectBlack);
	this->renderGui(target);
}

void CombatState::renderGui(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
	for (auto& it : this->lifeBar)
	{
		it.second->render(target);
	}
}