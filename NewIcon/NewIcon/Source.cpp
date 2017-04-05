
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"

int main() {
	
		   al_init();
	   al_init_image_addon();

		   ALLEGRO_DISPLAY *display = al_create_display(800, 600);
	    ALLEGRO_BITMAP  *icon = al_load_bitmap("icon.png");
	
		   al_set_display_icon(display, icon);
	
		  al_rest(3);
	
		   al_destroy_bitmap(icon);
    al_destroy_display(display);
    return 0;
	
}