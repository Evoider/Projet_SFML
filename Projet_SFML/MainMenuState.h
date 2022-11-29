#pragma once
#include "GameState.h"
#include "Button.h"

class MainMenuState:
    public State
{
private:
    //Variable
    sf::Sprite background;
    sf::Texture textureBg;
    float scale;
    sf::Font font;
    
    sf::Clock clock;
    float elapsed;

    std::map<std::string, Button*> buttons;

    //Game State
    GameState*   game;

    //Functions
    void initFonts();
    void initKeyBinds();
    void initButtons();
    void initSprite();

public:

    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);

    virtual ~MainMenuState();

    //Functions
    void endState();

    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void renderButtons(sf::RenderTarget* target = nullptr);
    void render(sf::RenderTarget* target = nullptr);
};

