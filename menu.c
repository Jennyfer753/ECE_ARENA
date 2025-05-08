#include <stdio.h>
#include <allegro.h>
#include "menu.h"
#include "gestion_sons.h"

void ecran_menu(BITMAP* buffer) {
    clear_bitmap(buffer);
    textout_ex(buffer, font, "ECE ARENA", 370,200, makecol(255, 255, 255), -1);

    rectfill(buffer,300,250,500,290,makecol(255, 0, 0));
    textout_centre_ex(buffer, font, "JOUER", 400, 262, makecol(255, 255, 255), -1);

    rectfill(buffer,300,330,500,370,makecol(255, 0, 0));
    textout_centre_ex(buffer, font, "QUITTER", 400, 342, makecol(255, 255, 255), -1);

    if (mouse_x >= 300 && mouse_x <= 500 && mouse_y >= 250 && mouse_y <= 290 ) {
        rect(buffer, 290, 240, 510, 300, makecol(0, 255, 0));
        textout_ex(buffer, font, ">", 310, 262, makecol(255, 255, 255), -1);
    }
    if(mouse_x >= 300 && mouse_x <= 500 && mouse_y >= 330 && mouse_y <= 370) {
        rect(buffer, 290, 320, 510, 380, makecol(0, 255, 0));
        textout_ex(buffer, font, ">", 310, 342, makecol(255, 255, 255), -1);

    }
}

void config_partie(BITMAP* buffer,  int* etat_son) {

    bouton_son(buffer, etat_son); // affichage du bouton son

    if ((mouse_b & 1) &&
        (mouse_x - 770)*(mouse_x - 770) + (mouse_y - 570)*(mouse_y - 570) <= 15*15) {
        clic(mouse_x, mouse_y, etat_son);
        while (mouse_b & 1) {} // attendre le relâchement du clic
        }

    rectfill(buffer, 220, 200, 380, 250, makecol(255, 0, 0));
    textout_centre_ex(buffer, font, "Partie à 2", 300, 215, makecol(255, 255, 255), -1);
    if (mouse_x >= 220 && mouse_x <= 380 && mouse_y >= 200 && mouse_y <= 250 ) {
        rect(buffer, 210, 190, 390, 260, makecol(200, 0, 200));
        textout_ex(buffer, font, ">", 230, 215, makecol(255, 255, 255), -1);
    }

    rectfill(buffer, 420, 200, 580, 250, makecol(0, 255, 0));
    textout_centre_ex(buffer, font, "Partie à 3", 500, 215, makecol(255, 255, 255), -1);
    if(mouse_x >= 420 && mouse_x <= 580 && mouse_y >= 200 && mouse_y <= 250) {
        rect(buffer, 410, 190, 590, 260, makecol(200, 0, 200));
        textout_ex(buffer, font, ">", 430, 215, makecol(255, 255, 255), -1);
    }

    rectfill(buffer, 320, 280, 480, 330, makecol(0, 0, 255));
    textout_centre_ex(buffer, font, "Partie à 4", 400, 295, makecol(255, 255, 255), -1);
    if(mouse_x >= 320 && mouse_x <= 480 && mouse_y >= 280 && mouse_y <= 330) {
        rect(buffer, 310, 270, 490, 340, makecol(200, 0, 200));
        textout_ex(buffer, font, ">", 330, 295, makecol(255, 255, 255), -1);
    }
}
