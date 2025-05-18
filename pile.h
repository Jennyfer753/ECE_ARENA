#ifndef PILE_H
#define PILE_H


///type pour les maillons
typedef struct maillonP{
    void *data; //pointeur generique sur la donnee
    struct maillonP *suivant;  //pointeur sur le maillon suivant
}t_maillonP;

///type pour la pile
typedef struct pile{
    t_maillonP *sommet;//ancre de tete : pointeur sur le sommet de la pile
    int taille; //taille de la pile
}t_pile;

///prototypes des sous-programmes
/* initialisation d'une pile vide
parametre : l'adresse de la pile */
void init_pile(t_pile*p);

/* test si la pile est vide
parametre : l'adresse de la pile
retour : 1 si la pile est vide, 0 sinon */
char pileVide(t_pile*f);

/* compter le nombre d'elements
parametre : l'adresse de la pile
retour : taille de la pile */
int tailleP(t_pile*f);

/* enpiler une nouvelle donnee
parametres : l'adresse de la pile, l'adresse de la donnee */
void empiler(t_pile*f,void*data);

/* depiler le prochain element
parametre : l'adresse de la pile
retour : l'adresse de la donnee*/
void* depiler(t_pile*f);

/* acceder au prochain element (donnee en tete)
parametre : l'adresse de la pile
retour : adresse de la donnee au sommet de la pile */
void* sommet(t_pile*f);




#endif //PILE_H
