#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <assert.h>
#include <time.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#define LARGEUR 1920
#define LONGUEUR 1080
#define CREER_COULEUR al_map_rgb(rand()%256, rand()%256, rand()%256)


void dessinerEcran(ALLEGRO_BITMAP *fondecran, ALLEGRO_FONT* text){
    al_draw_bitmap(fondecran, 0, 0, 0);
    al_draw_filled_rounded_rectangle(660, 450, 1260, 600, 50, 50,al_map_rgb(85, 119, 107));
    al_draw_textf(text, al_map_rgb(255, 255, 255), 960, 457, ALLEGRO_ALIGN_CENTER, "Nouvelle partie");
    al_flip_display();
}
void ecranJoueur(ALLEGRO_BITMAP *fondecran, ALLEGRO_FONT *text){
    al_draw_bitmap(fondecran, 0, 0, 0);
    al_draw_filled_rounded_rectangle(660, 150, 1260, 300, 50, 50, al_map_rgb(85, 119, 107));
    al_draw_filled_rounded_rectangle(660, 400, 1260, 550, 50, 50, al_map_rgb(85, 119, 107));
    al_draw_filled_rounded_rectangle(660, 650, 1260, 800, 50, 50, al_map_rgb(85, 119, 107));
    al_draw_textf(text, al_map_rgb(255, 255, 255), 960, 150, ALLEGRO_ALIGN_CENTER, "2 joueurs");
    al_draw_textf(text, al_map_rgb(255, 255, 255), 960, 400, ALLEGRO_ALIGN_CENTER, "3 joueurs");
    al_draw_textf(text, al_map_rgb(255, 255, 255), 960, 650, ALLEGRO_ALIGN_CENTER, "4 joueurs");
    al_flip_display();
}

void ecranClasse(ALLEGRO_BITMAP *fondecran, ALLEGRO_FONT *text){
    al_draw_bitmap(fondecran, 0, 0, 0);
    al_draw_filled_rounded_rectangle(660, 130, 1260, 250, 50, 50, al_map_rgb(85, 119, 107));
    al_draw_filled_rounded_rectangle(660, 350, 1260, 470, 50, 50, al_map_rgb(85, 119, 107));
    al_draw_filled_rounded_rectangle(660, 570, 1260, 690, 50, 50, al_map_rgb(85, 119, 107));
    al_draw_filled_rounded_rectangle(660, 790, 1260, 910, 50, 50, al_map_rgb(85, 119, 107));
    al_draw_textf(text, al_map_rgb(255, 255, 255), 960, 125, ALLEGRO_ALIGN_CENTER, "CLASSE FEU");
    al_draw_textf(text, al_map_rgb(255, 255, 255), 960, 345, ALLEGRO_ALIGN_CENTER, "CLASSE EAU");
    al_draw_textf(text, al_map_rgb(255, 255, 255), 960, 565, ALLEGRO_ALIGN_CENTER, "CLASSE VENT");
    al_draw_textf(text, al_map_rgb(255, 255, 255), 960, 785, ALLEGRO_ALIGN_CENTER, "CLASSE TERRE");
    al_flip_display();
}

void ecranMenu(ALLEGRO_BITMAP *fondecran, ALLEGRO_FONT *text){
    al_draw_bitmap(fondecran, 0, 0, 0);
    al_draw_filled_rounded_rectangle(660, 150, 1260, 300, 50, 50, al_map_rgb(232, 33, 2));
    al_draw_filled_rounded_rectangle(660, 400, 1260, 550, 50, 50, al_map_rgb(232, 33, 2));
    al_draw_filled_rounded_rectangle(660, 650, 1260, 800, 50, 50, al_map_rgb(232, 33, 2));
    al_draw_textf(text, al_map_rgb(255, 255, 255), 960, 150, ALLEGRO_ALIGN_CENTER, "QUITTER");
    al_draw_textf(text, al_map_rgb(255, 255, 255), 960, 400, ALLEGRO_ALIGN_CENTER, "REJOUER LA MEME PARTIE");
    al_draw_textf(text, al_map_rgb(255, 255, 255), 960, 650, ALLEGRO_ALIGN_CENTER, "NOUVELLE PARTIE");
    al_flip_display();
}

void tour(){

}

