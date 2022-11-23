#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("Best_Pokemon.ogg"))
    {
        std::cout << "Oh no the pokemon is broken";
    }

    sf::Sound cri;
    cri.setBuffer(buffer);

    sf::Music music;
    if (!music.openFromFile("centre.wav"))
    {
        std::cout<< "Vous n'etes pas a l'hopital awai";
    }
    music.play();
    music.setLoop(true);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::R)
                {
                    cri.play();
                }
            }
        }
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}