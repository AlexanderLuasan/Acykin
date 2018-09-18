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

private:
	ALLEGRO_DISPLAY * screen;
	

};
