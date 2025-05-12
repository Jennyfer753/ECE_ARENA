//
// Created by Admin on 20/04/2025.
//

#ifndef ATTAQUE_SORT_H
#define ATTAQUE_SORT_H

#include <allegro.h>

// Définition de la structure Sort
typedef struct Sort {
    int pv_retire;
    int cout_pa;
    char nom[30];
    int portee_min;
    int portee_max;
} Sort;

// Prototypes des sorts du Mage
void sort_pluie_de_glace(Sort* sort);
void sort_sac_de_feu(Sort* sort);
void sort_tornade(Sort* sort);
void sort_cercueil_de_boue(Sort* sort);

// Prototypes des sorts de la Maîtresse Dragon
void sort_boule_de_feu(Sort* sort);
void sort_multi_boule_de_feu(Sort* sort);
void sort_bebe_dragon_feu(Sort* sort);
void sort_susano_dragon(Sort* sort);

// Prototypes des sorts du Savant Fou
void sort_bombe(Sort* sort);
void sort_canon(Sort* sort);
void sort_mitraillette(Sort* sort);
void sort_super_bazooka(Sort* sort);

// Prototypes des sorts de l’Archère
void sort_tir_normal(Sort* sort);
void sort_tir_multiple(Sort* sort);
void sort_fleche_poison(Sort* sort);
void sort_fleche_foudre(Sort* sort);

#endif //ATTAQUE_SORT_H
