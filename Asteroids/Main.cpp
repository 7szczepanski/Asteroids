#include <SFML/Graphics.hpp>
#include "Ship.h"
int width = 800;
int height = 800;

using namespace sf;


int main()
{
	sf::RenderWindow window(sf::VideoMode(width, height), "Asteroids!");
	sf::RectangleShape background(Vector2f(width, height));
	background.setFillColor(sf::Color(51,51,51));
	Ship ship;
	float angle = 0;
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
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			angle += -0.5;
			ship.rotate(angle);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			angle += 0.5;
			ship.rotate(angle);
			
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			float acc = 0.0001;
			ship.setAcc(acc*ship.warship.getRotation(),)
		}

		ship.show(window);
		
		window.display();
	}

	return 0;
}