#include <stdio.h>
#include <allegro.h>
#include "allegro_init.h"
#include "menu.h"
#include "parties.h"
#include "gestion_sons.h"

int main() {
    BITMAP* buffer = NULL;
    int etat_jeu=0;
    int etat_son=1;

    initialisation_allegro(&buffer);
    init_son(&etat_son);

    while (!key[KEY_ESC]) {
        clear_bitmap(buffer);

        switch(etat_jeu) {
            case 0 :
                ecran_menu(buffer);
            bouton_son(buffer, &etat_son);

            if ((mouse_b & 1) && (mouse_x >= 300) &&
                (mouse_x <= 500) && (mouse_y >= 250) &&
                (mouse_y <= 290)) {
                etat_jeu = 1;
                }

            if ((mouse_b & 1) && (mouse_x >= 300) &&
               (mouse_x <= 500) && (mouse_y >= 330) &&
               (mouse_y <= 370)) {
                etat_jeu = 5;
               }
                while (mouse_b & 1) {
                    if (mouse_b & 1) {
                    clic(mouse_x, mouse_y, &etat_son);
                    }
            }
            break;

            case 1:
                config_partie(buffer,&etat_son);

            if (key[KEY_2]) {
                etat_jeu = 2;
            }
            else if (key[KEY_3]){
                etat_jeu = 3;
            }
            else if (key[KEY_4]) {
                etat_jeu = 4;
            }

            if (mouse_b & 1) {

                  if (mouse_x >= 220 && mouse_x <= 380 &&
                      mouse_y >= 200 && mouse_y <= 250 ){
                    etat_jeu = 2;
                }
                else if(mouse_x >= 420 && mouse_x <= 580 &&
                    mouse_y >= 200 && mouse_y <= 250) {
                    etat_jeu = 3;
                }
                else if(mouse_x >= 320 && mouse_x <= 480 &&
                    mouse_y >= 280 && mouse_y <= 330) {
                    etat_jeu = 4;
                }
            }
            break;

            case 2 :
                init_1v1(buffer);
            break;

            case 3 :
                init_1v1v1(buffer);
            break;

            case 4 :
                init_1v1v1v1(buffer);
            break;

            case 5:
                allegro_exit();
            exit(0);
        }

    blit(buffer, screen,
        0, 0,
        0, 0, 800, 600);
}
    destroy_bitmap(buffer);
    return 0;
}
END_OF_MAIN();
