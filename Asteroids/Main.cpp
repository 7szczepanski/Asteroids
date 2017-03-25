#include <SFML/Graphics.hpp>
#include "Ship.h"
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>


int width = 800;
int height = 800;

using namespace sf;
using namespace std;

Vector2<float> normalize(const Vector2<float>& source)
{
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	if (length != 0)
		return Vector2<float>(source.x / length, source.y / length);
	else
		return source;
}

float heading(Vector2f v) {
//	float angle = atan2(-v.y,v.x)
	return atan2(v.x, v.y);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(width, height), "Asteroids!");
	sf::RectangleShape background(Vector2f(width, height));
	background.setFillColor(sf::Color(51,51,51));
	Ship ship;
	float angle = 0;
	float ang;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(background);
		ship.update();
		ship.edges(width, height);
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			angle += -0.1;
			ship.rotate(angle + M_PI / 2);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			angle += 0.1;
			ship.rotate(angle+M_PI/2);
			
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {

			ang = ship.warship.getRotation();
			ang = (ang*M_PI) / 180;
			float speed = 0.001;
			
			Vector2f acc;
			acc.x = sin(ship.heading)/1000;
			acc.y = cos(ship.heading)/1000;
			cout << "X : " << acc.x << " Y : " << acc.y << endl;
			ship.setAcc(acc);
		}

		ship.show(window);
		
		window.display();
	}

	return 0;
}