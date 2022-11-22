#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include "App.h"
#include "Pokemon.h"

int main()
{
    App::init(1920,1080,"Pokémon Cynthia");
    
    Pokemon tarsa;


    bool quit = false;
    while (!quit)
    {
        App::event();
    }
    return 0;
}
