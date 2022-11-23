#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"
#include "Character.h"

bool up = false;
bool down = false;
bool left = false;
bool right = false;


int main()
{
    sf::RenderWindow window(sf::VideoMode(500,500), "SFML works!", sf::Style::Default);
    sf::Texture texture;
    texture.loadFromFile("ressources/sprites/pika_pika.png");
    sf::Sprite sprite;
    sprite.scale(sf::Vector2f(1.f, 1.f)); // facters d'échelle relatifs à l'échelle actuelle
    sprite.setTexture(texture);

    sf::Texture texture2;
    texture2.loadFromFile("ressources/sprites/gravity_falls.png");
    sf::Sprite character;
    character.scale(sf::Vector2f(1.f, 1.f)); // facters d'échelle relatifs à l'échelle actuelle
    character.setTexture(texture2);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Z)
                {
                    up = true;

                    down = false;
                    left = false;
                    right = false;
                }
                if (event.key.code == sf::Keyboard::S)
                {
                    down = true;

                    up = false;
                    left = false;
                    right = false;
                }
                if (event.key.code == sf::Keyboard::Q)
                {
                    left = true;

                    up = false;
                    down = false;
                    right = false;
                }
                if (event.key.code == sf::Keyboard::D)
                {

                    right = true;

                    up = false;
                    down = false;
                    left = false;
                }
            }
            if (event.type == sf::Event::KeyReleased)
            {
                up = false;
                down = false;
                left = false;
                right = false;
            }
            
        }
        //Action
        if (up == true)
        {
            sprite.move(0.f, -0.1f);
        }
            
        if (down == true)
        {
            sprite.move(0.f, 0.1f);
        }
            
        if (left == true)
        {
            sprite.move(-0.1f, 0.f);
        }

        if (right == true)
        {
            sprite.move(0.1f, 0.f);
        }


        window.clear();
        window.draw(character);
        window.draw(sprite);
        window.display();
    }
    return 0;
}