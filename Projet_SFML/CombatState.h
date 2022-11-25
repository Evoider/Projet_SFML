#pragma once
#include "GameState.h"
#include "Button.h"

class CombatState : public State
{
private: 

	//Pokemon AllyPokemon;
	//Pokemon EnnemyPokemon; 

	sf::Font font;

	sf::RectangleShape rectBlack;

	std::map<std::string, Button*> buttons;

	void initFonts();
	void initButtons();


	virtual void initKeyBinds();


public: 
	CombatState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);

	virtual ~CombatState() = default;

	void endState();
	virtual void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget* target = nullptr);
	void render(sf::RenderTarget* target = nullptr);


protected:


};
