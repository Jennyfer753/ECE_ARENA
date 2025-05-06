#include <Allegro.h>
#include <stdio.h>
#include "gestion_states.h"
#include "joueurs.h"

void state(BITMAP* buffer, init_joueurs* j, int nb_joueurs, int taille_case) {
    for (int i = 0; i < nb_joueurs; i++) {
        int x = 110 + j[i].colonne * taille_case + taille_case / 2;
        int y = j[i].ligne * taille_case + taille_case / 2;

        if (mouse_x >= x - 25 && mouse_x <= x + 25 &&
            mouse_y >= y - 25 && mouse_y <= y + 25) {
            char pm[10], pv[10], pa[10],nom[51];
            sprintf(nom, j[i].nom);
            sprintf(pv, "PV: %d", j[i].pv);
            sprintf(pm,"PM:%d",j[i].pm);
            sprintf(pa,"PA:%d",j[i].pa);

            textout_ex(buffer, font, nom, mouse_x + 10, mouse_y + 10, makecol(255, 255, 255), -1);
            textout_ex(buffer, font, pv, mouse_x + 10, mouse_y + 20, makecol(255, 255, 255), -1);
            textout_ex(buffer, font, pm, mouse_x + 10, mouse_y + 30, makecol(255, 255, 255), -1);
            textout_ex(buffer, font, pa, mouse_x + 10, mouse_y + 40, makecol(255, 255, 255), -1);
            }
    }
}
