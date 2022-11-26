#include <stdio.h>
#include <iostream>
#include <string>
#include "Game.h"
#include "Combat.h"
#include "Pokemon.h"

int main()
{
    std::cout << "Bonjour Cynthia, comment va-tu aujourd'hui?" << std::endl;
    std::cout <<std::endl;
    std::cout << "[...]" << std::endl;
    std::cout << std::endl;
    std::cout << "Mmhhh très bien, vois-tu je suis en train de faire des recherche qui pouront révolutionner notre monde" << std::endl;
    std::cout << "Ah tu réfléchis à ce que je t'ai proposer?" << std::endl;
    std::cout << "[ELISPE]" << std::endl;
    std::cout << "Pour t'aider dans ta quête je te confie ce petit bonhomme, prend en bien soins" << std::endl;
    std::cout << "[Tu as obtenue Griknot]" << std::endl;
    std::cout << "Il t'aidera à te defendre contre les pokemon malfesant" << std::endl;
    std::cout << "[Tu sors et te fais attaquer par un ROZBOUTON]" << std::endl;
    Pokemon Tiplouf, Griknot, Rozbouton;
    Griknot.creationPokemon(443);
    Rozbouton.creationPokemon(406);

    Combat premierCombat(Griknot, Rozbouton);
    premierCombat.fighting();
    //delete premierCombat;

    std::cout << "Très bien tu as battue ton premier pokemon, pour te felicite je te heal" << std::endl;
    std::cout << Tiplouf.getPv() << std::endl;
    Tiplouf.healMax();
    system("pause");
    std::cout << Tiplouf.getPv() << std::endl;
    //delete premierCombat;

    
    return 0;
}


//Créer une petit IA qui voit choisir quelle attaque faire
//Créer les réstance et faiblesse