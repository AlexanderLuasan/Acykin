#include "player.h"
#include "Rect.h"
#include <string>
#include <iostream>
using namespace std;


player::player(string n, rect box) {
	name = n;
	hitbox = box;
	drawing = box;
	xaim = 1;
}
player::player() {
	name = "Acykin";
	hitbox = rect(0, 0, 10, 10);
	drawing = rect(0, 0, 10, 10);
	xaim = 1;
}

void player::setHorizonal(int direction)
{
	if (direction == 0) {
		xaim = 0;
	}
	else {
		xaim = direction / abs(direction);
	}
	
}

void player::setVertical(int direction)
{
	if (direction == 0) {
		yaim = 0;
	}
	else {
		yaim = direction / abs(direction);
	}

}

void player::setJump(bool jumping)
{
	this->jumping = jumping;
}

rect player::getHit()
{
	return hitbox;
}

rect player::getDraw()
{
	return drawing;
}

void player::collision(rect other, string name)
{

	//no implmentation

	cout << "colision" << endl;
}

void player::update() {
	hitbox.setx(hitbox.getx() + xaim);
	cout << hitbox.getx() << endl;//need movemnet programing


}

