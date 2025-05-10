//
// Created by alois on 05/05/2025.
//

#ifndef TOURS_H
#define TOURS_H
#include <stdlib.h>
#include <time.h>
#include "file.h"
#include "joueurs.h"

typedef struct {
    char nom[50];
    // tu peux ajouter des champs ici (PV, etc.)
} tours_joueurs;

void initialiser_file_tours(t_file* file, init_joueurs* joueurs, int nb_joueurs);


#endif //TOURS_H
