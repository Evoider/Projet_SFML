#include "Entity.h"

Entity::Entity()
{
	this->texture.loadFromFile("Ressources/Sprites/cynthia_final.png");
	this->sprite.setTexture(texture);

	this->compteurAnimUp = 0;
	this->compteurAnimDown = 0;
	this->compteurAnimLeft = 0;
	this->compteurAnimRight = 0;

	this->Up = sf::IntRect(0, 0, 32, 32);
	this->Up1 = sf::IntRect(32, 94, 32, 32);
	this->Up2 = sf::IntRect(64, 0, 32, 32);
	this->Down = sf::IntRect(64, 32, 32, 32);
	this->Down1 = sf::IntRect(64, 64, 32, 32);
	this->Down2 = sf::IntRect(64, 96, 32, 32);
	this->Left = sf::IntRect(0, 64, 32, 32);
	this->Left1 = sf::IntRect(0, 96, 32, 32);
	this->Left2 = sf::IntRect(0, 32, 32, 32);
	this->Right = sf::IntRect(32, 0, 32, 32);
	this->Right1 = sf::IntRect(32, 32, 32, 32);
	this->Right2 = sf::IntRect(32, 64, 32, 32);


	this->sprite.setTextureRect(Up);
	this->sprite.scale(3, 3);
	this->movementSpeed = 0.2f;

	this->posX = 12.75;
	this->posY = 8.5;

	this->offSetX = 64;
	this->offSetY = 64;

	this->sprite.setPosition(posX * offSetX, posY * offSetY);
}

Entity::~Entity()
{
}


void Entity::move(std::string direction, sf::View& view)
{
	if (dtclock.getElapsedTime().asSeconds() > this->movementSpeed) {
		if (direction == "Up")
		{
			//Mouvement
			posY -= 0.5;
			sprite.setPosition(posX * offSetX, posY * offSetY);

			//Animation
			if (compteurAnimUp == 0)
			{
				this->sprite.setTextureRect(Up);
			}
			else if (compteurAnimUp == 1)
			{
				this->sprite.setTextureRect(Up1);
			}
			else if (compteurAnimUp == 2)
			{
				this->sprite.setTextureRect(Up);
			}
			else if (compteurAnimUp == 3)
			{
				this->sprite.setTextureRect(Up2);
			}

			compteurAnimUp++;
			if (compteurAnimUp >= 4)
			{
				compteurAnimUp = 0;
			}

			//Vue
			/*view.setCenter(view.getCenter().x, view.getCenter().y - (0.5 * offSetY));*/
		}
		else if (direction == "Down")
		{
			//Mouvement
			posY += 0.5;
			sprite.setPosition(posX * offSetX, posY * offSetY);

			//Animation
			if (compteurAnimDown == 0)
			{
				this->sprite.setTextureRect(Down);
			}
			else if (compteurAnimDown == 1)
			{
				this->sprite.setTextureRect(Down1);
			}
			else if (compteurAnimDown == 2)
			{
				this->sprite.setTextureRect(Down);
			}
			else if (compteurAnimDown == 3)
			{
				this->sprite.setTextureRect(Down2);
			}

			compteurAnimDown++;
			if (compteurAnimDown >= 4)
			{
				compteurAnimDown = 0;
			}

			////Vue
			//view.setCenter(view.getCenter().x, view.getCenter().y + (0.5 * offSetY));
		}
		else if (direction == "Left")
		{
			//Mouvement
			posX -= 0.5;
			sprite.setPosition(posX * offSetX, posY * offSetY);

			//Animation
			if (compteurAnimLeft == 0)
			{
				this->sprite.setTextureRect(Left);
			}
			else if (compteurAnimLeft == 1)
			{
				this->sprite.setTextureRect(Left1);
			}
			else if (compteurAnimLeft == 2)
			{
				this->sprite.setTextureRect(Left);
			}
			else if (compteurAnimLeft == 3)
			{
				this->sprite.setTextureRect(Left2);
			}

			compteurAnimLeft++;
			if (compteurAnimLeft >= 4)
			{
				compteurAnimLeft = 0;
			}

			////Vue
			//view.setCenter(view.getCenter().x - (0.5 * offSetX), view.getCenter().y);
		}
		else if (direction == "Right")
		{
			//Mouvement
			posX += 0.5;
			sprite.setPosition(posX * offSetX, posY * offSetY);

			//Animation
			if (compteurAnimRight == 0)
			{
				this->sprite.setTextureRect(Right);
			}
			else if (compteurAnimRight == 1)
			{
				this->sprite.setTextureRect(Right1);
			}
			else if (compteurAnimRight == 2)
			{
				this->sprite.setTextureRect(Right);
			}
			else if (compteurAnimRight == 3)
			{
				this->sprite.setTextureRect(Right2);
			}

			compteurAnimRight++;
			if (compteurAnimRight >= 4)
			{
				compteurAnimRight = 0;
			}

			////Vue
			//view.setCenter(view.getCenter().x + (0.5 * offSetX), view.getCenter().y);
		}
		view.setCenter(posX * 64 + 32, posY * 64 + 64);
		dtclock.restart();
	}
}



void Entity::update(const float& dt)
{

}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}


int Entity::getPositionX()
{
	return posX;
}

int Entity::getPositionY()
{
	return posY;
}