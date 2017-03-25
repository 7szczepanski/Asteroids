#include "Ship.h"
#include <iostream>

using namespace std;



Ship::Ship()
{
	CircleShape triangle(80, 3);
	warship = triangle;
	warship.setOrigin(warship.getRadius(),warship.getRadius());
}


Ship::~Ship()
{
}

void Ship::show(RenderWindow &target_) {
	target_.draw(warship);
}

void Ship::update() {
	this->position += this->velocity;
	this->velocity += this->acceleration;
	warship.setPosition(this->position);
	this->acceleration = this->acceleration * 0.f;
}

void Ship::rotate(float ang) {
	warship.setRotation(ang);
	this->heading += this->warship.getRotation();
}

void Ship::setAcc(Vector2f xy){
	acceleration = xy;
}

void Ship::setPosition(float x_, float y_) {
	position.x = x_;
	position.y = y_;
}
void Ship::edges(int w, int h) {
	if (warship.getPosition().x > w) { this->setPosition(0, warship.getPosition().y); }
	if (warship.getPosition().y > h) { this->setPosition(warship.getPosition().x, 0); }
	if (warship.getPosition().x < 0) { this->setPosition(w, warship.getPosition().y); }
	if (warship.getPosition().y < 0) { this->setPosition(warship.getPosition().x, h); }
	
}