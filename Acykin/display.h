#pragma once
#include <allegro5/allegro.h>
#include "Rect.h"
#include "imagecutter.h"

class display
{
public:
	display(int sizex, int sizey);//start a screen with given size
	ALLEGRO_DISPLAY *getScreen();//return display pointer
	void clear(); //set screen to white
	void flip(); // change display to buffer
	void draw(rect shape); // draw a rect as black box
	void draw(ALLEGRO_BITMAP *image, rect box); //draw a bitmap image in rect
	void draw(plate bg);//draw a full plate backgounrd

private:
	ALLEGRO_DISPLAY * screen; 
	

};
