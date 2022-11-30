#pragma once
#include "State.h"
#include "Gui.h"

class SettingsState :
    public State
{
private:
    //Variable
    unsigned int defResolution, defFullscreen, defVsync, defFrameRateLimit, defAntiAlias;
    GraphicsSettings& graphSettings;
    sf::Sprite background;
    sf::Texture textureBg;
    float scale;
    sf::Font font;


    std::map<std::string, gui::Button*> buttons;
    std::map<std::string, gui::DropDownList*> ddl;

    std::vector<sf::VideoMode> modes;
    //Functions
    void initVariables();
    void initKeyBinds();
    void initGui();
    void initBackground();
public:
    SettingsState(sf::RenderWindow* window, GraphicsSettings& graphSettings, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, sf::Font font, float scale );

    ~SettingsState();



    //Functions
    void endState();

    void updateWindow(sf::RenderWindow* window);
    void updateInput(const float& dt);
    void updateGui(const float& dt);
    void update(const float& dt);
    void renderGui(sf::RenderTarget* target = nullptr);
    void render(sf::RenderTarget* target = nullptr);
};

