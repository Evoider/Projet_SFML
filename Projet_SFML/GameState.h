#pragma once
#include "SettingsState.h"
#include "Background.h"
#include "PauseMenu.h"

class GameState :
    public State
{
private:
    float scale;
    sf::Font font;
    PauseMenu pmenu;

    Player player;
    Background test;

    //Functions
    void initKeyBinds();

public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, sf::Font font, float scale);

     
    virtual ~GameState();

    //Functions
    void endState();

    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};

