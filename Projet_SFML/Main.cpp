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

int posx = 0;
int posy = 0;


int main()
{
    sf::RenderWindow window(sf::VideoMode(1000,600), "SFML works!", sf::Style::Default);

    // on crée une vue
    sf::View view;
    view.reset(sf::FloatRect(0, 0, 1000, 600));

    // on l'active
    window.setView(view);
    sf::Texture texture;
    texture.loadFromFile("ressources/sprites/pika_pika.png");
    sf::Sprite sprite;
    sprite.scale(sf::Vector2f(1, 1)); // facters d'échelle relatifs à l'échelle actuelle
    sprite.setTexture(texture);
    sprite.setPosition(500, 300);

    sf::Texture texture2;
    texture2.loadFromFile("ressources/sprites/maps_test.png");
    sf::Sprite character;
    character.scale(sf::Vector2f(2.f, 2.f)); // facters d'échelle relatifs à l'échelle actuelle²²²
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
            view.move(0.f, -0.1f);
            posy++;
        }
            
        if (down == true)
        {
            sprite.move(0.f, 0.1f);
            view.move(0.f, 0.1f);
            posy--;
        }
            
        if (left == true)
        {
            sprite.move(-0.1f, 0.f);
            view.move(-0.1f, 0.f);
            posx--;
        }

        if (right == true)
        {
            sprite.move(0.1f, 0.f);
            view.move(0.1f, 0.f);
            posx++;
        }


        window.clear();
        window.setView(view);
        window.draw(character);
        window.draw(sprite);
        window.display();
    }
    return 0;
}

//Hit-box (colision)
// Combat tour-par-tour
//Architecture