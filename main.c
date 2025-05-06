#include <stdio.h>
#include <allegro.h>
#include "allegro_init.h"
#include "menu.h"
#include "parties.h"

int main() {

    BITMAP* buffer = NULL;
    int x1=300;
    int x2=500;
    int y1=250;
    int y2=350;
    int etat_jeu=0;

    initialisation_allegro(&buffer);

    while (!key[KEY_ESC]) {
        clear_bitmap(buffer);

        /*if (key[KEY_ENTER] ) {
            etat_jeu = 1;
            rest(200);
        }*///Ne fonctionne pas

        switch(etat_jeu) {
            case 0 :
                ecran_menu(buffer);
            if ((mouse_b & 1) && (mouse_x >= x1) &&
                (mouse_x <= x2) && (mouse_y >= y1) &&
                (mouse_y <= y2)) {
                etat_jeu = 1;
                }
            break;

            case 1:
                config_partie(buffer);

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
                int mx = mouse_x;
                int my = mouse_y;
                int rayon = 20;

                if ((mx - 350)*(mx - 350) + (my - 300)*(my - 300) <= rayon*rayon) {
                    etat_jeu = 2;
                }
                else if ((mx - 400)*(mx - 400) + (my - 300)*(my - 300) <= rayon*rayon) {
                    etat_jeu = 3;
                }
                else if ((mx - 450)*(mx - 450) + (my - 300)*(my - 300) <= rayon*rayon) {
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
        }

        blit(buffer, screen,
            0, 0,
            0, 0, 800, 600);
        }

    destroy_bitmap(buffer);
    return 0;
}
END_OF_MAIN();
