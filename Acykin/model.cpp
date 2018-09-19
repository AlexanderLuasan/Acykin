#include "player.h"
#include "model.h"
#include "wall.h"
#include <iostream>
using namespace std;

room::room(vector<wall> w) {
	walls = w;
}
room::room() {

}
vector<wall> room::getWalls()
{
	return walls;
}
game::game(room r, player h){
	hero = h;
	currentroom = r;
}

vector<wall> game::getCurrentWalls()
{
	vector<wall> end = currentroom.getWalls();

	
	return end;
}

void game::updateplayer()
{
	hero.update();
}

