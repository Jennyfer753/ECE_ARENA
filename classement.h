
#ifndef CLASSEMENT_H
#define CLASSEMENT_H

#include "parties.h"
#include <allegro.h>
#include <stdlib.h>
#include "pile.h"
#include "allegro_init.h"
#define MAX_PILE 10
int classement();

typedef struct {
    init_joueurs* elements[MAX_PILE];
    int sommet;
} Pile_classement;

#endif //CLASSEMENT_H
