//
// Created by abiec on 14/05/2025.
//
#include <stdio.h>
#include "attaque_corps.h"
#include "attaque_sort.h"

void afficherNuageFumee(ClassePersonnage* a, ClassePersonnage* b) ;

/**On teste que les personnages soient bien sur des cases voisines**/ 
int sontAdjacents(ClassePersonnage *a, ClassePersonnage *b) {
    if (abs(a->x - b->x) + abs(a->y - b->y) == 1) {//on vérifie qu'ils sont sur des cases voisines
        return 1;
    }
    return 0;
}


void attaqueCAC(ClassePersonnage *attaquant, ClassePersonnage *cible) {
    if (sontAdjacents(attaquant, cible) == 1) {

        // Celui qui attaque avance vers sa cible pour provoquer la collision
        int oldX = attaquant->x;
        int oldY = attaquant->y;

        attaquant->x = cible->x;
        attaquant->y = cible->y;

        // Pas encore codé mais il faut coder ça pour avoir un nuage de fumée lorsqu'il y a collision entre les personnages
        afficherNuageDeFumee(cible->x, cible->y); //Celui qui attaque fonce sur la cible et il y a un nuage de fumée pour marquer l'attaque

        // On applique les dégâts sur les pv de la cible
        cible->pv -= attaquant->puissanceCAC;

        // Retour à la position d'origine (c'est une option on le fera peut être pas)
        attaquant->x = oldX;
        attaquant->y = oldY;
    } else {
        printf("Pas à portée !"); // Afficher à l'écran qu'on ne peut pas faire d'attaque au corps à corps 
    }
}
