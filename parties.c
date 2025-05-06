
#include <allegro.h>
#include <stdio.h>
#include "deplacement.h"
#include "parties.h"
#include "joueurs.h"


void init_1v1(BITMAP* buffer) {

    init_joueurs joueur[2] ={
        {1, 5, makecol(255, 0, 0), 100, 10,25,"undef","J1"},
        {10, 5, makecol(0, 255, 0),100, 10,25,"undef","J2"}};

    while (!key[KEY_ESC]) {
        clear_bitmap(buffer);
        deplacement(buffer, joueur, 2);
        blit(buffer, screen, 0, 0, 0, 0, 800, 600);
    }
}


void init_1v1v1(BITMAP* buffer) {
    init_joueurs joueur[3] ={
        {1, 5, makecol(255, 0, 0), 100, 25,10,"undef","J1"},
        {10, 5, makecol(0, 255, 0),100, 10,25,"undef","J2"},
        { 5,1,makecol(0,0,255), 100, 10,25,"undef","J3"}};

    while (!key[KEY_ESC]) {
        clear_bitmap(buffer);
        deplacement(buffer, joueur, 3);
        blit(buffer, screen, 0, 0, 0, 0, 800, 600);
    }
}


void init_1v1v1v1(BITMAP* buffer) {
    init_joueurs joueur[4] ={
        {1, 5, makecol(255, 0, 0), 100, 10,25,"undef","J1"},
        {10, 5, makecol(0, 255, 0), 100, 10,25,"undef","J2"},
        { 5,1,makecol(0,0,255), 100, 10,25,"undef","J3"},
        {5,10,makecol(255,255,255), 100, 10,25,"undef","J4"}};

    while (!key[KEY_ESC]) {
        clear_bitmap(buffer);
        deplacement(buffer, joueur, 4);
        blit(buffer, screen, 0, 0, 0, 0, 800, 600);
    }
}
