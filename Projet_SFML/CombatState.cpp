#include "CombatState.h"


void CombatState::initSprite(Pokemon gentil, Pokemon mechant)
{
	this->texture_ally.loadFromFile("Ressources/Sprites/pokemon/dos/pachirisu.png");
	this->texture_ennemy.loadFromFile("Ressources/Sprites/pokemon/face/griknot.png");
	this->ally.setTexture(texture_ally);
	this->ennemy.setTexture(texture_ennemy);

	this->ally.scale(5, 5);
	this->ennemy.scale(5, 5);
	this->ally.setPosition(this->window->getSize().x - 1700 * this->scale, this->window->getSize().y - 601 * this->scale);
	this->ennemy.setPosition(this->window->getSize().x - 650 * this->scale, this->window->getSize().y - 900 * this->scale);
}

void CombatState::initGui()
{
	this->buttons["ATTACK"] = new  gui::Button(this->window->getSize().x - 600 * this->scale, this->window->getSize().y - 200 * this->scale,
		600 * this->scale, 100 * this->scale,
		this->font, "Attack", 30,
		sf::Color(255, 0, 0, 150),
		sf::Color(240, 0, 0, 255),
		sf::Color(235, 0, 0, 200),
		sf::Color(0, 0, 235, 255), 2 * this->scale
	);

	this->buttons["POKEMON"] = new  gui::Button(this->window->getSize().x - 600 * this->scale, this->window->getSize().y - 100 * this->scale,
		300 * this->scale, 100 * this->scale,
		this->font, "Pokemon", 30,
		sf::Color(255, 0, 0, 150),
		sf::Color(240, 0, 0, 255),
		sf::Color(235, 0, 0, 200),
		sf::Color(0, 0, 235, 255), 2 * this->scale
	);

	this->buttons["FUITE"] = new  gui::Button(this->window->getSize().x - 300 * this->scale, this->window->getSize().y - 100 * this->scale,
		300 * this->scale, 100 * this->scale,
		this->font, "Fuite", 30,
		sf::Color(255, 0, 0, 150),
		sf::Color(0, 240, 0, 255),
		sf::Color(0, 0, 235, 200),
		sf::Color(0, 0, 235, 255), 2 * this->scale
	);

	this->lifeBar["GENTIL"] = new gui::LifeBarBox(this->window->getSize().x - 625 * this->scale, this->window->getSize().y - 450 * this->scale,
		600 * this->scale, 200 * this->scale,
		this->font, "Trouduc", 1, 200, 50 * this->scale,
		sf::Color(255, 0, 0, 150),
		sf::Color(0, 240, 0, 255),
		sf::Color(0, 0, 235, 255), 2 * this->scale
	);
	this->lifeBar["GENTIL"]->showTextLife();

	this->lifeBar["MECHANT"] = new gui::LifeBarBox(25 * this->scale, 25 * this->scale,
		600 * this->scale, 200 * this->scale,
		this->font, "Grofion", 1, 200, 50 * this->scale,
		sf::Color(255, 0, 0, 150),
		sf::Color(0, 240, 0, 255),
		sf::Color(0, 0, 235, 255), 2 * this->scale
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

CombatState::CombatState(sf::RenderWindow* window, GraphicsSettings& graphSettings, std::map<std::string, int>* supportedKeys, std::stack<State*>* states,
	sf::Font font, float scale,int numero_gentil, int numero_mechant)
	: State(window, supportedKeys, states),graphSettings(graphSettings),scale(scale),font(font), pmenu(window, graphSettings, font, scale, states, supportedKeys)
{
	this->gentil.creationPokemon(numero_gentil);
	this->mechant.creationPokemon(numero_mechant);
	this->initBackground();
	this->initSprite(this->gentil, this->mechant);
	this->initKeyBinds();
	this->initGui();
	
	Combat fight(gentil, mechant);
}

CombatState::~CombatState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
	auto it2 = this->lifeBar.begin();
	for (it2 = this->lifeBar.begin(); it2 != this->lifeBar.end(); ++it2)
	{
		delete it2->second;
	}
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
	this->initBackground();
	this->initSprite(this->gentil, this->mechant);
	this->initGui();
	
	this->pmenu.updateWindow(window, this->scale);

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

	if (this->buttons["FUITE"]->isPressed())
	{
		this->endState();
	}
	
	if (this->buttons["ATTACK"]->isPressed())
	{
		this->lifeBar["MECHANT"]->setLife(150);
	}
}

void CombatState::update(const float& dt)
{
	this->updateGui();
	this->updateKeytime(dt);
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
	target->draw(this->backgound);
	target->draw(this->ally);
	target->draw(this->ennemy);
	this->renderGui(target);
	if (this->pmenu.getPauseState()) // Pause menu render
	{
		this->pmenu.render(target);
	}
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