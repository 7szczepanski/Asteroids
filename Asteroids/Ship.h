#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;

class Ship
{
public:
	Ship();
	~Ship();
	sf::CircleShape warship;

	void update();
	void show(RenderWindow &);
	void rotate(float);
	void setAcc(Vector2f );
protected:
	Vector2f position;
	Vector2f velocity;
	Vector2f acceleration;
	Vector2f heading;
};

