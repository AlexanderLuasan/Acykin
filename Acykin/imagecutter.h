#pragma once
#include "allegro5/allegro.h"
#include <string>
#include "Rect.h"
using namespace std;



class spritesheet
{
public:
	spritesheet();
	spritesheet(const char * filename,int w,int h);
	ALLEGRO_BITMAP *getFrame(int x, int y);


private:
	int width, height;
	ALLEGRO_BITMAP *sheet;


};


class plate
{
public:
	plate();
	plate(int width, int height);
	void placeshape(ALLEGRO_BITMAP * shape, rect box);
	ALLEGRO_BITMAP * getI();

private:
	ALLEGRO_BITMAP * image;
};

