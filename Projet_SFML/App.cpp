#include "App.h"

sf::RenderWindow App::window;

void App::init(int x,int y,std::string title) {
	window.create(sf::VideoMode(x, y), title, sf::Style::Default);

}

void App::quit()
{
	window.close();
}

void App::event()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            App::quit();

        if (event.type == sf::Event::TextEntered)
        {
            if (event.text.unicode < 128)
                std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
        }

        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                std::cout << "the escape key was pressed" << std::endl;
                std::cout << "control:" << event.key.control << std::endl;
                std::cout << "alt:" << event.key.alt << std::endl;
                std::cout << "shift:" << event.key.shift << std::endl;
                std::cout << "system:" << event.key.system << std::endl;
            }
        }

        if (event.type == sf::Event::MouseWheelScrolled)
        {
            if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
                std::cout << "wheel type: vertical" << std::endl;
            else if (event.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel)
                std::cout << "wheel type: horizontal" << std::endl;
            else
                std::cout << "wheel type: unknown" << std::endl;
            std::cout << "wheel movement: " << event.mouseWheelScroll.delta << std::endl;
            std::cout << "mouse x: " << event.mouseWheelScroll.x << std::endl;
            std::cout << "mouse y: " << event.mouseWheelScroll.y << std::endl;
        }

        if (event.type == sf::Event::MouseButtonPressed)
        {
            std::cout << "the mouse button was pressed :" << event.mouseButton.button << std::endl;
            std::cout << "mouse x: " << event.mouseButton.x << std::endl;
            std::cout << "mouse y: " << event.mouseButton.y << std::endl;
        }

        if (event.type == sf::Event::MouseMoved)
        {
            std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
            std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
        }

        if (event.type == sf::Event::MouseEntered)
            std::cout << "the mouse cursor has entered the window" << std::endl;

        if (event.type == sf::Event::MouseLeft)
            std::cout << "the mouse cursor has left the window" << std::endl;
    }

}
