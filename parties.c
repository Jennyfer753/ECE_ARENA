#include "parties.h"
void init_1v1(BITMAP* buffer) {
    srand(time(NULL));
    init_joueurs joueur[2] = {
        {1, 5, makecol(255, 0, 0), 100, 10, 25, "undef", "J1"},
        {10, 5, makecol(0, 255, 0), 100, 10, 25, "undef", "J2"}
    };

    t_file file;
    initialiser_file_tours(&file, joueur, 2);

    static int tour_en_cours = 0;
    static init_joueurs* joueur_actuel = NULL;

    if (joueur_actuel == NULL) {
        joueur_actuel = defiler(&file);
        tour_en_cours++;
    }

    while (!key[KEY_ESC]) {
        clear_bitmap(buffer);

        // Appelle la fonction temps : si elle retourne 1, on change de joueur
        if (temps(buffer)) {
            enfiler(&file, joueur_actuel);
            joueur_actuel = defiler(&file);
            joueur_actuel->pm = 10;
            tour_en_cours++;
        }

        // Gestion du déplacement
        int index_actuel = joueur_actuel - joueur;
        if (deplacement(buffer, joueur, 2, index_actuel, 0)) {
            enfiler(&file, joueur_actuel);
            joueur_actuel = defiler(&file);
            joueur_actuel->pm = 10;
        }

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

    t_file file;
    initialiser_file_tours(&file, joueur, 3);

    static int tour_en_cours = 0;
    static init_joueurs* joueur_actuel = NULL;

    if (joueur_actuel == NULL) {
        joueur_actuel = defiler(&file);
        tour_en_cours++;
    }

    while (!key[KEY_ESC]) {
        clear_bitmap(buffer);

        // Appelle la fonction temps : si elle retourne 1, on change de joueur
        if (temps(buffer)) {
            enfiler(&file, joueur_actuel);
            joueur_actuel = defiler(&file);
            joueur_actuel->pm = 10;
            tour_en_cours++;
        }

        // Gestion du déplacement
        int index_actuel = joueur_actuel - joueur;
        if (deplacement(buffer, joueur, 3, index_actuel, 0)) {
            enfiler(&file, joueur_actuel);
            joueur_actuel = defiler(&file);
            joueur_actuel->pm = 10;
        }

        // Affichage des joueurs
        for (int i = 0; i < 3; i++) {
            int x = 110 + joueur[i].colonne * 50 + 25;
            int y = joueur[i].ligne * 50 + 25;
            circlefill(buffer, x, y, 20, joueur[i].couleur);
            if (i == index_actuel) {
                circle(buffer, x, y, 25, makecol(255, 255, 255)); // surbrillance blanche pour le joueur actif
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

    t_file file;
    initialiser_file_tours(&file, joueur, 4);

    static int tour_en_cours = 0;
    static init_joueurs* joueur_actuel = NULL;

    if (joueur_actuel == NULL) {
        joueur_actuel = defiler(&file);
        tour_en_cours++;
    }

    while (!key[KEY_ESC]) {
        clear_bitmap(buffer);

        // Appelle la fonction temps : si elle retourne 1, on change de joueur
        if (temps(buffer)) {
            enfiler(&file, joueur_actuel);
            joueur_actuel = defiler(&file);
            joueur_actuel->pm = 10;
            tour_en_cours++;
        }

        // Gestion du déplacement
        int index_actuel = joueur_actuel - joueur;
        if (deplacement(buffer, joueur, 4, index_actuel, 0)) {
            enfiler(&file, joueur_actuel);
            joueur_actuel = defiler(&file);
            joueur_actuel->pm = 10;
        }

        // Affichage des joueurs
        for (int i = 0; i < 4; i++) {
            int x = 110 + joueur[i].colonne * 50 + 25;
            int y = joueur[i].ligne * 50 + 25;
            circlefill(buffer, x, y, 20, joueur[i].couleur);
            if (i == index_actuel) {
                circle(buffer, x, y, 25, makecol(255, 255, 0)); // surbrillance jaune pour joueur actif
            }
        }

        blit(buffer, screen, 0, 0, 0, 0, 800, 600);
    }
}

