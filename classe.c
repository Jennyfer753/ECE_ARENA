#include <stdio.h>
#include "classes.h"
#include "attaque_sort.h"

void charger_classes(ClassePersonnage *classes) {
    strcpy(classes[0].nom_classe, "Mage");
    classes[0].sprite = load_bitmap("mage.bmp", NULL);

    strcpy(classes[1].nom_classe, "Maîtresse Dragon");
    classes[1].sprite = load_bitmap("dragon.bmp", NULL);

    strcpy(classes[2].nom_classe, "Technomage");
    classes[2].sprite = load_bitmap("tech.bmp", NULL);

    strcpy(classes[3].nom_classe, "Archère");
    classes[3].sprite = load_bitmap("archere.bmp", NULL);
}
