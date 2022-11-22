#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include "App.h"

int main()
{

    App::init(1920,1080,"Pokémon Cynthia");
   

    bool quit = false;
    while (!quit)
    {
        
        App::event();

    }
    return 0;
}
