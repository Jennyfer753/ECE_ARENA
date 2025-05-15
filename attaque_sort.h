// attaque_sort.h
#ifndef ATTAQUE_SORT_H
#define ATTAQUE_SORT_H

#include <allegro.h>

// Définition de la structure Sort
typedef struct {
    int pv_retire_min;
    int pv_retire_max;
    int pa_requis;
    char nom[30];
    int portee_min;
    int portee_max;
    int chance_echec;
    int zone_effet; // 0 = cible unique, 1 = cases adjacentes, etc.
    BITMAP* animation[10]; // Tableau pour les frames d'animation
    int nb_frames;
    int frame_delay; // Délai entre chaque frame
} Sort;

typedef struct {
    Sort sorts[4]; // Chaque personnage a 4 sorts
    char nom_classe[50];
    BITMAP* sprite;
} ClassePersonnage;

// Prototypes des fonctions
void initialiser_sort(Sort* sort, const char* nom, int pv_min, int pv_max, int pa, 
                     int portee_min, int portee_max, int echec, int zone);
void charger_animations_sort(Sort* sort, const char* prefixe_nom_fichier);
void liberer_sort(Sort* sort);

// Fonctions pour initialiser les sorts de chaque classe
void initialiser_sorts_mage(ClassePersonnage* classe);
void initialiser_sorts_maitresse_dragon(ClassePersonnage* classe);
void initialiser_sorts_savant_fou(ClassePersonnage* classe);
void initialiser_sorts_archere(ClassePersonnage* classe);

// Fonctions pour lancer les sorts
int lancer_sort(Sort* sort, int x_source, int y_source, int x_cible, int y_cible, 
               BITMAP* buffer, int* frame_counter);
void afficher_portee_sort(Sort* sort, int x_source, int y_source, 
                         int** grille, int largeur, int hauteur, BITMAP* buffer);

#endif // ATTAQUE_SORT_H
