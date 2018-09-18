#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "display.h"


using namespace std;


display::display(int sizex, int sizey) {
	this->screen = al_create_display(sizex, sizey);
}

ALLEGRO_DISPLAY* display::getScreen() {
	return screen;
}

void display::clear() {
	al_clear_to_color(al_map_rgb(255, 255, 255));
}

void display::flip() {
	al_flip_display();
}

void display::draw(rect shape) {
	al_draw_rectangle(shape.getx(), shape.gety(), shape.right(), shape.bottom(),
		al_map_rgb(0, 0, 0), 2.0);
}