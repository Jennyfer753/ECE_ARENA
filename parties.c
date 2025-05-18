#include "parties.h"
#include "joueurs.h"
#include "classement.h"
void init_1v1(BITMAP* buffer) {
    srand(time(NULL));
    int nb_joueurs = 2;

    init_joueurs joueur[2] = {
        {1, 5, makecol(255, 0, 0), 100, 10, 25, "classe", "J1"},
        {10, 5, makecol(0, 255, 0), 100, 10, 25, "classe", "J2"}
    };

    for (int g = 0; g < 2; g++) {
        while (mouse_b & 1) rest(10);
        choix_perso(buffer, &joueur[g], g);
    }

    t_file file;
    initialiser_file_tours(&file, joueur, 2);

    Pile_classement pile_classement_joueurs;
    init_pile(&pile_classement_joueurs);

    static int tour_en_cours = 0;
    static init_joueurs* joueur_actuel = NULL;

    int joueurs_actifs[2] = {1, 1};

    if (joueur_actuel == NULL) {
        joueur_actuel = defiler(&file);
        tour_en_cours++;
    }

    reinit_temps();

    while (!key[KEY_ESC]) {
        clear_bitmap(buffer);
        rectfill(buffer, 740, 25, 775, 40, makecol(255, 255, 0));
        textout_ex(buffer, font, "XX", 750, 30, makecol(0, 0, 0), -1);

        int index_actuel = joueur_actuel - joueur;

        // Si le joueur actuel n’a plus de PM
        if (joueur_actuel->pm == 0 && joueurs_actifs[index_actuel]) {
            empiler(&pile_classement_joueurs, joueur_actuel);
            joueurs_actifs[index_actuel] = 0;
            nb_joueurs--;

            // Si 1 seul joueur restant
            if (nb_joueurs == 1) {
                for (int i = 0; i < 2; i++) {
                    if (joueurs_actifs[i]) {
                        empiler(&pile_classement_joueurs, &joueur[i]);
                        joueurs_actifs[i] = 0;
                        break;
                    }
                }
                classement(&pile_classement_joueurs);
                return;
            }

            joueur_actuel = defiler(&file);
            reinit_temps();
            continue;
        }

        // Si temps écoulé → changer de joueur
        if (temps(buffer)) {
            if (joueurs_actifs[index_actuel] && joueur_actuel->pm > 0) {
                enfiler(&file, joueur_actuel);
            }

            joueur_actuel = defiler(&file);
            reinit_temps();
            tour_en_cours++;
        }

        // Actions
        deplacement(buffer, joueur, 2, index_actuel, 0);

        // Affichage des joueurs actifs
        for (int i = 0; i < 2; i++) {
            if (!joueurs_actifs[i]) continue;
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
    int nb_joueurs = 3;

    init_joueurs joueur[3] = {
        {1, 5, makecol(255, 0, 0), 100, 25, 10, "undef", "J1"},
        {10, 5, makecol(0, 255, 0), 100, 10, 25, "undef", "J2"},
        {5, 1, makecol(0, 0, 255), 100, 10, 25, "undef", "J3"}
    };

    for (int g = 0; g < 3; g++) {
        while (mouse_b & 1) rest(10);
        choix_perso(buffer, &joueur[g], g);
    }

    t_file file;
    initialiser_file_tours(&file, joueur, 3);

    Pile_classement pile_classement_joueurs;
    init_pile(&pile_classement_joueurs);

    static int tour_en_cours = 0;
    static init_joueurs* joueur_actuel = NULL;

    int joueurs_actifs[3] = {1, 1, 1};

    if (joueur_actuel == NULL) {
        joueur_actuel = defiler(&file);
        tour_en_cours++;
    }

    reinit_temps();

    while (!key[KEY_ESC]) {
        clear_bitmap(buffer);
        rectfill(buffer, 740, 25, 775, 40, makecol(255, 255, 0));
        textout_ex(buffer, font, "XX", 750, 30, makecol(0, 0, 0), -1);

        int index_actuel = joueur_actuel - joueur;

        // Si le joueur actuel n’a plus de PM
        if (joueur_actuel->pm == 0 && joueurs_actifs[index_actuel]) {
            empiler(&pile_classement_joueurs, joueur_actuel);
            joueurs_actifs[index_actuel] = 0;
            nb_joueurs--;

            // Si 1 seul joueur restant
            if (nb_joueurs == 1) {
                for (int i = 0; i < 3; i++) {
                    if (joueurs_actifs[i]) {
                        empiler(&pile_classement_joueurs, &joueur[i]);
                        joueurs_actifs[i] = 0;
                        break;
                    }
                }
                classement(&pile_classement_joueurs);
                return;
            }

            joueur_actuel = defiler(&file);
            reinit_temps();
            continue;
        }

        // Si temps écoulé → changer de joueur
        if (temps(buffer)) {
            if (joueurs_actifs[index_actuel] && joueur_actuel->pm > 0) {
                enfiler(&file, joueur_actuel);
            }

            joueur_actuel = defiler(&file);
            reinit_temps();
            tour_en_cours++;
        }

        // Actions
        deplacement(buffer, joueur, 3, index_actuel, 0);

        // Affichage des joueurs actifs
        for (int i = 0; i < 3; i++) {
            if (!joueurs_actifs[i]) continue;
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
    int nb_joueurs = 4;
    init_joueurs joueur[4] = {
        {1, 5, makecol(255, 0, 0), 100, 10, 25, "undef", "J1"},
        {10, 5, makecol(0, 255, 0), 100, 10, 25, "undef", "J2"},
        {5, 1, makecol(0, 0, 255), 100, 10, 25, "undef", "J3"},
        {5, 10, makecol(255, 255, 255), 100, 10, 25, "undef", "J4"}
    };
    for (int g = 0; g < 4; g++) {
        while (mouse_b & 1) rest(10);
        choix_perso(buffer, &joueur[g], g);
    }

    t_file file;
    initialiser_file_tours(&file, joueur, 4);

    Pile_classement pile_classement_joueurs;
    init_pile(&pile_classement_joueurs);

    static int tour_en_cours = 0;
    static init_joueurs* joueur_actuel = NULL;

    int joueurs_actifs[4] = {1, 1, 1, 1};

    if (joueur_actuel == NULL) {
        joueur_actuel = defiler(&file);
        tour_en_cours++;
    }

    reinit_temps();

    while (!key[KEY_ESC]) {
        clear_bitmap(buffer);
        rectfill(buffer, 740, 25, 775, 40, makecol(255, 255, 0));
        textout_ex(buffer, font, "XX", 750, 30, makecol(0, 0, 0), -1);

        int index_actuel = joueur_actuel - joueur;

        // Si le joueur actuel n’a plus de PM
        if (joueur_actuel->pm == 0 && joueurs_actifs[index_actuel]) {
            empiler(&pile_classement_joueurs, joueur_actuel);
            joueurs_actifs[index_actuel] = 0;
            nb_joueurs--;

            // Si 1 seul joueur restant
            if (nb_joueurs == 1) {
                for (int i = 0; i < 4; i++) {
                    if (joueurs_actifs[i]) {
                        empiler(&pile_classement_joueurs, &joueur[i]);
                        joueurs_actifs[i] = 0;
                        break;
                    }
                }
                classement(&pile_classement_joueurs);
                return;
            }

            joueur_actuel = defiler(&file);
            reinit_temps();
            continue;
        }

        // Si temps écoulé → changer de joueur
        if (temps(buffer)) {
            if (joueurs_actifs[index_actuel] && joueur_actuel->pm > 0) {
                enfiler(&file, joueur_actuel);
            }

            joueur_actuel = defiler(&file);
            reinit_temps();
            tour_en_cours++;
        }

        // Actions
        deplacement(buffer, joueur, 4, index_actuel, 0);

        // Affichage des joueurs actifs
        for (int i = 0; i < 4; i++) {
            if (!joueurs_actifs[i]) continue;
            int x = 110 + joueur[i].colonne * 50 + 25;
            int y = joueur[i].ligne * 50 + 25;
            circlefill(buffer, x, y, 20, joueur[i].couleur);
            if (i == index_actuel) {
                circle(buffer, x, y, 25, makecol(0, 255, 0));
            }
        }

        blit(buffer, screen, 0, 0, 0, 0, 800, 600);
    }



