#include <allegro.h>
#include <stdio.h>
#include "deplacement.h"
#include "parties.h"
#include "joueurs.h"
#include "selection_joueurs.h"
#include "classes.h"


void init_1v1(BITMAP *buffer) {
    ClassePersonnage classes[4];
    charger_classes(classes);
    init_joueurs joueurs[2];

    if (selection_joueurs(buffer, joueurs, 2, classes, 4)) {
        while (!key[KEY_ESC]) {
            clear_bitmap(buffer);
            deplacement(buffer, joueurs, 2);
            blit(buffer, screen, 0, 0, 0, 0, 800, 600);
            rest(20);
        }
    }
}

void init_1v1v1(BITMAP* buffer) {
    ClassePersonnage classes[4];
    charger_classes(classes);
    init_joueurs joueurs[3];

    if (selection_joueurs(buffer, joueurs, 2, classes, 4)) {
        while (!key[KEY_ESC]) {
            clear_bitmap(buffer);
            deplacement(buffer, joueurs, 2);
            blit(buffer, screen, 0, 0, 0, 0, 800, 600);
        }
    }
}


void init_1v1v1v1(BITMAP* buffer) {
    ClassePersonnage classes[4];
    charger_classes(classes);
    init_joueurs joueurs[4];

    if (selection_joueurs(buffer, joueurs, 2, classes, 4)) {
        while (!key[KEY_ESC]) {
            clear_bitmap(buffer);
            deplacement(buffer, joueurs, 2);
            blit(buffer, screen, 0, 0, 0, 0, 800, 600);
        }
    }
}

