#ifndef LISTE_ADJACENCE_H_
#define LISTE_ADJACENCE_H_

#include "cellule_adjacence.h"

typedef struct
{
	celluleAdjacence_t *tete;
} listeAdjacence_t;

listeAdjacence_t *initialiserListeAdjacence(); /* Valide */
void insererCelluleAdjacence(listeAdjacence_t *pliste, celluleAdjacence_t *pcell); /* Valide */
celluleAdjacence_t *rechercherCelluleAdjacence(listeAdjacence_t *pliste, int noeud);
void supprimerCelluleAdjacence(listeAdjacence_t *pliste, celluleAdjacence_t *pcell);
void detruireListeAdjacence(listeAdjacence_t *pliste);

#endif /* LISTE_ADJACENCE_H_ */
