#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;

class Ship
{
public:
	Ship();
	~Ship();
	sf::CircleShape warship;

	float heading;

	void update();
	void show(RenderWindow &);
	void rotate(float);
	void setAcc(Vector2f );
	void setPosition(float, float);
	void edges(int, int);
protected:
	Vector2f position;
	Vector2f velocity;
	Vector2f acceleration;
};

