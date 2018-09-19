#include "player.h"
#include "Rect.h"
#include <string>
using namespace std;


player::player(string n, rect box) {
	name = n;
	hitbox = box;
	drawing = box;
}
player::player() {
	name = "Acykin";
	hitbox = rect(0, 0, 10, 10);
	drawing = rect(0, 0, 10, 10);
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

