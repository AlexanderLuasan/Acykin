#pragma once
/*

game is the  global stuff like the player and score

room is temorary rests and can be loaded again and again

*/
#include "player.h"
#include "wall.h"
#include <vector>
using namespace std;

class room
{
public:
	room(vector<wall> w);
	room();
	vector<wall> getWalls();

private:
	vector<wall> walls;

};

class game
{
public:
	game(room r , player h);
	vector<wall> getCurrentWalls();
	void updateplayer();

private:
	room currentroom;

public:
	player hero;
};




