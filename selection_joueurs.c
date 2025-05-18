#include <stdio.h>
#include <string.h>
#include "selection_joueurs.h"

int souris_sur_classe(int x, int y, int nb_classes) {
    for (int i = 0; i < nb_classes; i++) {
        int bx = 550, by = 120 + i * 80;
        if (x >= bx && x <= bx + 120 && y >= by && y <= by + 60) return i;
    }
    return -1;
}

int souris_sur_joueur(int x, int y) {
    if (y >= 150 && y <= 250) {
        if (x >= 120 && x <= 300) return 0;
        if (x >= 370 && x <= 550) return 1;
    }
    return -1;
}

int souris_sur_valider(int x, int y) {
    return (x >= 300 && x <= 500 && y >= 500 && y <= 540);
}

void interface_selection(BITMAP *buffer, int joueur_actif, ClassePersonnage *classes, int nb_classes, int *choix_classes, ClassePersonnage *choix_sprites) {
    clear_bitmap(buffer);

    drawing_mode(DRAW_MODE_TRANS, NULL, 0, 0);
    set_trans_blender(0, 0, 0, 128);
    rectfill(buffer, 100, 50, 700, 550, makecol(160, 160, 160));
    rect(buffer, 100, 50, 700, 550, makecol(0, 0, 0));

    for (int i = 0; i < 2; i++) {
            int x1 = 120 + i * 250;
            int y1 = 150;
            int x2 = x1 + 180;
            int y2 = y1 + 100;

        int couleur;
        if (joueur_actif == i) {
            couleur = makecol(180, 180, 180);
        } else {
            couleur = makecol(120, 120, 120);
        }
        rectfill(buffer, x1, y1, x2, y2, couleur);

        rect(buffer, x1, y1, x2, y2, makecol(255, 255, 255));
        textprintf_centre_ex(buffer, font, (x1 + x2) / 2, y1 + 10, makecol(255, 255, 255), -1, "Joueur %d", i + 1);
        if (choix_classes[i] != -1 && choix_sprites[i].sprite) {
            draw_sprite(buffer, choix_sprites[i].sprite, x1 + 30, y1 + 30);
            textprintf_ex(buffer, font, x1 + 90, y1 + 45, makecol(0, 0, 0), -1, "%s", choix_sprites[i].nom_classe);
        }
    }

    for (int i = 0; i < nb_classes; i++) {
        int x = 550, y = 120 + i * 80;
        rectfill(buffer, x, y, x + 120, y + 60, makecol(150, 150, 150));
        rect(buffer, x, y, x + 120, y + 60, makecol(255, 255, 255));
        textprintf_ex(buffer, font, x + 10, y + 20, makecol(0, 0, 0), -1, "%s", classes[i].nom_classe);
    }

    // Bouton valider (si les deux classes sont choisies)
    if (choix_classes[0] != -1 && choix_classes[1] != -1) {
        rectfill(buffer, 300, 500, 500, 540, makecol(0, 200, 0));
        rect(buffer, 300, 500, 500, 540, makecol(255, 255, 255));
        textprintf_centre_ex(buffer, font, 400, 515, makecol(255, 255, 255), -1, "VALIDER");
    }
}

int selection_joueurs(BITMAP *buffer, init_joueurs *joueurs, int nb_joueurs, ClassePersonnage *classes, int nb_classes) {
    if (nb_joueurs != 2) return 0; // Ce code ne gère pour l’instant que 2 joueurs

    int choix_classes[2] = {-1, -1};
    ClassePersonnage sprites_choisis[2];
    int joueur_actif = 0;
    int valide = 0;

    while (!valide) {
        interface_selection(buffer, joueur_actif, classes, nb_classes, choix_classes, sprites_choisis);
        blit(buffer, screen, 0, 0, 0, 0, 800, 600);

        if (mouse_b & 1) {
            int clic_joueur = souris_sur_joueur(mouse_x, mouse_y);
            if (clic_joueur != -1) {
                joueur_actif = clic_joueur;
                rest(200);
            }

            int clic_classe = souris_sur_classe(mouse_x, mouse_y, nb_classes);
            if (clic_classe != -1) {
                choix_classes[joueur_actif] = clic_classe;
                sprites_choisis[joueur_actif] = classes[clic_classe];
                rest(200);
            }

            if (souris_sur_valider(mouse_x, mouse_y) &&
                choix_classes[0] != -1 && choix_classes[1] != -1) {
                valide = 1;
            }

            while (mouse_b & 1) rest(10); // attente relâchement clic
        }

        rest(20);
    }

    // Initialisation des joueurs
    for (int i = 0; i < 2; i++) {
        joueurs[i].ligne = (i == 0) ? 1 : 11;
        joueurs[i].colonne = 7;
        joueurs[i].couleur = makecol(rand() % 256, rand() % 256, rand() % 256);
        joueurs[i].pv = 100;
        joueurs[i].pa = 10;
        joueurs[i].pm = 25;
        sprintf(joueurs[i].nom, "J%d", i + 1);
        strcpy(joueurs[i].classe, classes[choix_classes[i]].nom_classe);
    }

    return 1;
}
