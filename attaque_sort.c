#include "attaque_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <allegro.h>

#define TAILLE_CASE 50

// Initialisation d'un sort avec ses caractéristiques de base
void initialiser_sort(Sort* sort, const char* nom, int pv_min, int pv_max, int pa, int portee_min, int portee_max, int echec, int zone) {
    strcpy(sort->nom, nom);
    sort->pv_retire_min = pv_min;
    sort->pv_retire_max = pv_max;
    sort->pa_requis = pa;
    sort->portee_min = portee_min;
    sort->portee_max = portee_max;
    sort->chance_echec = echec;
    sort->zone_effet = zone;
    sort->nb_frames = 0;
    sort->frame_delay = 5;
}

// On charge les frames d'animation d'un sort
void charger_animations_sort(Sort* sort, const char* prefixe_nom_fichier) {
    char filename[100];
    int i = 0;

    while (i < 10) { // Limité à 10 frames max
        sprintf(filename, "%s%d.bmp", prefixe_nom_fichier, i);
        sort->animation[i] = load_bitmap(filename, NULL);
        if (!sort->animation[i]) break; // Arrêt si fichier introuvable
        i++;
    }

    sort->nb_frames = i;
}

/**INITIALISATION DES SORTS DES PERSONNAGES**/

// Initialisation des sorts du Mage
void initialiser_sorts_mage(ClassePersonnage* classe) {
    strcpy(classe->nom_classe, "Mage");

    // Sort 1: Pluie de glace
    initialiser_sort(&classe->sorts[0], "Pluie de glace", 10, 15, 3, 2, 5, 10, 1);
    charger_animations_sort(&classe->sorts[0], "mage_pluie_de_glace_");

    // Sort 2: Sac de feu
    initialiser_sort(&classe->sorts[1], "Sac de feu", 15, 20, 4, 1, 3, 15, 0);
    charger_animations_sort(&classe->sorts[1], "mage_sac_de_feu_");

    // Sort 3: Tornade
    initialiser_sort(&classe->sorts[2], "Tornade", 13, 25, 4, 4, 7, 5, 0);
    charger_animations_sort(&classe->sorts[2], "mage_tornade_");

}

//Initialisation des sorts de la Maitresse dragon
void initialiser_sorts_maitresse(ClassePersonnage* classe) {
    // Sort 1 : Bébé dragon
    initialiser_sort(&classe->sorts[0], "Bébé dragon", 12, 15, 3, 2, 5, 10, 1);
    charger_animations_sort(&classe->sorts[0], "maitresse_bebe_dragon_");

    // Sort 2 : Multiples boules de feu
    initialiser_sort(&classe->sorts[1], "Multiples boules de feu", 15, 20, 4, 1, 3, 15, 0);
    charger_animations_sort(&classe->sorts[1], "maitresse_plusieurs_boules_");

    // Sort 3: Susano
    initialiser_sort(&classe->sorts[2], "Susano", 13, 25, 4, 4, 7, 5, 0);
    charger_animations_sort(&classe->sorts[2], "maitresse_susano_");

    // Sort 4 : Unique boule de feu
    initialiser_sort(&classe->sorts[3], "Unique boule de feu", 13, 25, 4, 4, 7, 5, 0);
    charger_animations_sort(&classe->sorts[3], "maitresse_unique_boule_");
}

//Initialisation des sorts de l'Archère
void initialiser_sorts_archere(ClassePersonnage* classe) {
    // Sort 1 : Tir unique
    initialiser_sort(&classe->sorts[0], "Tir unique", 10, 15, 3, 2, 5, 10, 1);
    charger_animations_sort(&classe->sorts[0], "archere_tir_unique_");

    // Sort 2: Tir multiple
    initialiser_sort(&classe->sorts[1], "Tir multiple", 15, 20, 4, 1, 3, 15, 0);
    charger_animations_sort(&classe->sorts[1], "archere_tir_multiple_");

    // Sort 3 : Flèche empoisonée
    initialiser_sort(&classe->sorts[2], "Flèche empoisonée", 13, 25, 4, 1, 3, 15, 0);
    charger_animations_sort(&classe->sorts[2], "archere_fleche_empoisonee_");

    // Sort 4: Flèche foudroyante
    initialiser_sort(&classe->sorts[3], "Flèche foudroyante", 13, 25, 4, 1, 3, 15, 0);
    charger_animations_sort(&classe->sorts[3], "archere_fleche_foudroyante_");
}

//Initialisation des sorts du Savant fou 
void initialiser_sorts_savant_fou(ClassePersonnage* classe) {
    // Sort 1: Bombe
    initialiser_sort(&classe->sorts[0], "Bombe", 10, 15, 3, 2, 5, 10, 1);
    charger_animations_sort(&classe->sorts[0], "savant_fou_bombe_");

    // Sort 2: Canon
    initialiser_sort(&classe->sorts[1], "Canon", 10, 15, 3, 2, 5, 10, 1);
    charger_animations_sort(&classe->sorts[1], "savant_fou_canon_");

    // Sort 3 : Mitraillette
    initialiser_sort(&classe->sorts[2], "Mitraillette", 13, 25, 4, 1, 3, 15, 0);
    charger_animations_sort(&classe->sorts[2], "savant_fou_mitraillette_");

    // Sort 4: Super bazooka
    initialiser_sort(&classe->sorts[3], "Super bazooka", 13, 25, 4, 1, 3, 15, 0);
    charger_animations_sort(&classe->sorts[3], "savant_fou_bazooka_");
}

// Libère les bitmaps des animations d'un sort
void liberer_sort(Sort* sort) {
    for (int i = 0; i < sort->nb_frames; i++) {
        if (sort->animation[i]) {
            destroy_bitmap(sort->animation[i]);
        }
    }
}

// Affiche la portée du sort sur la grille (cases vertes)
void afficher_portee_sort(Sort* sort, int x_source, int y_source, int** grille, int largeur, int hauteur, BITMAP* buffer) {
    for (int y = 0; y < hauteur; y++) {
        for (int x = 0; x < largeur; x++) {
            int distance = abs(x - x_source) + abs(y - y_source);
            if (distance >= sort->portee_min && distance <= sort->portee_max && grille[y][x] == 1) {
                rectfill(buffer, x * TAILLE_CASE, y * TAILLE_CASE, (x + 1) * TAILLE_CASE, (y + 1) * TAILLE_CASE, makecol(0, 255, 0));
            }
        }
    }
}

// Fonction pour lancer de sort avec animation et calcul des dégâts infligés 
int lancer_sort(Sort* sort, int x_cible, int y_cible, BITMAP* buffer) {
    static int frame_actuelle = 0;
    static int delay_counter = 0;

    if (frame_actuelle < sort->nb_frames) {
        int anim_x = x_cible * TAILLE_CASE;
        int anim_y = y_cible * TAILLE_CASE;
        draw_sprite(buffer, sort->animation[frame_actuelle], anim_x, anim_y);

        delay_counter++;
        if (delay_counter >= sort->frame_delay) {
            delay_counter = 0;
            frame_actuelle++;
        }
        return 0; // Animation en cours
    } else {
        frame_actuelle = 0;
        delay_counter = 0;
        srand(time(NULL));
        if (rand() % 100 < sort->chance_echec) {
            return 0; // Le sort a échoué.
        }
        return sort->pv_retire_min + rand() % (sort->pv_retire_max - sort->pv_retire_min + 1);
    }
}

