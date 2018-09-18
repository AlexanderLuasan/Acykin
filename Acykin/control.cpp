#include <iostream>
#include "control.h"
#include "display.h"
#include <allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include "Rect.h"
using namespace std;


int controlStart() {

	cout << "where the main game loop is" << endl;
	al_init();
	al_init_primitives_addon();
	ALLEGRO_TIMER *timer;
	timer = al_create_timer(1.0 / 60.0);
	al_start_timer(timer);


	display screen(800,600);

	ALLEGRO_EVENT_QUEUE *queue;
	queue = al_create_event_queue();

	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_display_event_source(screen.getScreen()));


	bool running = true;
	while (running) {
		ALLEGRO_EVENT event;

		al_wait_for_event(queue, &event);

		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {// eixt procedure
			running = false;
			cout << "ending" << endl;
		}
		else if (event.type == ALLEGRO_EVENT_TIMER) {
			screen.clear();
			screen.draw(rect(5,10,40,40));
			screen.flip();
		
		}
	}

	return 0;

}