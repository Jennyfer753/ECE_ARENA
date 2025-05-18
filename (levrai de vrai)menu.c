#include "menu.h"
#include <allegro.h>
#include <stdio.h>

BITMAP* charger_img_menu() {
    BITMAP* img = load_bitmap("img_menu.bmp", NULL);
    if (!img) {
        allegro_message("Erreur chargement img_menu.bmp");
        exit(1);
    }
    return img;
}

void ecran_menu(BITMAP* buffer, BITMAP* img_menu) {

    if (img_menu) {
        draw_sprite(buffer, img_menu, 0, 0);
    } else {
        clear_bitmap(buffer);
    }

    // bouton jouer
    rectfill(buffer, 200, 330, 380, 370, makecol(110, 75, 40));
    textout_centre_ex(buffer, font, "JOUER", 290, 342, makecol(255, 255, 255), -1);

    // bouton quitter
    rectfill(buffer, 420, 330, 600, 370, makecol(110, 75, 40));
    textout_centre_ex(buffer, font, "QUITTER", 510, 342, makecol(255, 255, 255), -1);

    // Survol JOUER
    if (mouse_x >= 200 && mouse_x <= 380 && mouse_y >= 330 && mouse_y <= 370) {
        rect(buffer, 190, 320, 390, 380, makecol(224, 214, 25));
        textout_ex(buffer, font, ">", 210, 342, makecol(255, 255, 255), -1);
    }

    // Survol QUITTER
    if (mouse_x >= 420 && mouse_x <= 600 && mouse_y >= 330 && mouse_y <= 370) {
        rect(buffer, 410, 320, 610, 380, makecol(224, 214, 25));
        textout_ex(buffer, font, ">", 430, 342, makecol(255, 255, 255), -1);
    }
}

