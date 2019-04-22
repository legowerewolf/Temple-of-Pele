#pragma once

#include "Entity.h"
#include "textures.h"

#include <iostream>

class Enemy : public Entity {
public:
	Enemy() : Entity() {
		setTexture(textures->Enemy1Gif);
		set_isHazard(true);
		maxFrames = 6;
		curFrame = 1;
		lastTime = 0.0;
	}
	~Enemy() {}

	void update(double time) {
		float playerAngle = atan( // This enemy is 1, player is 2.
			(-playerPos.y + getPosition().y)/
			(playerPos.x - getPosition().x)
		) + (getPosition().x > playerPos.x ? PI : 0);
		
		animateEnemy(time);
		//std::cout << playerAngle << std::endl;
		move(playerAngle, 0.005);
	}

	void collide(Node &object) {
		if (object.get_layer() == SWORD)
		{
			//modify_health(-20);
		}
	};

	void animateEnemy(double time) {
		animateTime(time);
		switch (curFrame)
		{
		case 1:
			setTextureRect(sf::IntRect(0, 0, 10, 16));
			break;
		case 2:
			setTextureRect(sf::IntRect(10, 0, 10, 16));
			break;
		case 3:
			setTextureRect(sf::IntRect(20, 0, 10, 16));
			break;
		case 4:
			setTextureRect(sf::IntRect(0, 16, 10, 16));
			break;
		case 5:
			setTextureRect(sf::IntRect(10, 16, 10, 16));
			break;
		case 6:
			setTextureRect(sf::IntRect(20, 16, 10, 16));
			break;
		}
	};
	
	void animateTime(double time)
	{
		if (time - lastTime >= 0.1)
		{
			lastTime = time;
			curFrame++;
			if (curFrame == 6)
			{
				curFrame = 1;
			}
		}
	}

private:
	int maxFrames;
	int curFrame;
	double lastTime;
};