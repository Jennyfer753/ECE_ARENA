
#include "gestion_jeu.h"
#include <allegro.h>
#include <stdlib.h>
#include "allegro_init.h"
#include "menu.h"
#include "parties.h"
#include "gestion_sons.h"
#include "choix_partie.h"

void lancer_jeu() {
    BITMAP* buffer = NULL;
    BITMAP* img_menu = NULL;
    BITMAP* img_parties = NULL;
    BITMAP* son_on = NULL;
    BITMAP* son_off = NULL;

    int etat_jeu = 0;
    int etat_son = 1;

    initialisation_allegro(&buffer);
    init_son(&etat_son);
    img_menu = charger_img_menu();
    img_parties = charger_img_parties();
    son_on = charger_son_on();
    son_off = charger_son_off();


    SAMPLE* melodie_menu = load_sample("melodie_menu.wav");
    if (!melodie_menu) {
        allegro_message("Erreur chargement de la musique du menu");
        exit(EXIT_FAILURE);
    }
    if (etat_son == 1) {
        play_sample(melodie_menu, 255, 128, 1000, 1); // volume, panning, fréquence, boucle
    }

    while (!key[KEY_ESC]) {
        clear_bitmap(buffer);

        switch (etat_jeu) {
            case 0:
                ecran_menu(buffer, img_menu);
             bouton_son(buffer, &etat_son, son_on, son_off);; // affichage du bouton son
            if ((mouse_b & 1) && mouse_x >= 755 && mouse_x <= 785 &&mouse_y >= 555 && mouse_y <= 585)
            {
                clic(mouse_x, mouse_y, &etat_son, melodie_menu, buffer, son_on, son_off);
                while (mouse_b & 1){} // attendre le relâchement du clic
                }
            if ((mouse_b & 1) && (mouse_x >= 200 && mouse_x <= 380 &&
                                      mouse_y >= 330 && mouse_y <= 370)) {
                    while (mouse_b & 1);
                    etat_jeu = 1;
                } else if ((mouse_b & 1) && (mouse_x >= 420 && mouse_x <= 600 &&
                                             mouse_y >= 330 && mouse_y <= 370)) {
                    while (mouse_b & 1);
                    etat_jeu = 5;
                }
                break;

            case 1:
                config_partie(buffer, img_parties);
            bouton_son(buffer, &etat_son, son_on, son_off);

            // Bouton retour
            if ((mouse_b & 1) && mouse_x >= 50 && mouse_x <= 150 && mouse_y >= 550 && mouse_y <= 580) {
                etat_jeu = 0;
                while (mouse_b & 1) {} // attendre le relâchement du clic
            }

            // Bouton son
            if ((mouse_b & 1) && mouse_x >= 755 && mouse_x <= 785 && mouse_y >= 555 && mouse_y <= 585) {
                clic(mouse_x, mouse_y, &etat_son, melodie_menu, buffer, son_on, son_off);
                while (mouse_b & 1) {} // attendre relâchement ici aussi
            }

            // Boutons choix de partie
            if ((mouse_b & 1) && mouse_x >= 220 && mouse_x <= 380 && mouse_y >= 200 && mouse_y <= 250) {
                etat_jeu = 2;
                while (mouse_b & 1) {}
            }
            else if ((mouse_b & 1) && mouse_x >= 420 && mouse_x <= 580 && mouse_y >= 200 && mouse_y <= 250) {
                etat_jeu = 3;
                while (mouse_b & 1) {}
            }
            else if ((mouse_b & 1) && mouse_x >= 320 && mouse_x <= 480 && mouse_y >= 280 && mouse_y <= 330) {
                etat_jeu = 4;
                while (mouse_b & 1) {}
            }

            break;

            case 2:
                init_1v1(buffer);
                break;

            case 3:
                init_1v1v1(buffer);
                etat_jeu = 1;
                break;

            case 4:
                init_1v1v1v1(buffer);
                etat_jeu = 1;
                break;

            case 5:
                destroy_sample(melodie_menu);
                allegro_exit();
                exit(0);
        }

        blit(buffer, screen, 0, 0, 0, 0, 800, 600);
    }

    destroy_bitmap(img_menu);
    destroy_bitmap(img_parties);
    destroy_bitmap(son_on);
    destroy_bitmap(son_off);
    destroy_bitmap(buffer);
}
