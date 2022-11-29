#include "Gui.h"

//Button===================================================================

gui::Button::Button(float x, float y, float width, float height,
	sf::Font font, std::string text, float text_size,
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	this->buttonState = BTN_IDLE;

	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	this->font = font;
	this->text.setFont(this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(text_size);
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height ) / 2.f - this->text.getGlobalBounds().height / 2.f
	);

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->shape.setFillColor(this->idleColor);

}

gui::Button::~Button()
{

}

//Accessor
const bool gui::Button::isPressed() const
{
	if (this->buttonState == BTN_ACTIVE)
	{
		return true;
	}
	return false;
}

const std::string& gui::Button::getText() const
{
	return this->text.getString();
}

void gui::Button::setText(const std::string text)
{
	this->text.setString(text);
}


//Functios
void gui::Button::update(const sf::Vector2f mousePos)
{
	/*Update for hover and pressed*/
	//Idle
	this->buttonState = BTN_IDLE;

	//Hover
	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->buttonState = BTN_HOVER;

		//Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonState = BTN_ACTIVE;
		}
	}

	switch (this->buttonState)
	{
	case BTN_IDLE :
		this->shape.setFillColor(this->idleColor);
		break;

	case BTN_HOVER:
		this->shape.setFillColor(this->hoverColor);
		break;

	case BTN_ACTIVE:
		this->shape.setFillColor(this->activeColor);
		break;

	default:
		this->shape.setFillColor(sf::Color::Red);
		break;
	}

}

void gui::Button::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->text);
}
//==========================================================
// 
//Drop down list============================================

gui::DropDownList::DropDownList(sf::RenderWindow& window, float scale, sf::Font* font, std::string list[], unsigned nrOfElements, unsigned default_index)
	:font(font)
{

	for (size_t i = 0; i < nrOfElements; i++)
	{
		this->list.push_back(
			new gui::Button((window.getSize().x / 2) - 150 * scale, (window.getSize().y / 2) - 400 * scale, 300 * scale, 50 * scale,
				*this->font, list[i], 20 * scale,
				sf::Color(70, 70, 70, 200),
				sf::Color(150, 150, 150, 255),
				sf::Color(20, 20, 20, 200)
			)
		);
	}

	this->Selected = new Button(*this->list[default_index]);


}

gui::DropDownList::~DropDownList()
{
	delete this->Selected;
	for (auto& i : this->list)
		delete i;
}

void gui::DropDownList::update(const sf::Vector2f mousePos)
{
}

void gui::DropDownList::render(sf::RenderTarget* target)
{
}
