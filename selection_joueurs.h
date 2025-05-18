
#ifndef SELECTION_JOUEURS_H
#define SELECTION_JOUEURS_H
#include <allegro.h>
#include "joueurs.h"
#include "attaque_sort.h"

void interface_selection(BITMAP *buffer, int joueur_actif, ClassePersonnage *classes, int nb_classes, int *choix_classes, ClassePersonnage *choix_sprites);
int souris_sur_classe(int x, int y, int nb_classes);
int selection_joueurs(BITMAP *buffer, init_joueurs *joueurs, int nb_joueurs, ClassePersonnage *classes, int nb_classes);
int souris_sur_joueur(int x, int y);
int souris_sur_valider(int x, int y);
int selection_joueurs(BITMAP *buffer, init_joueurs *joueurs, int nb_joueurs, ClassePersonnage *classes, int nb_classes);

#endif //SELECTION_JOUEURS_H
