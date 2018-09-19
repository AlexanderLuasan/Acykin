#pragma once
#include <allegro5/allegro.h>
#include "Rect.h"

class display
{
public:
	display(int sizex, int sizey);
	ALLEGRO_DISPLAY *getScreen();
	void clear();
	void flip();
	void draw(rect shape);
	void draw(ALLEGRO_BITMAP *image, rect box);

private:
	ALLEGRO_DISPLAY * screen;
	

};
