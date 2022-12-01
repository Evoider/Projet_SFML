#pragma once
#include "SettingsState.h"
#include "PauseMenu.h"
#include "Gui.h"

class CombatState : public State
{
private:
	GraphicsSettings& graphSettings;
	PauseMenu pmenu;
	float scale;

	//Pokemon AllyPokemon;
	//Pokemon EnnemyPokemon; 

	sf::Font font;

	sf::RectangleShape rectBlack;

	std::map<std::string, gui::Button*> buttons;
	std::map < std::string, gui::LifeBarBox*> lifeBar;

	void initFonts();
	void initGui();


	virtual void initKeyBinds();


public:
	CombatState(sf::RenderWindow* window, GraphicsSettings& graphSettings, std::map<std::string, int>* supportedKeys, std::stack<State*>* states,sf::Font font, float scale);

	virtual ~CombatState() = default;

	void endState();

	virtual void updateWindow(sf::RenderWindow* window);
	virtual void updateInput(const float& dt);
	void updateGui();

	void update(const float& dt);
	void renderGui(sf::RenderTarget* target = nullptr);
	void render(sf::RenderTarget* target = nullptr);


protected:


};
