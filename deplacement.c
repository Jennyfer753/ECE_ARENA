#include <allegro.h>
#include "deplacement.h"
#include "joueurs.h"
#include "arene.h"

void zonesDeplacement(BITMAP* buffer, int ligne_joueur, int colonne_joueur, int taille_case, init_joueurs* joueurs, int nb_joueurs) {

    int couleur_libre;
    int couleur_occupee;
    int ligne_min;
    int ligne_max;
    int colonne_min;
    int colonne_max;
    int diff_colonne;
    int diff_ligne;
    int distance;
    int occupee;
    int couleur;

    couleur_libre = makecol(0, 255, 0);
    couleur_occupee = makecol(255, 0, 0);
    ligne_min = ligne_joueur - 3;
    ligne_max = ligne_joueur + 3;
    colonne_min = colonne_joueur - 3;
    colonne_max = colonne_joueur + 3;

    if (ligne_min < 0) ligne_min = 0;
    if (ligne_max >= SCREEN_H / taille_case) ligne_max = (SCREEN_H / taille_case) - 1;
    if (colonne_min < 0) colonne_min = 0;
    if (colonne_max >= (SCREEN_W - 110) / taille_case) colonne_max = ((SCREEN_W - 110) / taille_case) - 1;

    for (int ligne = ligne_min; ligne <= ligne_max; ligne++) {
        for (int colonne = colonne_min; colonne <= colonne_max; colonne++) {
            diff_ligne = ligne_joueur - ligne;
            diff_colonne = colonne_joueur - colonne;
            if (diff_ligne < 0) diff_ligne = -diff_ligne;
            if (diff_colonne < 0) diff_colonne = -diff_colonne;

            distance = diff_ligne + diff_colonne;

            if (distance > 0 && distance <= 3) {
                int i = 0;
                occupee = 0;
                while (i < nb_joueurs) {
                    if (joueurs[i].ligne == ligne && joueurs[i].colonne == colonne) {
                        occupee = 1;
                        i = nb_joueurs;
                    } else {
                        i = i + 1;
                    }
                    if (occupee == 1) {
                        couleur = couleur_occupee;
                    } else {
                        couleur = couleur_libre;
                    }
                }
                int x1 = 110 + colonne * taille_case;
                int y1 = ligne * taille_case;
                drawing_mode(DRAW_MODE_TRANS, NULL, 0, 0);
                set_trans_blender(0, 0, 0, 128);
                rectfill(buffer, x1, y1, x1 + taille_case - 1, y1 + taille_case - 1, couleur);
                solid_mode();
            }
        }
    }
}

int verificationCaseVide (int ligne, int colonne, init_joueurs* joueurs, int nb_joueurs, int joueur_actuel) {
    for (int i = 0; i < nb_joueurs; i++) {
        if (i != joueur_actuel &&
            joueurs[i].ligne == ligne &&
            joueurs[i].colonne == colonne) {
            return 1;
        }
    }
    return 0;
}

int calculeDistanceManhattan(int ligne1, int colonne1, int ligne2, int colonne2){
    int diff_ligne;
    int diff_colonne;

    diff_ligne = ligne1 - ligne2;
    diff_colonne = colonne1 - colonne2;
    if (diff_ligne < 0) diff_ligne = -diff_ligne;
    if (diff_colonne < 0) diff_colonne = -diff_colonne;
    return diff_ligne + diff_colonne;
}

void deplacement(BITMAP* buffer, init_joueurs* j, int nb_joueurs) {
    clear_bitmap(buffer);
    int taille_case = 50;
    static int joueur_choisi = -1;
    int largeur = (SCREEN_W - 110) / taille_case;
    int hauteur = SCREEN_H / taille_case;
    static int position_prec = 0;
    int position_actuel = mouse_b & 1;

    int ligne_clic = mouse_y / taille_case;
    int colonne_clic = (mouse_x - 110) / taille_case;
    int distance;
    int case_occupee;

    if (position_actuel == 1 && position_prec == 0) {
        if (ligne_clic >= 0 && ligne_clic < hauteur && colonne_clic >= 0 && colonne_clic < largeur) {
            if (joueur_choisi == -1) {
                for (int i = 0; i < nb_joueurs; i++) {
                    if (j[i].ligne == ligne_clic && j[i].colonne == colonne_clic) {
                        joueur_choisi = i;
                    }
                }
            }
            else{
                 distance = calculeDistanceManhattan(j[joueur_choisi].ligne, j[joueur_choisi].colonne, ligne_clic, colonne_clic);
                 case_occupee = verificationCaseVide(ligne_clic, colonne_clic, j, nb_joueurs, joueur_choisi);

                if (case_occupee == 0 && distance <= 3) {
                    j[joueur_choisi].ligne = ligne_clic;
                    j[joueur_choisi].colonne = colonne_clic;
                }
                joueur_choisi = -1;
            }
        }
        else{
            joueur_choisi = -1;
        }
    }

    arene(buffer);

    if (joueur_choisi != -1) {
        zonesDeplacement(buffer, j[joueur_choisi].ligne, j[joueur_choisi].colonne, taille_case, j, nb_joueurs);
    }

    for (int i = 0; i < nb_joueurs; i++) {
        int x = 110 + j[i].colonne * taille_case + taille_case / 2;
        int y = j[i].ligne * taille_case + taille_case / 2;
        circlefill(buffer, x, y, 20, j[i].couleur);
        if (i == joueur_choisi) {
            circle(buffer, x, y, 25, makecol(0, 255, 0));
        }
    }
    position_prec = position_actuel;
}
