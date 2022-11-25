#include "CombatState.h"

void CombatState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Pokemon-Solid.ttf"))
	{
		std::cout << "ERROR::MAINMENUSTATE::COULD NOT LOAD FONT" << "\n";
	}
}


void CombatState::initButtons()
{
	this->buttons["ATTACK"] = new Button(this->window->getSize().x - 600, this->window->getSize().y - 200, 600, 100,
		this->font, "Attack", 30,
		sf::Color(255, 0, 0, 150),
		sf::Color(240, 0, 0, 255),
		sf::Color(235, 0, 0, 200)
	);

	this->buttons["POKEMON"] = new Button(this->window->getSize().x - 600, this->window->getSize().y - 100, 300, 100,
		this->font, "Pokemon", 30,
		sf::Color(255, 0, 0, 150),
		sf::Color(240, 0, 0, 255),
		sf::Color(235, 0, 0, 200)
	);

	this->buttons["FUITE"] = new Button(this->window->getSize().x - 300, this->window->getSize().y - 100, 300, 100,
		this->font, "Fuite", 30,
		sf::Color(255, 0, 0, 150),
		sf::Color(0, 240, 0, 255),
		sf::Color(0, 0, 235, 200)
	);

}

void CombatState::initKeyBinds()
{

}

CombatState::CombatState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states): State(window,supportedKeys,states)
{
	this->initFonts();
	this->initButtons();
	this->rectBlack.setSize(sf::Vector2f(600,200));
	this->rectBlack.setPosition(this->window->getSize().x - 610, this->window->getSize().y - 210);
	this->rectBlack.setFillColor(sf::Color::Blue);
}

void CombatState::endState()
{
	std::cout << "Ending fight state" << "\n";
}

void CombatState::updateInput(const float& dt)
{

}


void CombatState::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}
}

void CombatState::update(const float& dt)
{
	this->updateButtons();
	this->updateMousePosition();
	this->updateInput(dt);

}

void CombatState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
	this->window->draw(rectBlack);
	this->renderButtons(target);
}

void CombatState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}
