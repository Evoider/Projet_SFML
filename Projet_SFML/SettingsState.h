#pragma once
#include "State.h"
#include "Button.h"

class SettingsState :
    public State
{
private:
    //Variable
    sf::Sprite background;
    sf::Texture textureBg;
    float scale;
    sf::Font font;


    std::map<std::string, Button*> buttons;

    //Functions
    void initFonts();
    void initKeyBinds();
    void initButtons();
    void initSprite();
public:
    SettingsState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, sf::Font font, float scale);

    ~SettingsState();
};

