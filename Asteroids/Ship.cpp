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
	//warship.setRotation(this->heading);
	this->acceleration = this->acceleration * 0.f;
}

void Ship::rotate(float ang) {
	//this->heading = warship.getRotation();
	//this->heading = this->heading + ang;
	warship.setRotation(ang);
	cout<<warship.getRotation();
}

void Ship::setAcc(Vector2f xy){
	acceleration = xy;
}