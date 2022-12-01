#include "Gui.h"

//Button===================================================================

gui::Button::Button(float x, float y, float width, float height,
	sf::Font font, std::string text, float text_size,
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor, 
	short unsigned id)
{
	this->buttonState = BTN_IDLE;
	this->id = id;
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

const std::string gui::Button::getText() const
{
	return this->text.getString();
}

const short unsigned& gui::Button::getId() const
{
	return this->id;
}

void gui::Button::setText(const std::string text)
{
	this->text.setString(text);
}

void gui::Button::setId(const short unsigned id)
{
	this->id = id;
}


//Functions
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

gui::DropDownList::DropDownList(std::string titleddl, float x, float y, float width, float height,
	sf::Font* font, std::string list[], float text_size,
	unsigned nrOfElements, unsigned default_index)
	:titleddl(titleddl), font(font), showList(false), waitMax(1.f), wait(0.f)
{
	
	for (size_t i = 0; i < nrOfElements; i++)
	{
		this->list.push_back(
			new gui::Button(x, (y + height * i), width, height,
				*this->font, list[i], text_size,
				sf::Color(0, 0, 0, 255),
				sf::Color(150, 150, 150, 255),
				sf::Color(20, 20, 20, 200),
				i
			)
		);
	}

	this->Selected = new gui::Button(x - width, y, width, height,
		*this->font,this->titleddl + list[default_index], text_size,
		sf::Color(0, 0, 0, 255),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200),
		default_index
	);



}

gui::DropDownList::~DropDownList()
{
	delete this->Selected;
	for (auto& i : this->list)
		delete i;
}


//Accessors

//for blocking spam
const bool gui::DropDownList::getWait()
{
	if (this->wait >= this->waitMax)
	{
		this->wait = 0.f;
		return true;
	}
	return false;
}

const unsigned short& gui::DropDownList::getSelectedId() const
{
	return this->Selected->getId();
}

void gui::DropDownList::updateWait(const float& dt)
{
	if (this->wait <= this->waitMax)
		this->wait += 10 * dt;
	
}

//Show and hide the list

void gui::DropDownList::update(const sf::Vector2f & mousePos, const float& dt)
{
	this->updateWait(dt);
	this->Selected->update(mousePos);

	if (this->Selected->isPressed() && this->getWait())
	{
		if (this->showList)
			this->showList = false;
		else
			this->showList = true;
	}
	if (this->showList)
	{
		for (auto& i : this->list)
		{
			i->update(mousePos);
			if (i->isPressed() && this->getWait())
			{
				this->showList = false;
				this->Selected->setText(this->titleddl + i->getText());
				this->Selected->setId(i->getId());
			}
		}
	}

	
}

void gui::DropDownList::render(sf::RenderTarget* target)
{
	this->Selected->render(target);
	if (this->showList)
	{
		for (auto& i : this->list)
		{
			i->render(target);
		}
	}
}



gui::LifeBarBox::~LifeBarBox()
{

}
