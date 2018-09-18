#pragma once
#include <string>
#include "Rect.h"
using namespace std;
class player
{
public:
	player(string n, rect box);
	player();

private:
	string name;
	rect hitbox;
	rect drawing;

};
