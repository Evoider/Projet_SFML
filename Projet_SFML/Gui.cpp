#include "Gui.h"

//Button===================================================================

gui::Button::Button(float x, float y, float width, float height,
	sf::Font font, std::string text, float text_size,
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor, sf::Color outlineColor, float outlineThick,
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
	this->outlineColor = outlineColor;
	this->outlineThick = outlineThick;

	this->shape.setFillColor(this->idleColor);
	this->shape.setOutlineColor(this->outlineColor);
	this->shape.setOutlineThickness(this->outlineThick);

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
	sf::Font* font, std::string list[], float text_size, sf::Color outlineColor, float outlineThick,
	unsigned nrOfElements, unsigned default_index)
	:titleddl(titleddl), font(font), showList(false), waitMax(2.f), wait(0.f)
{
	
	for (size_t i = 0; i < nrOfElements; i++)
	{
		this->list.push_back(
			new gui::Button(x, (y + height * i), width, height,
				*this->font, list[i], text_size,
				sf::Color(0, 0, 0, 255),
				sf::Color(150, 150, 150, 255),
				sf::Color(20, 20, 20, 200),
				sf::Color(0, 0, 235, 255), outlineThick,
				i
			)
		);
	}

	this->Selected = new gui::Button(x - width, y, width, height,
		*this->font,this->titleddl + list[default_index], text_size,
		sf::Color(0, 0, 0, 255),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200),
		sf::Color(0, 0, 235, 255), outlineThick, 
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

//===========================================================================================

//Life Bar Box===============================================================================

gui::LifeBarBox::LifeBarBox(float x, float y, float width, float height,
	sf::Font font, std::string nom,	int lvl, int pv, float text_size,
	sf::Color backBoxColor, sf::Color lifeColor, sf::Color outlineColor, float outlineThick)
	:showPV(false)
{
	//set position of the whole box
	this->backBox.setPosition(sf::Vector2f(x, y));
	this->backBox.setSize(sf::Vector2f(width, height));
	//set position of the life Bar
	this->LifeBarContainer.setPosition(
		this->backBox.getPosition().x + 4.5 * (this->backBox.getGlobalBounds().width / 10.f),
		this->backBox.getPosition().y + this->backBox.getGlobalBounds().height / 2.f
	);
	this->LifeBarContainer.setSize(sf::Vector2f(4.5 * (width / 10), height / 10));
	this->LifeBar.setPosition(
		this->backBox.getPosition().x + 5 * (this->backBox.getGlobalBounds().width / 10.f),
		this->backBox.getPosition().y + this->backBox.getGlobalBounds().height / 2.f
	);
	this->LifeBar.setSize(sf::Vector2f(4 * (width / 10), height / 10));

	//initialize/set the position of the various texts
	this->font = font;
	//nom
	this->nom.setFont(this->font);
	this->nom.setString(nom);
	this->nom.setFillColor(sf::Color::Black);
	this->nom.setCharacterSize(text_size);
	this->nom.setPosition(
		this->backBox.getPosition().x + (this->backBox.getGlobalBounds().width / 30.f) ,
		this->backBox.getPosition().y + (2 * (this->backBox.getGlobalBounds().height) / 10.f) - this->nom.getGlobalBounds().height / 2.f
	);

	//PV
	this->pvMax = pv;
	this->life.setFont(this->font);
	this->life.setString("PV");
	this->life.setFillColor(sf::Color::Red);
	this->life.setCharacterSize(text_size / 4);
	this->life.setPosition(
		this->LifeBarContainer.getPosition().x + (this->LifeBarContainer.getGlobalBounds().width / 30.f),
		this->LifeBarContainer.getPosition().y + (this->LifeBarContainer.getGlobalBounds().height) / 2.f - this->life.getGlobalBounds().height / 2.f
	);

	
	this->textLife.setFont(this->font);
	this->textLife.setString(std::to_string(pv)+"/"+std::to_string(this->pvMax));
	this->textLife.setFillColor(sf::Color::Black);
	this->textLife.setCharacterSize(text_size / 1.5);
	this->textLife.setPosition(
		this->backBox.getPosition().x + 6 * (this->backBox.getGlobalBounds().width / 10.f),
		this->backBox.getPosition().y + (8 * (this->backBox.getGlobalBounds().height) / 10.f) - this->textLife.getGlobalBounds().height / 2.f
	);
	

	//level
	this->lvl = lvl;

	this->level.setFont(this->font);
	this->level.setString("Lv : " + std::to_string(lvl));
	this->level.setFillColor(sf::Color::White);
	this->level.setCharacterSize(text_size/2);
	this->level.setPosition(
		this->backBox.getPosition().x + 6 * (this->backBox.getGlobalBounds().width / 10.f),
		this->backBox.getPosition().y + (2 * (this->backBox.getGlobalBounds().height) / 10.f) - this->level.getGlobalBounds().height / 2.f
	);




	this->backBoxColor = backBoxColor;
	this->lifeColor = lifeColor;
	this->outlineColor = outlineColor;
	this->outlineThick = outlineThick;

	this->backBox.setFillColor(this->backBoxColor);
	this->LifeBar.setFillColor(this->lifeColor);
	this->LifeBarContainer.setFillColor(sf::Color(0, 0, 0, 0));
	this->LifeBarContainer.setOutlineColor(this->outlineColor);
	this->LifeBarContainer.setOutlineThickness(this->outlineThick);

}

gui::LifeBarBox::~LifeBarBox()
{

}

void gui::LifeBarBox::setLife(int pv)
{
	this->textLife.setString(std::to_string(pv) + "/" + std::to_string(this->pvMax));
	float width = this->LifeBarContainer.getSize().x - 0.5 * (this->backBox.getGlobalBounds().width / 10.f);
	std::cout << width << '\n';
	std::cout << width * (static_cast<float>(pv) / this->pvMax) << '\n';
	float height = this->LifeBarContainer.getSize().y;
	this->LifeBar.setSize(sf::Vector2f(width * (static_cast<float>(pv) / this->pvMax), height));
}

void gui::LifeBarBox::showTextLife()
{
	this->showPV = true;
}

void gui::LifeBarBox::update(const sf::Vector2f mousePos)
{

}

void gui::LifeBarBox::render(sf::RenderTarget* target)
{
	target->draw(this->backBox);

	target->draw(this->nom);
	if(showPV)
		target->draw(this->textLife);
	target->draw(this->level);
	target->draw(this->LifeBar);
	target->draw(this->LifeBarContainer);
	target->draw(this->life);
}
