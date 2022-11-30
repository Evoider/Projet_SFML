#pragma once
#include "State.h"
#include "Gui.h"

class SettingsState :
    public State
{
private:
    //Variable
    sf::Sprite background;
    sf::Texture textureBg;
    float scale;
    sf::Font font;


    std::map<std::string, gui::Button*> buttons;
    std::map<std::string, gui::DropDownList*> ddl;

    //Functions
    void initKeyBinds();
    void initGui();
    void initBackground();
public:
    SettingsState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, sf::Font font, float scale);

    ~SettingsState();

    //Functions
    void endState();

    void updateInput(const float& dt);
    void updateGui(const float& dt);
    void update(const float& dt);
    void renderGui(sf::RenderTarget* target = nullptr);
    void render(sf::RenderTarget* target = nullptr);
};

