#include <iostream>
#include "control.h"
#include "display.h"
#include <allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include "Rect.h"
#include "model.h"
#include <vector>
using namespace std;


int controlStart() {

	cout << "where the main game loop is" << endl;
	al_init();
	al_init_primitives_addon();
	ALLEGRO_TIMER *timer;
	timer = al_create_timer(1.0 / 30.0);
	al_start_timer(timer);


	wall one(rect(20, 20, 50, 10));
	wall two(rect(600, 400, 50, 10));
	wall thr(rect(60, 32, 10, 50));
	vector<wall> wallist;

	wallist.push_back(one);
	wallist.push_back(two);
	wallist.push_back(thr);


	game Acykin(room(wallist),player("Acykin",rect(400,300,20,20)));


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
			vector<wall> todraw = Acykin.getCurrentWalls();
			for (int i = 0; i < todraw.size(); i++) {
				screen.draw(todraw[i].getDrawingBox());
			}


			screen.flip();
		
		}
	}

	return 0;

}