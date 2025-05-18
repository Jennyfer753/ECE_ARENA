//
// Created by alois on 18/05/2025.
//

#include "pile.h"
#include <stdlib.h>
#include <stdio.h>

/**SOUS-PROGRAMMES PROVENANT DU COURS SUR BOOSTCAMP**/
void init_pile(t_pile*p){
    p->sommet=NULL;
    p->taille=0;
}//On initialise une pile

char pileVide(t_pile*p){
    if(p->sommet==NULL) return 1;
    else return 0;
}// On initialise une pile vide

int tailleP(t_pile*p){
    return p->taille;
}//La taille de la pile

//Sous-programme pour empiler des éléments dans la pile
void empiler(t_pile*p,void*data){
    t_maillonP* nouveau;
    nouveau=malloc(sizeof(t_maillonP));
    nouveau->data=data;
    nouveau->suivant=p->sommet;
    p->sommet=nouveau;
    (p->taille)++;
}

//Sous-programme pour dépiler des éléments de la pile
void* depiler(t_pile*p){
    t_maillonP*temp;
    void* data=NULL;
    //si liste non vide
    if(p->sommet!=NULL){
        temp=p->sommet;
        p->sommet=p->sommet->suivant;
        data=temp->data;
        free(temp);
        (p->taille)--;
    }
    return data;
}

void* sommet(t_pile*p){
    return p->sommet->data;
}//Le sommet de la pile

