//
// Created by Admin on 20/04/2025.
//

#ifndef ATTAQUE_SORT_H
#define ATTAQUE_SORT_H

#endif //ATTAQUE_SORT_H

typedef struct Sort{
    int pv_retire;
    int cout_pa;
    char nom[30];
    int portee_min;
    int portee_max;

}Sort;

void attaque_sort_mage(Sort* sort );
void attaque_sort_maitresse(Sort* sort );
void attaque_sort_savant(Sort* sort );
void attaque_sort_archère(Sort* sort );


