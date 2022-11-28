#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include "Entity.h"
#include "Character.h"

bool up = false;
bool down = false;
bool left = false;
bool right = false;

std::string preMove;

float posx = 0;
float posy = 0;


int main()
{
    sf::RenderWindow window(sf::VideoMode(1000,600), "SFML works!", sf::Style::Default);

    // on crée une vue
    sf::View view;
    view.reset(sf::FloatRect(0, 0, 1000, 600));
    window.setView(view);

    sf::Texture texture;
    texture.loadFromFile("ressources/sprites/cynthia_sprite.png");
    sf::IntRect rectSpriteUp(0, 195, 75, 75);
    sf::IntRect rectSpriteDown(0, 0, 75, 75);
    sf::IntRect rectSpriteLeft(0, 75, 75, 75);
    sf::IntRect rectSpriteRight(0, 150, 75, 75);
    sf::Sprite sprite(texture, rectSpriteDown);
    sprite.setPosition(500, 300);
    //sprite.scale(sf::Vector2f(1, 1)); facters d'échelle relatifs à l'échelle actuelle
    
    //Vitesse
    float speed=0.045;
    sf::Texture texture2;
    texture2.loadFromFile("ressources/sprites/maps_test.png");
    sf::Sprite character;
    character.scale(sf::Vector2f(2.f, 2.f)); // facters d'échelle relatifs à l'échelle actuelle²²²
    character.setTexture(texture2);

    sf::Clock clock;

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
                    preMove = "Up";

                    down = false;
                    left = false;
                    right = false;
                }
                if (event.key.code == sf::Keyboard::S)
                {
                    down = true;
                    preMove = "Down";

                    up = false;
                    left = false;
                    right = false;
                }
                if (event.key.code == sf::Keyboard::Q)
                {
                    left = true;
                    preMove = "Left";

                    up = false;
                    down = false;
                    right = false;
                }
                if (event.key.code == sf::Keyboard::D)
                {

                    right = true;
                    preMove = "Right";

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
            posy -= speed;
        }
            
        else if (down == true)
        {
            posy += speed;
        }
            
        else if (left == true)
        {
            posx -= speed;
        }

        else if (right == true)
        {
            posx += speed;
        }

        
        sprite.setPosition(posx, posy);
        view.setCenter(posx, posy);

        //Animataion
        if (clock.getElapsedTime().asSeconds() > 0.3f)
        {
            if (up == true)
            {
                rectSpriteUp.left += 65;
                if (rectSpriteUp.left > 195)
                {
                    rectSpriteUp.left = 0;
                }
                sprite.setTextureRect(rectSpriteUp);
            }

            else if (down == true)
            {
                rectSpriteDown.left += 65;
                if (rectSpriteDown.left > 195)
                {
                    rectSpriteDown.left = 0;
                }
                sprite.setTextureRect(rectSpriteDown);
            }

            else if (left == true)
            {
                rectSpriteLeft.left += 65;
                if (rectSpriteLeft.left > 195)
                {
                    rectSpriteLeft.left = 0;
                }
                sprite.setTextureRect(rectSpriteLeft);
            }

            else if (right == true)
            {
                rectSpriteRight.left += 65;
                if (rectSpriteRight.left > 195)
                {
                    rectSpriteRight.left = 0;
                }
                sprite.setTextureRect(rectSpriteRight);
            }
            else
            {
                if (preMove == "Up")
                {
                    rectSpriteUp.left = 0;
                    sprite.setTextureRect(rectSpriteUp);
                }
                else if (preMove == "Down")
                {
                    rectSpriteDown.left = 0;
                    sprite.setTextureRect(rectSpriteDown);
                }
                else if (preMove == "Left")
                {
                    rectSpriteLeft.left = 0;
                    sprite.setTextureRect(rectSpriteLeft);
                }
                else if (preMove == "Right")
                {
                    rectSpriteRight.left = 0;
                    sprite.setTextureRect(rectSpriteRight);
                }
            }

            clock.restart();
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
//tileset pour faire des maps soit même