#include <allegro.h>
#include <stdio.h>
#include "deplacement.h"
#include "joueurs.h"
#include "arene.h"
#include "gestion_states.h"
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
    if (ligne_max >= 600/ taille_case) ligne_max = (600/ taille_case) - 1;
    if (colonne_min < 0) colonne_min = 0;
    if (colonne_max >= 690 / taille_case) colonne_max = (690 / taille_case) - 1;

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


int deplacement(BITMAP* buffer, init_joueurs* j, int nb_joueurs, int index_joueur_actuel, int reset) {
    clear_bitmap(buffer);
    int taille_case = 50;
    static int joueur_choisi = -1;
    int largeur = 690 / taille_case;
    int hauteur = 600 / taille_case;
    static int position_prec = 0;
    int position_actuel = mouse_b & 1;

    int ligne_clic = mouse_y / taille_case;
    int colonne_clic = (mouse_x - 110) / taille_case;
    int distance;
    int case_occupee;

    if (reset) {
        joueur_choisi = -1;
        return 0;
    }

    if (position_actuel == 1 && position_prec == 0) {
        if (ligne_clic >= 0 && ligne_clic < hauteur && colonne_clic >= 0 && colonne_clic < largeur) {
            if (joueur_choisi == -1) {
                if (j[index_joueur_actuel].ligne == ligne_clic && j[index_joueur_actuel].colonne == colonne_clic) {
                    joueur_choisi = index_joueur_actuel;
                }
            } else {
                distance = calculeDistanceManhattan(j[joueur_choisi].ligne, j[joueur_choisi].colonne, ligne_clic, colonne_clic);
                case_occupee = verificationCaseVide(ligne_clic, colonne_clic, j, nb_joueurs, joueur_choisi);

                if (case_occupee == 0 && distance <= j[joueur_choisi].pm) {
                    j[joueur_choisi].ligne = ligne_clic;
                    j[joueur_choisi].colonne = colonne_clic;
                    j[joueur_choisi].pm -= distance; // Consommer les PM
                }

                joueur_choisi = -1;
            }
        } else {
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
        if (i == index_joueur_actuel) {
            circle(buffer, x, y, 25, makecol(0, 255, 0));
        }
    }

    position_prec = position_actuel;
    state(buffer, j, nb_joueurs, taille_case);
    return 0;
}



