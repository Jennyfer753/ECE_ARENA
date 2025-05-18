
#ifndef GESTION_SONS_H
#define GESTION_SONS_H
BITMAP* charger_son_on();
BITMAP* charger_son_off();
void init_son(int* etat_son);
void bouton_son(BITMAP* buffer, int* etat_son, BITMAP* img_son_on, BITMAP* img_son_off);
void clic(int x, int y, int* etat_son, SAMPLE* melodie_menu, BITMAP* buffer, BITMAP* img_son_on, BITMAP* img_son_off);


#endif //GESTION_SONS_H
