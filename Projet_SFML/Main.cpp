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
    std::cout << "Mmhhh tres bien, vois-tu je suis en train de faire des recherche qui pouront revolutionner notre monde" << std::endl;
    std::cout << "Ah tu refléchis a ce que je t'ai propose?" << std::endl;
    std::cout << "[ELISPE]" << std::endl;
    std::cout << "Pour t'aider dans ta quête je te confie ce petit bonhomme, prend en bien soins" << std::endl;
    std::cout << "[Tu as obtenue Griknot]" << std::endl;
    std::cout << "Il t'aidera à te defendre contre les pokemon malfesant" << std::endl;
    std::cout << "[Tu sors et te fais attaquer par un ROZBOUTON]" << std::endl;
    system("pause");
    system("cls");
    Pokemon Tiplouf, Griknot, Rozbouton;
    Griknot.creationPokemon(443);
    Rozbouton.creationPokemon(406);

    Combat premierCombat(Griknot, Rozbouton);
    premierCombat.fighting();
    //delete premierCombat;


    return 0;
}


//Créer une petit IA qui voit choisir quelle attaque faire
//Créer les réstance et faiblesse