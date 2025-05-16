#include "parties.h"
#include "joueurs.h"
void init_1v1(BITMAP* buffer) {
    srand(time(NULL));

    init_joueurs joueur[2] = {
        {1, 5, makecol(255, 0, 0), 100, 10, 25,"classe", "J1"},
        {10, 5, makecol(0, 255, 0), 100, 10, 25, "classe", "J2"}
    };
    for (int g = 0; g < 2; g++) {
        while (mouse_b & 1) rest(10);  // <-- D'abord attendre que le clic soit relâché
        choix_perso(buffer, &joueur[g], g);  // Ensuite seulement appeler le choix
    }


    t_file file;
    initialiser_file_tours(&file, joueur, 2);

    static int tour_en_cours = 0;
    static init_joueurs* joueur_actuel = NULL;

    //Premier tour pour commencer
    if (joueur_actuel == NULL) {
        joueur_actuel = defiler(&file);
        tour_en_cours++;
    }
    reinit_temps();  // Remise à zéro du chrono pour chaque nouvelle partie


    while (!key[KEY_ESC]) {
        clear_bitmap(buffer);
        rectfill(buffer, 740, 25, 775, 40, makecol(255, 255, 0));
        textout_ex(buffer, font, "XX", 750, 30, makecol(0, 0, 0), -1);

        int index_actuel = joueur_actuel - joueur;

        // Si temps écoulé -> fin du tour
        if (temps(buffer)) {
            enfiler(&file, joueur_actuel);
            joueur_actuel = defiler(&file);
            joueur_actuel->pm = 10;
            reinit_temps();  // Repart à 15s pour le nouveau joueur
            tour_en_cours++;
        }

        // Actions autorisées tant que temps restant
        deplacement(buffer, joueur, 2, index_actuel, 0);

        // Affichage des joueurs
        for (int i = 0; i < 2; i++) {
            int x = 110 + joueur[i].colonne * 50 + 25;
            int y = joueur[i].ligne * 50 + 25;
            circlefill(buffer, x, y, 20, joueur[i].couleur);
            if (i == index_actuel) {
                circle(buffer, x, y, 25, makecol(0, 255, 0));
            }
        }

        blit(buffer, screen, 0, 0, 0, 0, 800, 600);
    }
}


void init_1v1v1(BITMAP* buffer) {
    srand(time(NULL));
    init_joueurs joueur[3] = {
        {1, 5, makecol(255, 0, 0), 100, 25, 10, "undef", "J1"},
        {10, 5, makecol(0, 255, 0), 100, 10, 25, "undef", "J2"},
        {5, 1, makecol(0, 0, 255), 100, 10, 25, "undef", "J3"}
    };

    for (int g = 0; g < 3; g++) {
        while (mouse_b & 1) rest(10);  // <-- D'abord attendre que le clic soit relâché
        choix_perso(buffer, &joueur[g], g);  // Ensuite seulement appeler le choix
    }


    t_file file;
    initialiser_file_tours(&file, joueur, 3);

    static int tour_en_cours = 0;
    static init_joueurs* joueur_actuel = NULL;

    //Premier tour pour commencer
    if (joueur_actuel == NULL) {
        joueur_actuel = defiler(&file);
        tour_en_cours++;
    }
    reinit_temps();  // Remise à zéro du chrono pour chaque nouvelle partie


    while (!key[KEY_ESC]) {
        clear_bitmap(buffer);
        rectfill(buffer, 740, 25, 775, 40, makecol(255, 255, 0));
        textout_ex(buffer, font, "XX", 750, 30, makecol(0, 0, 0), -1);

        int index_actuel = joueur_actuel - joueur;

        // Si temps écoulé -> fin du tour
        if (temps(buffer)) {
            enfiler(&file, joueur_actuel);
            joueur_actuel = defiler(&file);
            joueur_actuel->pm = 10;
            reinit_temps();  // Repart à 15s pour le nouveau joueur
            tour_en_cours++;
        }

        // Actions autorisées tant que temps restant
        deplacement(buffer, joueur, 3, index_actuel, 0);

        // Affichage des joueurs
        for (int i = 0; i < 3; i++) {
            int x = 110 + joueur[i].colonne * 50 + 25;
            int y = joueur[i].ligne * 50 + 25;
            circlefill(buffer, x, y, 20, joueur[i].couleur);
            if (i == index_actuel) {
                circle(buffer, x, y, 25, makecol(0, 255, 0));
            }
        }

        blit(buffer, screen, 0, 0, 0, 0, 800, 600);
    }
}

void init_1v1v1v1(BITMAP* buffer) {
    srand(time(NULL));
    init_joueurs joueur[4] = {
        {1, 5, makecol(255, 0, 0), 100, 10, 25, "undef", "J1"},
        {10, 5, makecol(0, 255, 0), 100, 10, 25, "undef", "J2"},
        {5, 1, makecol(0, 0, 255), 100, 10, 25, "undef", "J3"},
        {5, 10, makecol(255, 255, 255), 100, 10, 25, "undef", "J4"}
    };
    for (int g = 0; g < 3; g++) {
        while (mouse_b & 1) rest(10);  // <-- D'abord attendre que le clic soit relâché
        choix_perso(buffer, &joueur[g], g);  // Ensuite seulement appeler le choix
    }


    t_file file;
    initialiser_file_tours(&file, joueur, 3);

    static int tour_en_cours = 0;
    static init_joueurs* joueur_actuel = NULL;

    //Premier tour pour commencer
    if (joueur_actuel == NULL) {
        joueur_actuel = defiler(&file);
        tour_en_cours++;
    }
    reinit_temps();  // Remise à zéro du chrono pour chaque nouvelle partie


    while (!key[KEY_ESC]) {
        clear_bitmap(buffer);
        rectfill(buffer, 740, 25, 775, 40, makecol(255, 255, 0));
        textout_ex(buffer, font, "XX", 750, 30, makecol(0, 0, 0), -1);

        int index_actuel = joueur_actuel - joueur;

        // Si temps écoulé -> fin du tour
        if (temps(buffer)) {
            enfiler(&file, joueur_actuel);
            joueur_actuel = defiler(&file);
            joueur_actuel->pm = 10;
            reinit_temps();  // Repart à 15s pour le nouveau joueur
            tour_en_cours++;
        }

        // Actions autorisées tant que temps restant
        deplacement(buffer, joueur, 3, index_actuel, 0);

        // Affichage des joueurs
        for (int i = 0; i < 3; i++) {
            int x = 110 + joueur[i].colonne * 50 + 25;
            int y = joueur[i].ligne * 50 + 25;
            circlefill(buffer, x, y, 20, joueur[i].couleur);
            if (i == index_actuel) {
                circle(buffer, x, y, 25, makecol(0, 255, 0));
            }
        }

        blit(buffer, screen, 0, 0, 0, 0, 800, 600);
    }
}


