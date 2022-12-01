#pragma once
#include "SettingsState.h"
#include "Pokemon.h"
#include "Gui.h"
#include "Combat.h"

class CombatState : public State
{
private:
	GraphicsSettings& graphSettings;
	sf::Sprite backgound;
	sf::Texture texturebg;
	float scale;

	sf::Font font;

	std::map<std::string, gui::Button*> buttons;

	Pokemon gentil;
	Pokemon mechant;

	void initFonts();
	void initButtons();
	void initBackground();


	virtual void initKeyBinds();


public:
	CombatState(sf::RenderWindow* window, GraphicsSettings& graphSettings, std::map<std::string, int>* supportedKeys, std::stack<State*>* states,sf::Font font, float scale, int numero_gentil, int numero_mechant);

	virtual ~CombatState() = default;

	void endState();

	virtual void updateWindow(sf::RenderWindow* window);
	virtual void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget* target = nullptr);
	void render(sf::RenderTarget* target = nullptr);


protected:


};
