//
// Created by abiec on 14/05/2025.
//
#include <stdio.h>
#include "attaque_corps.h"

int sontAdjacents(Personnage *a, Personnage *b) {
    if (abs(a->x - b->x) + abs(a->y - b->y) == 1) {//on vérifie qu'ils sont sur des cases voisines
        return 1;
    }
    return 0;
}

void afficherNuageFumee(Personnage* a, Personnage* b) {

}

void attaqueCAC(Personnage *attaquant, Personnage *cible) {
    if (sontAdjacents(attaquant, cible) == 1) {

        // Celui qui attaque avance vers sa cible pour provoquer la collision
        int oldX = attaquant->x;
        int oldY = attaquant->y;

        attaquant->x = cible->x;
        attaquant->y = cible->y;

        // Afficher le nuage de fumée (à coder avec Allegro 4 : draw_sprite(...))
        afficherNuageDeFumee(cible->x, cible->y);

        // On applique les dégâts sur les pv de la cible
        cible->pv -= attaquant->puissanceCAC;

        // Retour à la position d'origine (optionnel)
        attaquant->x = oldX;
        attaquant->y = oldY;
    } else {
        printf("Pas à portée !");
    }
}
