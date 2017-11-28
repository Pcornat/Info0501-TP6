#ifndef LISTE_H_
#define LISTE_H_
#include "cellule.h"

typedef struct
{
	cellule_t *tete;
} liste_t;

liste_t *initialiserListe();					 //Valide
void inserer(liste_t *pliste, cellule_t *pcell); //Valide
cellule_t *rechercher(liste_t *pliste, int value);
void supprimer(liste_t *pliste, cellule_t *pcell);
void detruireListe(liste_t *pliste);

#endif /* LISTE_H_ */
