#include <allegro.h>
#include "1v1v1v1.h"
#include "joueurs.h"
#include "deplacement.h"

void init_1v1v1v1(BITMAP* buffer) {
    init_joueurs joueur[4] ={
        {1, 5, makecol(255, 0, 0)},
        {10, 5, makecol(0, 255, 0)},
        { 5,1,makecol(0,0,255)},
        {5,10,makecol(255,255,255)}};


    while (!key[KEY_ESC]) {
        clear_bitmap(buffer);
        deplacement(buffer, joueur, 4);
        blit(buffer, screen, 0, 0, 0, 0, 800, 600);
    }
}
