
#include "classement.h"
#include "menu.h"

int classement(Pile_classement* pile) {
    BITMAP *buffer;
    BITMAP *background;

    buffer = create_bitmap(SCREEN_W, SCREEN_H);
    if (!buffer) {
        allegro_message("Erreur création du buffer");
        return 1;
    }
/*
    background = load_bitmap("classement_resized.bmp", NULL);
    if (!background) {
        allegro_message("Erreur chargement de classement_resized.bmp");
        destroy_bitmap(buffer);
        return 1;
    }*/

    show_mouse(screen);

    while (!key[KEY_ESC]) {
        clear_bitmap(buffer);  // Pas d'image, on efface l'écran en noir

        // --- DESSIN DES 4 CASES DE CLASSEMENT ---
        rect(buffer, 125, 160, 675 , 225, makecol(40,54,39));  // 1er
        rect(buffer, 125, 242, 675 , 305, makecol(40,54,39));  // 2e
        rect(buffer, 125, 322, 675 , 385, makecol(40,54,39));  // 3e
        rect(buffer, 125, 402, 675 , 467, makecol(40,54,39));  // 4e

        // --- DESSIN DES DEUX BOUTONS DU BAS ---
        rect(buffer, 88, 495, 346 , 555, makecol(70,31,2));    // Bouton gauche
        rect(buffer, 454, 495, 712 , 555, makecol(70,31,2));   // Bouton droit

        // --- TEXTES DANS LES BOUTONS ---
        textout_centre_ex(buffer, font, "Rejouer autre partie", (88 + 346)/2, 520, makecol(255, 255, 255), -1);
        textout_centre_ex(buffer, font, "Rejouer meme partie", (454 + 712)/2, 520, makecol(255, 255, 255), -1);

        // --- AFFICHAGE DES NOMS ---
        int posX = 140;
        int positionsY[] = {180, 260, 340, 420};
        Pile_classement temp = *pile;
        for (int i = 0; i < 4 && !pileVide(&temp); i++) {
            init_joueurs* j = depiler(&temp);
            textout_ex(buffer, font, j->nom, posX, positionsY[i], makecol(255, 255, 255), -1);
        }

        // --- GESTION DU CLIC SOURIS ---
        if (mouse_b & 1) {
            if (mouse_x >= 88 && mouse_x <= 346 && mouse_y >= 495 && mouse_y <= 555) {
                return 1;
            }
            if (mouse_x >= 454 && mouse_x <= 712 && mouse_y >= 495 && mouse_y <= 555) {
                ecran_menu(buffer);
                break;
            }
        }

        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        rest(16);
    }


    destroy_bitmap(buffer);
    //destroy_bitmap(background);
    return 0;
}
