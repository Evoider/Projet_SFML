#include "CombatState.h"


void CombatState::initSprite(Pokemon gentil, Pokemon mechant)
{
	this->texture_ally.loadFromFile("Ressources/Sprites/pokemon/dos/pachirisu.png");
	this->texture_ennemy.loadFromFile("Ressources/Sprites/pokemon/face/griknot.png");
	this->ally.setTexture(texture_ally);
	this->ennemy.setTexture(texture_ennemy);

	this->ally.setScale(5 * this->scale, 5 * this->scale);
	this->ennemy.setScale(5 * this->scale, 5 * this->scale);
	this->ally.setPosition(220 * this->scale, 479 * this->scale);
	this->ennemy.setPosition(1270 * this->scale, 180 * this->scale);

}

void CombatState::initGui()
{
	this->buttons["ATTACK 1"] = new  gui::Button(this->window->getSize().x - 600 * this->scale, this->window->getSize().y - 200 * this->scale,
		300 * this->scale, 100 * this->scale,
		this->font, "Capacite 1", 30, sf::Color::Black,
		sf::Color(255, 240, 230, 255),
		sf::Color(200, 200, 200, 255),
		sf::Color(100, 100, 100, 200),
		sf::Color(0, 0, 235, 255), 2 * this->scale
	);
	this->buttons["ATTACK 2"] = new  gui::Button(this->window->getSize().x - 300 * this->scale, this->window->getSize().y - 200 * this->scale,
		300 * this->scale, 100 * this->scale,
		this->font, "Capacite 2", 30, sf::Color::Black,
		sf::Color(255, 240, 230, 255),
		sf::Color(200, 200, 200, 255),
		sf::Color(100, 100, 100, 200),
		sf::Color(0, 0, 235, 255), 2 * this->scale
	);

	this->buttons["POKEMON"] = new  gui::Button(this->window->getSize().x - 600 * this->scale, this->window->getSize().y - 100 * this->scale,
		300 * this->scale, 100 * this->scale,
		this->font, "Pokemon", 30, sf::Color::Black,
		sf::Color(255, 240, 230, 255),
		sf::Color(200, 200, 200, 255),
		sf::Color(100, 100, 100, 200),
		sf::Color(0, 0, 235, 255), 2 * this->scale
	);

	this->buttons["FUITE"] = new  gui::Button(this->window->getSize().x - 300 * this->scale, this->window->getSize().y - 100 * this->scale,
		300 * this->scale, 100 * this->scale,
		this->font, "Fuite", 30, sf::Color::Black,
		sf::Color(255, 240, 230, 255),
		sf::Color(200, 200, 200, 255),
		sf::Color(100, 100, 100, 200),
		sf::Color(0, 0, 235, 255), 2 * this->scale
	);

	this->lifeBar["GENTIL"] = new gui::LifeBarBox(this->window->getSize().x - 625 * this->scale, this->window->getSize().y - 450 * this->scale,
		600 * this->scale, 200 * this->scale,
		this->font, this->gentil.getNom(), this->gentil.getLvl(), this->gentil.getPv(), 50 * this->scale,
		sf::Color(255, 240, 230, 255),
		sf::Color(0, 240, 0, 255),
		sf::Color(0, 0, 235, 255), 2 * this->scale
	);
	this->lifeBar["GENTIL"]->showTextLife();

	this->lifeBar["MECHANT"] = new gui::LifeBarBox(25 * this->scale, 25 * this->scale,
		600 * this->scale, 200 * this->scale,
		this->font, this->mechant.getNom(), this->mechant.getLvl(), this->mechant.getPv(), 50 * this->scale,
		sf::Color(255, 240, 230, 255),
		sf::Color(0, 240, 0, 255),
		sf::Color(0, 0, 235, 255), 2 * this->scale
	);
}

void  CombatState::initBackground()
{
	this->texturebg.loadFromFile("Ressources/Sprites/battlegroundgrass.png");

	float scalebg = this->window->getSize().x / (float)(this->texturebg.getSize().x);
	this->backgound.setTexture(texturebg);
	this->backgound.setPosition(0, - 200 * this->scale);
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
	if (!this->battle_Music.openFromFile("Ressources/music/Cynthia_Battle.ogg"))
		std::cout << "Unable to load";
	this->battle_Music.setVolume(10);
	this->battle_Music.play();
	this->battle_Music.setLoop(true);
	this->gentil.creationPokemon(numero_gentil);
	this->mechant.creationPokemon(numero_mechant);
	this->initBackground();
	this->initSprite(this->gentil, this->mechant);
	this->initKeyBinds();
	this->initGui();
	
	Combat fight(gentil, mechant);
	this->attacked = fight.checkBeginer();
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
	this->battle_Music.stop();
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

	if (this->buttons["FUITE"]->isPressed() && this->getKeytime())
	{
		this->endState();
	}
	if (this->buttons["POKEMON"]->isPressed() && this->getKeytime())
	{
		std::cout << "gentil : " << this->gentil.getPv() << "\n";
		std::cout << "mechant " << this->mechant.getPv() << "\n";
	}
	
	if (this->buttons["ATTACK 1"]->isPressed() && this->getKeytime())
	{
		this->gentil.attaquer(this->mechant, 1);
		this->lifeBar["MECHANT"]->setLife(this->mechant.getPv());
		this->attacked = true;

	}

	if (this->buttons["ATTACK 2"]->isPressed() && this->getKeytime())
	{
		this->gentil.attaquer(this->mechant, 2);
		this->lifeBar["MECHANT"]->setLife(this->mechant.getPv());
		this->attacked = true;

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

	if (this->attacked)
	{
		int random = std::rand() % 2 + 1;
		this->mechant.attaquer(this->gentil, random);
		this->lifeBar["GENTIL"]->setLife(this->gentil.getPv());
		this->attacked = false;
	}

	if (this->gentil.getPv() <= 0 || this->mechant.getPv() <= 0)
		this->endState();

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