#include "Player.h"

Player::Player() :Entity(20, 0, false, 1.2)
{
	//sf::IntRect playerRectangle(0,0 10, 16);
	this->setTexture(textures->playerIdleDown);
	this->healthSprite.setTexture(textures->healthSpriteTexture);
	this->healthSprite.setTextureRect(sf::IntRect (0, 0, 25, 7));
	this->hasKey = false;
	int curDirection = 0; // 0 is down, 1 is up, 2 is right, 3 is left
	knife = new Node(SWORD);
	knife->setPosition(-10,10);
}

Player::~Player()
{

}

void Player::eightWayMovement(double time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) // up
	{
		this->setTexture(textures->playerMoveUp);
		move((3 * PI)/2);
		this->curDirection = 1;
		if (time > 1.0)
		{
			//if ()
			//{

			//}
			//else
			//{

			//}
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) // down
	{
		this->setTexture(textures->playerMoveDown);
		move(PI/2);
		this->curDirection = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // left
	{
		this->setTexture(textures->playerMoveLeft);
		move(PI);
		this->curDirection = 3;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // right
	{
		this->setTexture(textures->playerMoveRight);
		move(0);
		this->curDirection = 2;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // up-left
	{
		this->setTexture(textures->playerMoveLeft);
		move(PI/4);
		this->curDirection = 3;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // up-right
	{
		this->setTexture(textures->playerMoveRight);
		move((3 * PI) / 4);
		this->curDirection = 2;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // down-left
	{
		this->setTexture(textures->playerMoveLeft);
		move((3 * PI) / 4);
		this->curDirection = 3;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // down-right
	{
		this->setTexture(textures->playerMoveRight);
		move((5 * PI) / 4);
		this->curDirection = 2;
	}
	knife->setPosition(-10, 10);
}

void Player::drawGUI(sf::RenderWindow &window)
{
	window.draw(healthSprite);
}

void Player::updateHealth()
{
	healthSprite.setPosition(this->getPosition().x - 12.5, this->getPosition().y - 16);

	if (this->health > 40)
	{
		healthSprite.setTextureRect(sf::IntRect(0, 0, 25, 7));
	}
	else if (this->health > 20)
	{
		healthSprite.setTextureRect(sf::IntRect(0, 7, 25, 7));
	}
	else if (this->health > 0)
	{
		healthSprite.setTextureRect(sf::IntRect(0, 14, 25, 7));
	}
	else
	{
		this->is_dead();
	}
}

void Player::updateKey()
{
	
}

void Player::attack()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (this->curDirection == 0) // face down
		{
			knife->setRotation(180.f);
			knife->setPosition(this->getPosition().x, this->getPosition().y + 10);
		}
		else if (this->curDirection == 1) // face up
		{
			knife->setRotation(0.f);
			knife->setPosition(this->getPosition().x, this->getPosition().y - 10);
		}
		else if (this->curDirection == 3) // face left
		{
			knife->setRotation(90.f);
			knife->setPosition(this->getPosition().x - 5, this->getPosition().y);
		}
		else if (this->curDirection == 2) // face right
		{
			knife->setRotation(270.f);
			knife->setPosition(this->getPosition().x + 5, this->getPosition().y);
		}
		knife->setRotation(0.f);
		knife->setPosition(-10, 10);
	}
}

void Player::update(double time)
{
	eightWayMovement(time);
	updateHealth();
	updateKey();
}

bool Player::getKey()
{
	if(hasKey) {
		hasKey = false;
		return true;
	}
	return false;
}