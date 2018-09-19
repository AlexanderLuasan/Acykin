#include "imagecutter.h"
#include <string>
#include <allegro5/allegro.h>

using namespace std;


spritesheet::spritesheet()
{


}

spritesheet::spritesheet(const char *filename, int w, int h)
{
	width = w;
	height = h;
	sheet = al_load_bitmap(filename);

}

ALLEGRO_BITMAP * spritesheet::getFramce(int x, int y)
{
	return al_create_sub_bitmap(sheet,x*width, y*height, width, height);
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
