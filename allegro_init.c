//
// Created by alois on 18/05/2025.
//
#include <stdio.h>
#include <allegro.h>
#include "allegro_init.h"

/** On initialise Allegro **/
void initialisation_allegro(BITMAP** buffer){
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(desktop_color_depth());
    install_sound(DIGI_AUTODETECT, MIDI_NONE, NULL); //Installation d'une mélodie

    SAMPLE* melodie_menu = load_sample("melodie_menu.wav"); //On charge la mélodie

    //On vérifie que la mélodie soit bien chargée et sinon on quitte le programme
    if (!melodie_menu) {
        allegro_message("Erreur chargement melodie menu");
        exit(EXIT_FAILURE);
    }

    //On vérifie que la fenêtre se lance bien
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0){
        allegro_message("problème gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    *buffer = create_bitmap(800, 600);
    if (!(*buffer)) {
        allegro_message("Erreur allocation buffer");
        exit(EXIT_FAILURE);
    }
    show_mouse(screen);
}
