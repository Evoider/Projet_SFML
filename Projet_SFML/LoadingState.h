#pragma once

#include "GameState.h"
#include "SettingsState.h"
class LoadingState :
    public State
{
private:
    //Variable
    sf::Sprite background;
    sf::Texture textureBg;
    float scale;
    float load;
    sf::Font font;
    std::string nextState;


    //Functions
    void initBackground();
    void initKeyBinds();

public:

    LoadingState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, sf::Font font, float scale, std::string nextState);

    ~LoadingState();

    //Functions
    void endState();


    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};

