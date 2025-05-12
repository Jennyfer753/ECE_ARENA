#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "allegro_init.h"

// Le code suivant a été pris d'un video youtube de la chaine "Remilulz_91 - Programmations" sur le chronometre
// mais elle a apres été modifié pour que ça reponde aux attentes du projet

void my_delay(int i) {
    clock_t start = clock();
    while (clock() - start < i * CLOCKS_PER_SEC);
}

int temps(BITMAP* buffer) {
    static int timerseconde1 = 0, timerseconde2 = 0;
    char temps_str[10];
    // Incrémentation des secondes
    if (timerseconde2 == 9) {
        timerseconde1++;
        timerseconde2 = -1;
    }
    timerseconde2++;

    // Affichage graphique
    rectfill(buffer, 740, 25, 775, 40, makecol(255, 0, 0));
    sprintf(temps_str, "%d%d", timerseconde1, timerseconde2);
    textout_ex(buffer, font, temps_str, 750, 30, makecol(255, 255, 255), -1);

    my_delay(1); // Attend 1 seconde

    // Si 15 secondes écoulées, retourne 1
    if (timerseconde1 == 1 && timerseconde2 == 5) {
        timerseconde1 = 0;
        timerseconde2 = 0;
        return 1;
    }

    return 0;
}
