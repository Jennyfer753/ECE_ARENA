#include <allegro.h>
#include "gestion_sons.h"

void init_son(int* etat_son) {
    * etat_son = 1;
}

void bouton_son(BITMAP* buffer, int* etat_son) {
        if (*etat_son == 1) {
            circlefill(buffer, 770, 570, 15, makecol(255, 255, 0));
        } else {
            circlefill(buffer, 770, 570, 15, makecol(100, 100, 100));
        }
}

void clic(int x, int y, int* etat_son) {
    if ((x - 770)*(x - 770) + (y - 570)*(y - 570) <= 15*15) {
        if (*etat_son == 1) {
            *etat_son = 0;
            textout_ex(screen, font, "Le son n'est plus actif", 330, 150, makecol(255, 255, 255), -1);
        }
        else {
            *etat_son = 1;
            textout_ex(screen, font, "Le son est actif", 330, 150, makecol(255, 255, 255), -1);
        }
        blit(screen, screen, 0, 0, 0, 0, 800, 600);
        rest(1000);
    }
}
