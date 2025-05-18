#include <allegro.h>
#include <stdio.h>
#include "gestion_states.h"
#include "joueurs.h"

void state(BITMAP* buffer, init_joueurs* j, int nb_joueurs, int taille_case) {
    int decalage_x = 20;
    int decalage_y = (600 - 13 * taille_case) / 2;

    for (int i = 0; i < nb_joueurs; i++) {
        int x = decalage_x + j[i].colonne * taille_case + taille_case / 2;
        int y = decalage_y + j[i].ligne * taille_case + taille_case / 2;

        if (mouse_x >= x - 20 && mouse_x <= x + 20 &&
            mouse_y >= y - 20 && mouse_y <= y + 20) {

            char pm[20], pv[20], pa[20], nom[51], classe[60];
            sprintf(nom, "Nom : %s", j[i].nom);
            sprintf(classe, "Classe : %s", j[i].classe);
            sprintf(pv, "PV : %d", j[i].pv);
            sprintf(pm, "PM : %d", j[i].pm);
            sprintf(pa, "PA : %d", j[i].pa);

            int box_x = mouse_x + 10;
            int box_y = mouse_y + 10;
            int largeur = 150;
            int hauteur = 70;

            // Fond semi-transparent
            drawing_mode(DRAW_MODE_TRANS, NULL, 0, 0);
            set_trans_blender(0, 0, 0, 128);
            rectfill(buffer, box_x - 5, box_y - 5, box_x + largeur, box_y + hauteur, makecol(0, 0, 0));
            solid_mode();

            // Textes
            textout_ex(buffer, font, nom, box_x, box_y, makecol(255, 255, 255), -1);
            textout_ex(buffer, font, classe, box_x, box_y + 12, makecol(255, 255, 255), -1);
            textout_ex(buffer, font, pv, box_x, box_y + 24, makecol(255, 255, 255), -1);
            textout_ex(buffer, font, pm, box_x, box_y + 36, makecol(255, 255, 255), -1);
            textout_ex(buffer, font, pa, box_x, box_y + 48, makecol(255, 255, 255), -1);
            }
    }
}
