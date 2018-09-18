#include <iostream>
#include "control.h"
#include <allegro5/allegro.h>
using namespace std;


int controlStart() {

	cout << "where the main game loop is" << endl;
	al_init();

	ALLEGRO_TIMER *timer;
	timer = al_create_timer(1.0 / 60.0);
	al_start_timer(timer);


	ALLEGRO_EVENT_QUEUE *queue;
	queue = al_create_event_queue();





	return 0;

}