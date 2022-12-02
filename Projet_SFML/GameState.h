#pragma once
#include "CombatState.h"
#include "Background.h"
#include "PauseMenu.h"
#include <SFML/Audio.hpp>

class GameState :
    public State
{
private:
    GraphicsSettings& graphSettings;
    float scale;
    sf::Font font;
    PauseMenu pmenu;
    sf::Music Celestia;

    Entity player;
    Background map;
    sf::View view;


    //Functions
    void initKeyBinds();

public:
    GameState(sf::RenderWindow* window, GraphicsSettings& graphSettings, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, sf::Font font, float scale);

     
    virtual ~GameState();

    //Functions
    void endState();

    void updateWindow(sf::RenderWindow* window);
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};

