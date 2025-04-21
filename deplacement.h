#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H
#include "joueurs.h"

void deplacement(BITMAP* buffer, init_joueurs* j, int nb_joueurs);
void zonesDeplacement(BITMAP* buffer, int ligne_joueur, int colonne_joueur, int taille_case, init_joueurs* joueurs, int nb_joueurs);
int calculeDistancemanhattan(int ligne1, int colonne1, int ligne2, int colonne2);
int verificationCaseVide (int ligne, int colonne, init_joueurs* joueurs, int nb_joueurs, int joueur_actuel);
#endif //DEPLACEMENT_H
