
#ifndef JOUEURS_H
#define JOUEURS_H

typedef struct {
    int ligne;
    int colonne;
    int pv ;
    int pa;
    int pm;
    int classe;
    int couleur;
    char nom[51];
} init_joueurs;

#endif //JOUEURS_H
