#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "allegro_init.h"

// Affiche le chrono et retourne 1 quand 15 secondes sont écoulées
int temps(BITMAP* buffer) {
    static clock_t start_time = 0;
    static int secondes = 0;
    char temps_str[10];

    if (start_time == 0) {
        start_time = clock();  // Initialisation au premier appel
    }

    // Met à jour les secondes si une nouvelle seconde s'est écoulée
    clock_t elapsed = (clock() - start_time) / CLOCKS_PER_SEC;
    if (elapsed > secondes) {
        secondes = elapsed;
    }

    // Affichage graphique du compteur de secondes
    rectfill(buffer, 740, 25, 775, 40, makecol(255, 0, 0));
    sprintf(temps_str, "%02d", secondes);
    textout_ex(buffer, font, temps_str, 750, 30, makecol(255, 255, 255), -1);

    // Si 15 secondes écoulées, réinitialiser et retourner 1
    if (secondes >= 15) {
        secondes = 0;
        start_time = clock(); // Redémarrer le timer
        return 1;
    }

    return 0;
}

