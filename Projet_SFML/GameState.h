#pragma once
#include "State.h"


class GameState :
    public State
{
private:

public:
    GameState();
     
    virtual ~GameState();

    //Functions
    void update();
    void render();
};

