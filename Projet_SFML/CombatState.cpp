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
	this->buttons["ATTACK"] = new  gui::Button(this->window->getSize().x - 600 * this->scale, this->window->getSize().y - 200, 600, 100,
		this->font, "Attack", 30,
		sf::Color(255, 0, 0, 150),
		sf::Color(240, 0, 0, 255),
		sf::Color(235, 0, 0, 200)
	);

	this->buttons["POKEMON"] = new  gui::Button(this->window->getSize().x - 600, this->window->getSize().y - 100, 300, 100,
		this->font, "Pokemon", 30,
		sf::Color(0, 255, 0, 150),
		sf::Color(0, 240, 0, 255),
		sf::Color(0, 235, 0, 200)
	);

	this->buttons["FUITE"] = new  gui::Button(this->window->getSize().x - 300, this->window->getSize().y - 100, 300, 100,
		this->font, "Fuite", 30,
		sf::Color(0, 0, 255, 150),
		sf::Color(0, 0, 240, 255),
		sf::Color(0, 0, 235, 200)
	);

}

void  CombatState::initBackground()
{
	this->texturebg.loadFromFile("Ressources/Sprites/battlegroundgrass.png");

	float scalebg = this->window->getSize().x / (float)(this->texturebg.getSize().x);
	this->backgound.setTexture(texturebg);
	this->backgound.setPosition(this->backgound.getPosition().x, this->backgound.getPosition().y - 200 * this->scale);
	this->backgound.setScale(scalebg, scalebg);
}


void CombatState::initKeyBinds()
{

}

CombatState::CombatState(sf::RenderWindow* window, GraphicsSettings& graphSettings, std::map<std::string, int>* supportedKeys, std::stack<State*>* states,
	sf::Font font, float scale, int numero_gentil, int numero_mechant)
	: State(window, supportedKeys, states),graphSettings(graphSettings),scale(scale),font(font)
{
	this->initFonts();
	this->initBackground();
	this->initButtons();

	this->gentil.creationPokemon(numero_gentil);
	this->mechant.creationPokemon(numero_mechant);

	Combat fight(gentil, mechant);

}

void CombatState::endState()
{
	std::cout << "Ending fight state" << "\n";
}

void CombatState::updateWindow(sf::RenderWindow* window)
{
	this->window = window;
	this->scale = this->window->getSize().x / 1920.f;
	this->initBackground();
	this->initButtons();
	
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
	target->draw(this->backgound);
	this->renderButtons(target);
}

void CombatState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}