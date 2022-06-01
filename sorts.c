/*
#include "sorts.h"
SORTS

int main() {
    // Déclarations
    bool end = false;
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_KEYBOARD_STATE etatClavier;
    int largeurheal;
    int longueurheal;

    // Initilialisation (al_init) / Installations (al_install)
    assert(al_init());
    assert(al_install_keyboard());

    // Création (al_create)
    display = al_create_display(800, 600);
    al_set_window_title(display, "Dofus version beta");
    al_set_window_position(display, 20, 20);

    // Premier affichage
    al_clear_to_color(al_map_rgb(200, 215, 200));
    al_flip_display();
    // Boucle d'événements // Libérations
    // PROGRAMME PROJET -------------------------------------------------------------------------------------
    al_init_image_addon();


    ALLEGRO_BITMAP *sortdefleche = NULL;
    ALLEGRO_BITMAP *dragondefeu = NULL;
    ALLEGRO_BITMAP *bouleDeFeu = NULL;
    ALLEGRO_BITMAP *heal = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_EVENT event;
    ALLEGRO_EVENT_QUEUE *queuedejeu = NULL;


    queuedejeu = al_create_event_queue();
    timer = al_create_timer(1.0 / FPS);
    sortdefleche = al_load_bitmap("../Image/flechejeusort.png");
    dragondefeu = al_load_bitmap("../Image/dragonFeu.png");
    heal = al_load_bitmap("../Image/heal.png");
    bouleDeFeu = al_load_bitmap("../Image/bdfterminé.png");

    al_start_timer(timer);

    al_register_event_source(queuedejeu, al_get_timer_event_source(timer));


    /*  switch (event.type) {
          al_wait_for_event(queuedejeu, &event);
          case ALLEGRO_EVENT_TIMER:{

          }
                  }

    while (!end) {
        al_get_keyboard_state(&etatClavier);
        al_wait_for_event(queuedejeu, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_TIMER: {

                break;
            }
        }

        if (al_key_down(&etatClavier, ALLEGRO_KEY_F)) {
            for (int i = 500; i != 0; i--) {
                al_clear_to_color(al_map_rgb(200, 215, 200));
                al_draw_bitmap(sortdefleche, i, 0, 0);
                al_flip_display();
            }
        }

        if (al_key_down(&etatClavier, ALLEGRO_KEY_K)) {
            for (int i = 0; i < 1260; i += 140) {

                al_clear_to_color(al_map_rgb(255, 255, 255));
                al_draw_scaled_bitmap(dragondefeu, i, 0, 140, 98, 30, 30, 140, 98, 0);
                al_rest(0.1);
                al_flip_display();
            }
        }
        if (al_key_down(&etatClavier, ALLEGRO_KEY_H)) {
            for (int i = 0; i < 456; i += 95) {

                al_clear_to_color(al_map_rgb(255, 255, 255));
                al_draw_scaled_bitmap(heal, i, 0, 95, 98, 30, 30, 95, 98, 0);
                al_rest(0.1);
                al_flip_display();
            }
        }
        if (al_key_down(&etatClavier, ALLEGRO_KEY_B)) {
            for (int i = 30; i < 1279; i += 60) {

                al_clear_to_color(al_map_rgb(255, 255, 255));
                al_draw_scaled_bitmap(bouleDeFeu, i, 0, 60, 78, 30, 30, 60, 78, 0);
                al_rest(0.2);
                al_flip_display();
            }
        }
        if (al_key_down(&etatClavier, ALLEGRO_KEY_ESCAPE)) {
            end = true;


        }
    }


    al_destroy_bitmap(sortdefeu);
    al_destroy_display(display);
    // al_destroy_timer(timer);

    return 0;

    int main() {
        // Déclarations
        bool end = false;
        ALLEGRO_DISPLAY *display = NULL;
        ALLEGRO_KEYBOARD_STATE etatClavier;
        int largeurheal;
        int longueurheal;

        // Initilialisation (al_init) / Installations (al_install)
        assert(al_init());
        assert(al_install_keyboard());

        // Création (al_create)
        display = al_create_display(800, 600);
        al_set_window_title(display, "Dofus version beta");
        al_set_window_position(display, 20, 20);

        // Premier affichage
        al_clear_to_color(al_map_rgb(200, 215, 200));
        al_flip_display();
        // Boucle d'événements
        // Libérations
// PROGRAMME PROJET -------------------------------------------------------------------------------------
        al_init_image_addon();


        ALLEGRO_BITMAP *sortdefleche = NULL;
        ALLEGRO_BITMAP *dragondefeu = NULL;
        ALLEGRO_BITMAP *bouleDeFeu = NULL;
        ALLEGRO_BITMAP *heal = NULL;
        ALLEGRO_TIMER *timer = NULL;
        ALLEGRO_EVENT event;
        ALLEGRO_EVENT_QUEUE *queuedejeu = NULL;


        queuedejeu = al_create_event_queue();
        timer = al_create_timer(1.0 / FPS);
        sortdefleche = al_load_bitmap("../Image/flechejeusort.png");
        dragondefeu = al_load_bitmap("../Image/dragonFeu.png");
        heal = al_load_bitmap("../Image/heal.png");
        bouleDeFeu = al_load_bitmap("../Image/bdfterminé.png");

        al_start_timer(timer);

        al_register_event_source(queuedejeu, al_get_timer_event_source(timer));


        /*  switch (event.type) {
              al_wait_for_event(queuedejeu, &event);
              case ALLEGRO_EVENT_TIMER:{

              }
                      }

        while (!end) {
            al_get_keyboard_state(&etatClavier);
            al_wait_for_event(queuedejeu, &event);
            switch (event.type) {
                case ALLEGRO_EVENT_TIMER: {

                    break;
                }
            }

            if (al_key_down(&etatClavier, ALLEGRO_KEY_F)) {
                for (int i = 500; i != 0; i--) {
                    al_clear_to_color(al_map_rgb(200, 215, 200));
                    al_draw_bitmap(sortdefleche, i, 0, 0);
                    al_flip_display();
                }
            }

            if (al_key_down(&etatClavier, ALLEGRO_KEY_K)) {
                for (int i = 0; i < 1260; i += 140) {

                    al_clear_to_color(al_map_rgb(255, 255, 255));
                    al_draw_scaled_bitmap(dragondefeu, i, 0, 140, 98, 30, 30, 140, 98, 0);
                    al_rest(0.1);
                    al_flip_display();
                }
            }
            if (al_key_down(&etatClavier, ALLEGRO_KEY_H)) {
                for (int i = 0; i < 456; i += 95) {

                    al_clear_to_color(al_map_rgb(255, 255, 255));
                    al_draw_scaled_bitmap(heal, i, 0, 95, 98, 30, 30, 95, 98, 0);
                    al_rest(0.1);
                    al_flip_display();
                }
            }
            if (al_key_down(&etatClavier, ALLEGRO_KEY_B)) {
                for (int i = 30; i < 1279; i += 60) {

                    al_clear_to_color(al_map_rgb(255, 255, 255));
                    al_draw_scaled_bitmap(bouleDeFeu, i, 0, 60, 78, 30, 30, 60, 78, 0);
                    al_rest(0.2);
                    al_flip_display();
                }
            }
            if (al_key_down(&etatClavier, ALLEGRO_KEY_ESCAPE)) {
                end = true;
            }
        }


        al_destroy_bitmap(sortdefeu);
        al_destroy_display(display);
        // al_destroy_timer(timer);

        return 0;
*/


