#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(500,500), "SFML works!", sf::Style::Default);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
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
                    sprite.move(0.f, -6.f);
                }
                if (event.key.code == sf::Keyboard::S)
                {
                    sprite.move(0.f, 6.f);
                }
                if (event.key.code == sf::Keyboard::Q)
                {
                    sprite.move(-6.f, 0.f);
                }
                if (event.key.code == sf::Keyboard::D)
                {
                    sprite.move(6.f, 0.f);
                }
            }
        }
        window.clear();
        window.draw(character);
        window.draw(sprite);
        window.display();
    }
    return 0;
}