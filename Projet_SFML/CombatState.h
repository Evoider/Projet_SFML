#pragma once
#include "Pokemon.h"
#include "Gui.h"
#include "Combat.h"
#include "PauseMenu.h"
#include <SFML/Audio.hpp>

class CombatState : public State
{
private:
	GraphicsSettings& graphSettings;
	PauseMenu pmenu;
	float scale;

	sf::Texture texture_ally;
	sf::Texture texture_ennemy;
	sf::Sprite ally;
	sf::Sprite ennemy;
	sf::Sprite backgound;
	sf::Texture texturebg;
	sf::Music battle_Music;

	Pokemon gentil;
	Pokemon mechant;

	sf::Font font;


	std::map<std::string, gui::Button*> buttons;
	std::map < std::string, gui::LifeBarBox*> lifeBar;

	void initGui();
	void initSprite(Pokemon ally, Pokemon ennemy);
	void initBackground();


	void initKeyBinds();


public:
	CombatState(sf::RenderWindow* window, GraphicsSettings& graphSettings, std::map<std::string, int>* supportedKeys, std::stack<State*>* states,
		sf::Font font, float scale, int numero_gentil, int numero_mechant);

	~CombatState();

	void endState();

	void updateWindow(sf::RenderWindow* window);
	void updateInput(const float& dt);
	void updateGui();

	void update(const float& dt);
	void renderGui(sf::RenderTarget* target = nullptr);
	void render(sf::RenderTarget* target = nullptr);


protected:


};
