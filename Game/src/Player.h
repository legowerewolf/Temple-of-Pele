#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	Player();

	~Player();

	void eightWayMovement(double time);
	void animatePlayer(double time);
	void update(double time);
	void collide(Node *object);

	void drawGUI(sf::RenderWindow &window);
	void drawView(sf::RenderWindow &window);

	void updateHealth(double time);
	bool takeDamage(double time);

	void updateKey();
	void updateTime(double time, int curFrame, int maxFrames);
	void attack();

	bool getKey();

private:
	sf::Sprite healthSprite;
	Node knife;
	sf::View viewPlayer;
	bool hasKey;
	int curDirection;
	int curMoveFrame = 0;
	double lastTime;
	bool endGame;
};
