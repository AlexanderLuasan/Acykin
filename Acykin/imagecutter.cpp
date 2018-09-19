#include "imagecutter.h"
#include <string>
#include <allegro5/allegro.h>
#include <iostream>
using namespace std;


spritesheet::spritesheet()
{


}

spritesheet::spritesheet(const char *filename, int w, int h)
{
	width = w;
	height = h;
	sheet = al_load_bitmap(filename);
	if (sheet == NULL) {
		cout << "help "<<endl;
	}

}

ALLEGRO_BITMAP * spritesheet::getFrame(int x, int y)
{
	ALLEGRO_BITMAP * end;
	end = al_create_sub_bitmap(this->sheet, x*width, y*height, width, height);
	return end;
}

plate::plate()
{


}

plate::plate(int width, int height)
{
	image = al_create_bitmap(width,height);

}

void plate::placeshape(ALLEGRO_BITMAP * shape, rect box)
{
	al_set_target_bitmap(image);
	al_draw_bitmap_region(shape,0,0,box.getw(),box.geth(),box.getx(),box.gety(),0);
}

ALLEGRO_BITMAP * plate::getI()
{
	return image;
}
