#pragma once
#include "State.h"
#include "Background.h"


class GameState :
    public State
{
private:
    Entity player;
    Background map;

    sf::View view;

    //Functions
    void initKeyBinds();

public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
     
    virtual ~GameState();

    //Functions
    void endState();

    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};
