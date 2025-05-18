#include <stdio.h>
#include <allegro.h>
#include "gestion_sons.h"

BITMAP* charger_son_on() {
    BITMAP* img = load_bitmap("son_on.bmp", NULL);
    if (!img) {
        allegro_message("Erreur chargement img_son_on.bmp");
        exit(1);
    }
    return img;
}

BITMAP* charger_son_off() {
    BITMAP* img = load_bitmap("son_off.bmp", NULL);
    if (!img) {
        allegro_message("Erreur chargement img_son_of.bmp");
        exit(1);
    }
    return img;
}

void init_son(int* etat_son) {
    * etat_son = 1;
}

void bouton_son(BITMAP* buffer, int* etat_son, BITMAP* img_son_on, BITMAP* img_son_off) {
    if (*etat_son == 1 && img_son_on) {
        draw_sprite(buffer, img_son_on, 755, 555); // image 30x30 centrée sur 770x570
    } else if (*etat_son == 0 && img_son_off) {
        draw_sprite(buffer, img_son_off, 755, 555);
    }
}

void clic(int x, int y, int* etat_son, SAMPLE* melodie_menu, BITMAP* buffer, BITMAP* img_son_on, BITMAP* img_son_off) {
    if ((x - 770)*(x - 770) + (y - 570)*(y - 570) <= 15*15) {
        *etat_son = !(*etat_son); // inverse le son

        if (*etat_son == 0) {
            stop_sample(melodie_menu);
            textout_ex(screen, font, "Le son n'est plus actif", 330, 150, makecol(255, 255, 255), -1);
        } else {
            play_sample(melodie_menu, 255, 128, 1000, 1);
            textout_ex(screen, font, "Le son est actif", 330, 150, makecol(255, 255, 255), -1);
        }

        bouton_son(buffer, etat_son, img_son_on, img_son_off); // met à jour l'image
        blit(buffer, screen, 0, 0, 0, 0, 800, 600);
        rest(1000);
    }
}

