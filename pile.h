#include "pile.h"
#include <stdlib.h>
#include <stdio.h>

void init_pile(t_pile*p){
    p->sommet=NULL;
    p->taille=0;
}

char pileVide(t_pile*p){
    if(p->sommet==NULL) return 1;
    else return 0;
}

int tailleP(t_pile*p){
    return p->taille;
}

void empiler(t_pile*p,void*data){
    t_maillonP* nouveau;
    nouveau=malloc(sizeof(t_maillonP));
    nouveau->data=data;
    nouveau->suivant=p->sommet;
    p->sommet=nouveau;
    (p->taille)++;
}

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
}

