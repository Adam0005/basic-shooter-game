#include <iostream>
#include <allegro5/allegro.h>

const int SCREEN_W = 640;
const int SCREEN_H = 480;

int main()
{
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_EVENT_QUEUE* event_queue = NULL;
    ALLEGRO_TIMER* timer = NULL;

    if(!al_init()) {
        std::cout << "Failed to initialize Allegro.\n";
        return -1;
    }

    display = al_create_display(SCREEN_W, SCREEN_H);
    if(!display) {
        std::cout << "Failed to create display.\n";
        return -1;
    }

    event_queue = al_create_event_queue();
    timer = al_create_timer(1.0 / 60.0);

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    al_start_timer(timer);

    bool done = false;
    while(!done) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            done = true;
        }
        else if(ev.type == ALLEGRO_EVENT_TIMER) {
            // update game state
        }

        // render game
        al_clear_to_color(al_map_rgb(0, 0, 0));
        // render player, enemies, bullets, etc.
        al_flip_display();
    }

    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);

    return 0;
}
