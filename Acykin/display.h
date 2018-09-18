#pragma once
#include <allegro5/allegro.h>


class display
{
public:
	display(int sizex, int sizey);
	ALLEGRO_DISPLAY *getScreen();


private:
	ALLEGRO_DISPLAY * screen;
	

};
