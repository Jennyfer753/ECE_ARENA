
#ifndef JOUEURS_H
#define JOUEURS_H

typedef struct {
    int ligne;
    int colonne;
    int couleur;
    int pv ;
    int pm;
    int pa;
    char classe[4];
    char nom[51];
} init_joueurs;

#endif //JOUEURS_H
