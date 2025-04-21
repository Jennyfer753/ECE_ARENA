#include <allegro.h>
#include <stdio.h>
#include "deplacement.h"
#include "1v1.h"
#include "joueurs.h"

void init_1v1(BITMAP* buffer) {
    init_joueurs joueur[2] ={
        {1, 5, makecol(255, 0, 0)},
        {10, 5, makecol(0, 255, 0)}};

    while (!key[KEY_ESC]) {
        clear_bitmap(buffer);
        deplacement(buffer, joueur, 2);
        blit(buffer, screen, 0, 0, 0, 0, 800, 600);
    }
}
