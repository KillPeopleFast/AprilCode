#include <allegro5/allegro.h>
#include<iostream>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include <allegro5/allegro_image.h>
using namespace std;

void wallCollide(int x, int y, int dir, int map[20][20]);

int main()
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *square = NULL;
	ALLEGRO_BITMAP *wall = NULL;
	ALLEGRO_BITMAP *dot = NULL;
	ALLEGRO_FONT *font = NULL;

	//these two variables hold the x and y positions of the square
	//initalize these variables to where you want your square to start
	int square_x = 460;
	int square_y = 590;
	int score = 0;




	int map[20][20] = {
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,1,
		1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,2,2,1,
		1,2,1,2,2,2,2,1,2,1,2,2,2,2,1,2,2,2,2,1,
		1,2,1,2,1,2,2,1,2,1,2,1,1,2,1,2,2,2,1,1,
		1,2,2,2,1,2,2,1,2,1,2,1,2,2,1,2,1,2,2,1,
		1,2,1,1,1,2,1,1,2,1,2,1,2,2,1,2,1,2,2,1,
		1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,2,1,
		1,2,1,1,1,1,2,1,1,0,0,1,1,2,2,1,1,2,2,1,
		0,2,2,2,2,2,2,1,0,0,0,0,1,2,2,2,2,2,2,0,
		0,2,2,2,2,2,2,1,0,0,0,0,1,2,2,2,2,2,2,0,
		1,2,1,1,1,1,2,1,1,1,1,1,1,2,2,1,1,2,2,1,
		1,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,1,1,
		1,2,1,1,2,1,1,1,1,1,1,2,2,1,2,2,1,2,2,1,
		1,2,2,1,2,2,2,2,2,2,1,2,2,1,2,2,1,1,2,1,
		1,2,1,1,2,1,1,2,1,2,1,2,2,1,2,2,2,2,2,1,
		1,2,1,2,2,2,1,2,1,2,2,2,1,1,1,1,1,1,2,1,
		1,2,1,1,1,1,1,2,1,1,1,2,1,2,2,2,2,1,2,1,
		1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	};
	for (int row = 0; row < 20; row++) {
		for (int column = 0; column < 20; column++) 
			cout << map[row][column];
			cout << endl;
		
	}




	//here's our key states. they're all starting as "false" because nothing has been pressed yet.
	//the first slot represents "up", then "down", "left" and "right"
	bool key[4] = { false, false, false, false };

	//don't redraw until an event happens
	bool redraw = true;

	//this controls our game loop
	bool doexit = false;

	al_init();
	//al_init_ttf_addon();
	//al_init_font_addon();
	//al_install_audio();
	//al_init_acodec_addon();
	al_init_image_addon();

	//font = al_load_ttf_font("meatloaf.ttf", 100, 0);

	//square = al_load_bitmap("pacman.jpg");


	//get the keyboard ready to use
	al_install_keyboard();

	timer = al_create_timer(.02);

	display = al_create_display(800, 800);

	square = al_create_bitmap(34, 34);

	al_set_target_bitmap(square);

	al_clear_to_color(al_map_rgb(200, 200, 0));

	wall = al_create_bitmap(40, 40);

	al_set_target_bitmap(wall);

	al_clear_to_color(al_map_rgb(20, 200, 360));

	dot = al_create_bitmap(16, 16);

	al_set_target_bitmap(dot);

	al_clear_to_color(al_map_rgb(255, 255, 255));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	//these lines tell teh event source what to look for
	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	//new! tell the event queue that it should take keyboard events, too 
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);
	

	//so the game loop is set to act on "ticks" of the timer OR keyboard presses 
	//OR the mouse closing the display
	while (!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		//////////////////////////////////////////////////////////////////////////////////////////////////
		//here's the movement algorithm

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			//if the up button is pressed AND we're still below the top wall,
			//move the box "up" by 4 pixels
			if (key[0] && square_y >= 0) {
				square_y -= 4.0;
			}

			//if the down button is pressed AND we're still above the bottom wall
			//move the box "down" by 4 pixels
			if (key[1] && square_y <= 800 - 32) {
				square_y += 4.0;
			}
			//if the left button is pressed AND we're still right of the left wall
			//move the box left by 4 pixels
			if (key[2] && square_x >= 0) {
				square_x -= 4.0;
			}

			//if the left button is pressed AND we're still left of the right wall
			//move the box right by 4 pixels
			if (key[3] && square_x <= 800 - 32) {
				square_x += 4.0;
			}

			//redraw at every tick of the timer
			redraw = true;
		}
		if (map[(square_y + 20) / 40][(square_x + 20) / 40] == 2) {
				map[(square_y + 20) / 40][(square_x + 20) / 40] = 4; //4s are blank
				score++;
			}

		///////////////////////////////////////////////////////////////////////////////////////////////////////
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		//////////////////////////////////////////////////////////////////////////////////////////////////////
		//here's the algorithm that turns key presses into events
		//a "key down" event is when a key is pushed
		//while a "key up" event is when a key is released

		//has something been pressed on the keyboard?
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {

			//"keycode" holds all the different keys on the keyboard
			switch (ev.keyboard.keycode) {

				//if the up key has been pressed
			case ALLEGRO_KEY_UP:
				key[0] = true;
				break;

				//if the down key has been pressed
			case ALLEGRO_KEY_DOWN:
				key[1] = true;
				break;

				//if the left key has been pressed
			case ALLEGRO_KEY_LEFT:
				key[2] = true;
				break;

				//if the right key has been pressed
			case ALLEGRO_KEY_RIGHT:
				key[3] = true;
				break;
			}
		}
		//has something been released on the keyboard?
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[0] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				key[1] = false;
				break;

			case ALLEGRO_KEY_LEFT:
				key[2] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[3] = false;
				break;

				//kill the program if someone presses escape
			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}


		int PlatformCollide(int x, int y, int dir, int map[20][20]) {

			if (((map[(x + 32) / 100][(y + 32) / 100] == 1) && dir == 1) ||

				((map[(x) / 100][(y + 32) / 100] == 1) && dir == 1)) {

				return 1; //collision when falling down!
			}


		//RENDER SECTION
		//if the clock ticked but no other events happened, don't bother redrawing
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			//paint black over the old screen, so the old square dissapears
			al_clear_to_color(al_map_rgb(0, 0, 0));

			//the algorithm above just changes the x and y coordinates
			//here's where the bitmap is actually drawn somewhere else
			al_draw_bitmap(square, square_x, square_y, 0);

			//draw the MATRIX
			for (int row = 0; row < 20; row++) {
				for (int column = 0; column < 20; column++)
					if (map[row][column] == 1)
						al_draw_bitmap(wall, column * 40, row * 40, NULL);
					else if (map[row][column] == 2)
						al_draw_bitmap(dot, column * 40+16, row * 40+16, NULL);
					}
			//al_draw_bitmap(square, 200, 200, 0);
			//al_draw_textf(font, al_map_rgb(255, 255, 255), 69, 40, ALLEGRO_ALIGN_LEFT, "%i", score);
			
			al_flip_display();
		}
	}

	al_destroy_bitmap(square);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}

void wallCollide(int x, int y, int dir, int map[20][20])
{
	
}
