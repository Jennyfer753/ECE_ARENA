#include <stdio.h>
#include <allegro.h>
#include "arene.h"

void arene(BITMAP* buffer) {
    int taille_case = 50;
    int largeur = SCREEN_H/taille_case;
    int longueur = SCREEN_W/taille_case;

    for (int ligne = 0; ligne < longueur; ligne++) {
        for (int colonne = 0; colonne < largeur; colonne++) {
            int x = 110 + colonne * taille_case;
            int y = ligne * taille_case;
            rectfill(buffer, x, y, x + taille_case, y + taille_case,makecol(0,0,0));
            rect(buffer, x, y, x + taille_case, y + taille_case, makecol(255, 255, 255));
        }
    }
}
