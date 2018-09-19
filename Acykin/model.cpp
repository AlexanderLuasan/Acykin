#include "player.h"
#include "model.h"
#include "wall.h"
#include <iostream>
using namespace std;

room::room(vector<wall> w) {
	walls = w;
}
room::room() {
	//implement
	wall one(rect(1, 1, 799, 10));
	wall two(rect(1, 1, 10, 599));
	wall thr(rect(1, 589, 799, 10));
	wall four(rect(789, 1, 10, 599));
	vector<wall> wallist;

	wallist.push_back(one);
	wallist.push_back(two);
	wallist.push_back(thr);
	wallist.push_back(four);
	
	walls = wallist;

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

