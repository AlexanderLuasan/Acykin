#include <allegro5/allegro.h>
#include "display.h"


using namespace std;


display::display(int sizex, int sizey) {
	this->screen = al_create_display(sizex, sizey);
}

ALLEGRO_DISPLAY* display::getScreen() {
	return screen;
}