#include <stdio.h>
#include <allegro.h>
#include "allegro_init.h"


void initialisation_allegro(BITMAP** buffer){
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(desktop_color_depth());
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