int main() {
    //Déclaration :
    bool end = false;
    bool fin = false;
    bool clique = false;
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *queue = NULL;
    ALLEGRO_EVENT event;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_BITMAP *fondecran = NULL;
    ALLEGRO_FONT *text = NULL;
    ALLEGRO_BITMAP *persoclasse1 = NULL;
    ALLEGRO_BITMAP *persoclasse2 = NULL;
    ALLEGRO_BITMAP *persoclasse3 = NULL;
    ALLEGRO_BITMAP *persoclasse4 = NULL;
    int nbJoueur;
    int classe;


    //Initialisation :
    assert(al_init());
    assert(al_init_primitives_addon());
    assert(al_init_image_addon());
    assert(al_install_mouse());
    assert(al_install_keyboard());
    al_init_font_addon();
    assert(al_init_ttf_addon());
    fondecran = al_load_bitmap("../images/picture.jpg");
    text = al_load_ttf_font("../police/Koulen-Regular.ttf", 80, ALLEGRO_ALIGN_CENTER);

    //Création :
    display = al_create_display(LARGEUR, LONGUEUR);
    timer = al_create_timer(1.0 / 120.0);
    queue = al_create_event_queue();
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());

    //Premier affichage :

    dessinerEcran(fondecran, text);

    while (!clique) {
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_KEY_DOWN: {
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_ESCAPE: {
                        clique = true;
                        break;
                    }
                }
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN: {
                if ((event.mouse.button & 1) == 1) {
                    if (event.mouse.x >= 660 && event.mouse.x <= 1260
                        && event.mouse.y >= 450 && event.mouse.y <= 600) {
                        clique = true;
                        ecranJoueur(fondecran, text);
                        while (!end) {
                            al_wait_for_event(queue, &event);
                            switch (event.type) {
                                case ALLEGRO_EVENT_KEY_DOWN: {
                                    switch (event.keyboard.keycode) {
                                        case ALLEGRO_KEY_ESCAPE: {
                                            end = true;
                                            break;
                                        }
                                    }
                                    break;
                                }
                                case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN: {
                                    if ((event.mouse.button & 1) == 1) {
                                        if (event.mouse.x >= 660 && event.mouse.x <= 1260
                                            && event.mouse.y >= 150 && event.mouse.y <= 300) {
                                            nbJoueur = 2;
                                            end = true;
                                            for (int i = 0; i < nbJoueur; i++) {
                                                ecranClasse(fondecran, text);
                                                al_draw_textf(text, al_map_rgb(255, 255, 255), 100, 150,
                                                              ALLEGRO_ALIGN_LEFT, "joueur %d", i + 1);
                                                al_flip_display();
                                                while (!fin) {
                                                    al_wait_for_event(queue, &event);
                                                    switch (event.type) {
                                                        case ALLEGRO_EVENT_KEY_DOWN: {
                                                            switch (event.keyboard.keycode) {
                                                                case ALLEGRO_KEY_ESCAPE: {
                                                                    fin = true;
                                                                    break;
                                                                }
                                                            }
                                                            break;
                                                        }
                                                        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN: {
                                                            if ((event.mouse.button & 1) == 1) {
                                                                if (event.mouse.x >= 660 && event.mouse.x <= 1260
                                                                    && event.mouse.y >= 130 && event.mouse.y <= 250) {
                                                                    printf("classe 1");
                                                                    classe = 1;
                                                                    fin = true;
                                                                }
                                                                if (event.mouse.x >= 660 && event.mouse.x <= 1260
                                                                    && event.mouse.y >= 350 && event.mouse.y <= 470) {
                                                                    printf("classe 2");
                                                                    classe = 2;
                                                                    fin = true;
                                                                }
                                                                if (event.mouse.x >= 660 && event.mouse.x <= 1260
                                                                    && event.mouse.y >= 570 && event.mouse.y <= 690) {
                                                                    printf("classe 3");
                                                                    classe = 3;
                                                                    fin = true;
                                                                }
                                                                if (event.mouse.x >= 660 && event.mouse.x <= 1260
                                                                    && event.mouse.y >= 790 && event.mouse.y <= 910) {
                                                                    printf("classe 4");
                                                                    classe = 4;
                                                                    fin = true;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (event.mouse.x >= 660 && event.mouse.x <= 1260
                                            && event.mouse.y >= 400 && event.mouse.y <= 550) {
                                            nbJoueur = 3;
                                            end = true;
                                            for (int i = 0; i < nbJoueur; i++) {
                                                ecranClasse(fondecran, text);
                                                al_draw_textf(text, al_map_rgb(255, 255, 255), 100, 150,
                                                              ALLEGRO_ALIGN_LEFT, "joueur %d", i + 1);
                                                al_flip_display();
                                                while (!fin) {
                                                    al_wait_for_event(queue, &event);
                                                    switch (event.type) {
                                                        case ALLEGRO_EVENT_KEY_DOWN: {
                                                            switch (event.keyboard.keycode) {
                                                                case ALLEGRO_KEY_ESCAPE: {
                                                                    fin = true;
                                                                    break;
                                                                }
                                                            }
                                                            break;
                                                        }
                                                        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN: {
                                                            if ((event.mouse.button & 1) == 1) {
                                                                if (event.mouse.x >= 660 && event.mouse.x <= 1260
                                                                    && event.mouse.y >= 130 && event.mouse.y <= 250) {
                                                                    printf("classe 1");
                                                                    classe = 1;
                                                                    fin = true;
                                                                }
                                                                if (event.mouse.x >= 660 && event.mouse.x <= 1260
                                                                    && event.mouse.y >= 350 && event.mouse.y <= 470) {
                                                                    printf("classe 2");
                                                                    classe = 2;
                                                                    fin = true;
                                                                }
                                                                if (event.mouse.x >= 660 && event.mouse.x <= 1260
                                                                    && event.mouse.y >= 570 && event.mouse.y <= 690) {
                                                                    printf("classe 3");
                                                                    classe = 3;
                                                                    fin = true;
                                                                }
                                                                if (event.mouse.x >= 660 && event.mouse.x <= 1260
                                                                    && event.mouse.y >= 790 && event.mouse.y <= 910) {
                                                                    printf("classe 4");
                                                                    classe = 4;
                                                                    fin = true;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }

                                        if (event.mouse.x >= 660 && event.mouse.x <= 1260
                                            && event.mouse.y >= 650 && event.mouse.y <= 800) {
                                            nbJoueur = 4;
                                            end = true;
                                            for (int i = 0; i < nbJoueur; i++) {
                                                ecranClasse(fondecran, text);
                                                al_draw_textf(text, al_map_rgb(255, 255, 255), 100, 150,
                                                              ALLEGRO_ALIGN_LEFT, "joueur %d", i + 1);
                                                al_flip_display();
                                                while (!fin) {
                                                    al_wait_for_event(queue, &event);
                                                    switch (event.type) {
                                                        case ALLEGRO_EVENT_KEY_DOWN: {
                                                            switch (event.keyboard.keycode) {
                                                                case ALLEGRO_KEY_ESCAPE: {
                                                                    fin = true;
                                                                    break;
                                                                }
                                                            }
                                                            break;
                                                        }
                                                        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN: {
                                                            if ((event.mouse.button & 1) == 1) {
                                                                if (event.mouse.x >= 660 && event.mouse.x <= 1260
                                                                    && event.mouse.y >= 130 && event.mouse.y <= 250) {
                                                                    printf("classe 1");
                                                                    classe = 1;
                                                                    fin = true;
                                                                }
                                                                if (event.mouse.x >= 660 && event.mouse.x <= 1260
                                                                    && event.mouse.y >= 350 && event.mouse.y <= 470) {
                                                                    printf("classe 2");
                                                                    classe = 2;
                                                                    fin = true;
                                                                }
                                                                if (event.mouse.x >= 660 && event.mouse.x <= 1260
                                                                    && event.mouse.y >= 570 && event.mouse.y <= 690) {
                                                                    printf("classe 3");
                                                                    classe = 3;
                                                                    fin = true;
                                                                }
                                                                if (event.mouse.x >= 660 && event.mouse.x <= 1260
                                                                    && event.mouse.y >= 790 && event.mouse.y <= 910) {
                                                                    printf("classe 4");
                                                                    classe = 4;
                                                                    fin = true;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }

                                        break;
                                    }

                                }
                            }
                        }
                    }
                }
            }
        }
    }
        tour();

        ecranMenu(fondecran, text);


        //Libération :
        al_destroy_event_queue(queue);
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_bitmap(fondecran);
        al_destroy_font(text);
        al_destroy_bitmap(persoclasse1);
        al_destroy_bitmap(persoclasse2);
        al_destroy_bitmap(persoclasse3);
        al_destroy_bitmap(persoclasse4);

        return 0;

}