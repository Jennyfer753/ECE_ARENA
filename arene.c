#include "arene.h"
// Fonction qui dessine l'arène de jeu sur le bitmap buffer
void arene(BITMAP* buffer) {

    int arene[13][15] = {0};// Déclaration d'une grille vide de 13 lignes et 15 colonnes
    int taille_case = 40;// Taille de chaque case en pixels
    int nb_lignes = 13; // Nombre de lignes et de colonnes
    int nb_colonnes = 15;
    int decalage_x = 20;// Décalage horizontal pour décaler l’arène vers la droite de 20 pixels
    int decalage_y = (600 - nb_lignes * taille_case) / 2;// Décalage vertical pour centrer l’arène verticalement

    for (int ligne = 0; ligne < nb_lignes; ligne++) {  // Parcours de chaque case de la grille en ligne et en colonne
        for (int colonne = 0; colonne < nb_colonnes; colonne++) {
            // Calcul des coordonnées du coin supérieur gauche de la case
            int x = decalage_x + colonne * taille_case;
            int y = decalage_y + ligne * taille_case;
            int couleur;// Couleur de remplissage selon la valeur de la case
            if (arene[ligne][colonne] == 0) {
                couleur = makecol(0, 0, 0);// Couleur noire pour les cases vides
            }
            else {
                couleur = makecol(100, 100, 100);// Gris si la case a une autre valeur (obstacles)
            }
            rectfill(buffer, x, y, x + taille_case - 1, y + taille_case - 1, couleur);// Remplissage de la case avec la couleur définie
            rect(buffer, x, y, x + taille_case - 1, y + taille_case - 1, makecol(255, 255, 255));  // Dessin du contour blanc de la case
        }
    }
}
