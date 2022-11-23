#include <stdio.h>
#include <iostream>
#include <string>
#include "Game.h"
#include "Combat.h"
#include "Pokemon.h"

int main()
{
    Pokemon Tiplouf, Noctali;
    Tiplouf.creationPokemon(393);
    Noctali.creationPokemon(197);

    std::cout << "PV Noctali :" << Noctali.getpv() << std::endl;
    Tiplouf.attaquer(Noctali);
    std::cout << "PV Noctali :" << Noctali.getpv() << std::endl;
    return 0;
}
