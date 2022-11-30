#pragma once
#include "GameState.h"

#include "Gui.h"

class MainMenuState:
    public State
{
private:
    //Variable
    sf::Sprite background;
    sf::Texture textureBg;
    float scale;
    sf::Font font;
    sf::Text title;
    sf::RectangleShape titleBox;

    std::map<std::string, gui::Button*> buttons;

    
    //Functions
    void initFonts();
    void initKeyBinds();
    void initButtons();
    void initBackground();

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

