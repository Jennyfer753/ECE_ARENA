#include "choix_classe.h"
#include "allegro.h"
#include "choix_classe.h"
#include <stdio.h>
#include <string.h>  // Pour strcpy

void choix_perso(BITMAP* buffer, init_joueurs* j, int id_joueur) {
    char page_actuelle = 0;
    while (page_actuelle == 0) {
        clear_bitmap(buffer);

        // Titre
        char titre[32];
        sprintf(titre, "Choix du joueur %d", id_joueur + 1);
        textout_centre_ex(buffer, font, titre, SCREEN_W / 2, 20, makecol(255, 255, 0), -1);

        // 4 rectangles
        rectfill(buffer, 50, 50, 390, 290, makecol(255, 0, 0));
        rectfill(buffer, 410, 310, 750, 550, makecol(255, 0, 0));
        rectfill(buffer, 50, 310, 390, 550, makecol(255, 0, 0));
        rectfill(buffer, 410, 50, 750, 290, makecol(255, 0, 0));

        // Clic
        if (mouse_b & 1) {
            if (mouse_x >= 50 && mouse_x <= 390 && mouse_y >= 50 && mouse_y <= 290)
                page_actuelle = 'A';
            else if (mouse_x >= 50 && mouse_x <= 390 && mouse_y >= 310 && mouse_y <= 550)
                page_actuelle = 'B';
            else if (mouse_x >= 410 && mouse_x <= 750 && mouse_y >= 50 && mouse_y <= 290)
                page_actuelle = 'C';
            else if (mouse_x >= 410 && mouse_x <= 750 && mouse_y >= 310 && mouse_y <= 550)
                page_actuelle = 'D';

            rest(200); // anti-rebond
        }

        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        rest(16);
    }
    // Affecte les stats en fonction du choix
    switch (page_actuelle) {
        case 'A':
        strcpy(j->nom, "Savant");
        break;
        case 'B':
        strcpy(j->nom, "Archer");
        break;
        case 'C':
        strcpy(j->nom, "Mage");
        break;
        case 'D':
        strcpy(j->nom, "Maitresse");
        break;
    }

    // Affiche le choix
    clear_bitmap(buffer);
    char texte[32];
    sprintf(texte, "Joueur %d a choisi %c", id_joueur + 1, page_actuelle);
    textout_centre_ex(buffer, font, texte, SCREEN_W / 2, SCREEN_H / 2, makecol(255, 255, 255), -1);
    blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    rest(500);

    // Enregistre la "classe" dans la structure du joueur
    j->classe[0] = page_actuelle;
    j->classe[1] = '\0';
}

