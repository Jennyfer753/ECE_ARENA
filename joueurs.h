//
// Created by alois on 18/05/2025.
//

#ifndef JOUEURS_H
#define JOUEURS_H

//On définit une structure joueur
typedef struct {
    int ligne; //La Ligne sur laquelle est placée le joueur
    int colonne; //La colonne sur laquelle il est placé
    int couleur; //Couleur du joueur
    int pv ; // Nombre de points de vie
    int pm; // Nombre de points de mouvement
    int pa; // Nombre de points d'action
    char classe[4]; // Classe du personnage : mage, archère, etc.
    char nom[51]; // Nom du joueur
} init_joueurs;

#endif //JOUEURS_H
