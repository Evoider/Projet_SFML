#include <stdio.h>
#include <iostream>
#include <string>
#include "Game.h"
#include "Combat.h"
#include "Pokemon.h"

int main()
{
    int choixStarteur;
    std::cout << "Bonjour jeune dresseur, choisie ton starteur" << std::endl;
    std::cin >> choixStarteur;
    std::cout << "Très bien tu as choisie Tiplouf" << std::endl;
    std::cout << "Voici ton premier combat contre Griknot (Il ne fais que les attaque les plus faibles" << std::endl;
    Pokemon Tiplouf, Griknot;
    Tiplouf.creationPokemon(393);
    Griknot.creationPokemon(443);

    Combat premierCombat(Tiplouf, Griknot);
    premierCombat.fighting();
    //delete premierCombat;

    std::cout << "Très bien tu as battue ton premier pokemon, pour te felicite je te heal" << std::endl;
    std::cout << Tiplouf.getPv() << std::endl;
    Tiplouf.healMax();
    system("pause");
    std::cout << Tiplouf.getPv() << std::endl;
    std::cout << "Voici ton deuxième combat contre RozBouton (Il ne fais que les attaque les plus faibles)" << std::endl;
    Pokemon Rozbouton;
    Rozbouton.creationPokemon(406);

    Combat deuxiemeCombat(Tiplouf, Rozbouton);
    deuxiemeCombat.fighting();
    //delete premierCombat;

    
    return 0;
}

//Créer une petit IA qui voit choisir quelle attaque faire
//Créer les réstance et faiblesse