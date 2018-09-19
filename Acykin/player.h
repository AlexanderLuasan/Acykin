#pragma once
#include <string>
#include "Rect.h"
using namespace std;
class player
{
public:
	player(string n, rect box);
	player();

	void update();
	void setHorizonal(int direction);
	void setVertical(int direction);
	void setJump(bool jumping);
	rect getHit();
	rect getDraw();
	void collision(rect other, string name);//not implmented


private:
	string name;
	rect hitbox;
	rect drawing;
	int xaim;
	int yaim;
	bool jumping;
};
