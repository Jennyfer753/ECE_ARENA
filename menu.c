#include <stdio.h>
#include <allegro.h>
#include "menu.h"
#include "1v1.h"
#include "1v1v1.h"
#include "1v1v1v1.h"

void ecran_menu(BITMAP* buffer) {
    int x1=300;
    int x2=500;
    int y1=250;
    int y2=350;
    clear_bitmap(buffer);
    rectfill(buffer,x1,y1,x2,y2,makecol(255, 0, 0));
}

void config_partie(BITMAP* buffer) {
    textout_ex(buffer, font,"nombre de joueur ?", 800/3+60, 600/2,makecol(255, 255, 255), -1);
    textout_ex(buffer, font,"2", 350, 600/2+50,makecol(255, 0, 0), -1);
    textout_ex(buffer, font,"3", 400, 600/2+50,makecol(0, 255, 0), -1);
    textout_ex(buffer, font,"4", 450, 600/2+50,makecol(0, 0, 255), -1);
}
