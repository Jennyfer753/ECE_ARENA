#include <allegro.h>
#include "1v1v1.h"
#include "joueurs.h"
#include "arene.h"

void init_1v1v1(BITMAP* buffer) {
    int taille_case = 50;
    init_joueurs j1 = {1, 5};
    init_joueurs j2 = {10, 5};
    init_joueurs j3 = {5, 1};

    while (!key[KEY_ESC]) {
        clear_bitmap(buffer);

        arene(buffer);

        int j1_x = 110+(j1.colonne * taille_case + taille_case / 2);
        int j1_y = j1.ligne * taille_case + taille_case / 2;
        circlefill(buffer, j1_x, j1_y, 30, makecol(255, 0, 0));

        int j2_x = 110+(j2.colonne * taille_case + taille_case / 2);
        int j2_y = j2.ligne * taille_case + taille_case / 2;
        circlefill(buffer, j2_x, j2_y, 30, makecol(0, 255, 0));

        int j3_x = 110+(j3.colonne * taille_case + taille_case / 2);
        int j3_y = j3.ligne * taille_case + taille_case / 2;
        circlefill(buffer, j3_x, j3_y, 30, makecol(0, 0, 255));

        blit(buffer, screen, 0, 0, 0, 0, 800, 600);
        rest(15);
    }
}
