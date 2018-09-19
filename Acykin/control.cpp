#include <iostream>
#include "control.h"
#include "display.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
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

	al_install_keyboard();
	ALLEGRO_KEYBOARD_STATE keyState;
	al_install_mouse();

	






	game Acykin(room(),player("Acykin",rect(50,50,20,20)));


	display screen(800,600);

	ALLEGRO_EVENT_QUEUE *queue;
	queue = al_create_event_queue();

	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_display_event_source(screen.getScreen()));
	al_register_event_source(queue, al_get_keyboard_event_source());

	bool running = true;
	while (running) {
		ALLEGRO_EVENT event;

		al_wait_for_event(queue, &event);

		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {// eixt procedure
			running = false;
			cout << "ending" << endl;
		}
		else if (event.type == ALLEGRO_EVENT_TIMER) {



			Acykin.updateplayer();
			vector<wall> todraw = Acykin.getCurrentWalls();
			Acykin.hero.getHit();
			for (int i = 0; i < todraw.size(); i++) {
				if (Acykin.hero.getHit().colision(todraw[i].getColisionBox())) {
					Acykin.hero.collision(todraw[i].getColisionBox(),"Wall");
					Acykin.hero.getHit().display();
					todraw[i].getColisionBox().display();

				}
			}



			screen.clear();
			todraw = Acykin.getCurrentWalls();
			for (int i = 0; i < todraw.size(); i++) {
				screen.draw(todraw[i].getDrawingBox());
			}
			screen.draw(Acykin.hero.getDraw());
			screen.flip();
		}
		

		al_get_keyboard_state(&keyState);

		//left right
		if ((al_key_down(&keyState, ALLEGRO_KEY_RIGHT))&(al_key_down(&keyState, ALLEGRO_KEY_LEFT))){
			Acykin.hero.setHorizonal(0);
		}
		else if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT)) {
			Acykin.hero.setHorizonal(1);
		}
		else if (al_key_down(&keyState, ALLEGRO_KEY_LEFT)) {
			Acykin.hero.setHorizonal(-1);
		}
		else {
			Acykin.hero.setHorizonal(0);
		}

		if ((al_key_down(&keyState, ALLEGRO_KEY_UP))&(al_key_down(&keyState, ALLEGRO_KEY_DOWN))) {
			Acykin.hero.setVertical(0);
		}
		else if (al_key_down(&keyState, ALLEGRO_KEY_DOWN)) {
			Acykin.hero.setVertical(1);
		}
		else if (al_key_down(&keyState, ALLEGRO_KEY_UP)) {
			Acykin.hero.setVertical(-1);
		}
		else {
			Acykin.hero.setVertical(0);
		}


	}

	return 0;

}