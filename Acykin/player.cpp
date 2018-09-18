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

