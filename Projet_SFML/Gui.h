#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <sstream>


enum button_state { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };

namespace gui
{
	class Button
	{
	private:
		short unsigned buttonState;

		sf::RectangleShape shape;
		sf::Font font;
		sf::Text text;

		sf::Color idleColor;
		sf::Color hoverColor;
		sf::Color activeColor;


	public:
		Button(float x, float y, float width, float height,
			sf::Font font, std::string text, float text_size,
			sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
		~Button();

		//Accessor
		const bool isPressed() const;
		const std::string& getText() const;

		//Modifier
		void setText(const std::string text);

		//Functions
		void update(const sf::Vector2f mousePos);
		void render(sf::RenderTarget* target);

	};

	class DropDownList
	{
	
	private:
		sf::Font* font;
		gui::Button* Selected;
		std::vector<gui::Button*> list;

	public:
		DropDownList(sf::RenderWindow& window, float scale, sf::Font* font, std::string list[], unsigned nrOfElements, unsigned default_index = 0);
		~DropDownList();

		//Functions
		void update(const sf::Vector2f mousePos);
		void render(sf::RenderTarget* target);

	};

	

}

