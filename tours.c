#include "tours.h"
#include "deplacement.h"
#include <time.h>
#include "file.h"
#include <stdlib.h>
#include <time.h>
#include "file.h"

// Fonction de mélange des indices
void melanger_indices(int* indices, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = indices[i];
        indices[i] = indices[j];
        indices[j] = temp;
    }
}

// Fonction pour mélanger les joueurs et les enfiler dans la file
void initialiser_file_tours(t_file* file, init_joueurs* joueurs, int nb_joueurs) {
    int indices[nb_joueurs];  // Tableau pour stocker les indices des joueurs
    for (int i = 0; i < nb_joueurs; i++) {
        indices[i] = i;  // Initialiser les indices avec les numéros des joueurs
    }

    // Mélanger les indices aléatoirement
    melanger_indices(indices, nb_joueurs);

    // Initialiser la file
    init_file(file);

    // Enfiler les joueurs dans l'ordre aléatoire
    for (int i = 0; i < nb_joueurs; i++) {
        enfiler(file, &joueurs[indices[i]]);  // Enfiler le joueur à l'indice mélangé
    }
}
