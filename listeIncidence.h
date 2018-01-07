/*
 * listeIncidence.h
 *
 *      Author: Florent
 */

#ifndef LISTEINCIDENCE_H_
#define LISTEINCIDENCE_H_

#include "celluleIncidence.h"

typedef struct
{
	celluleIncidence_t *tete;
} listeIncidence_t;

listeIncidence_t *initialiserListeIncidence(); /* Valide */
void insererCelluleIncidence(listeIncidence_t *pliste,
		celluleIncidence_t *pcell); /* Valide */
celluleIncidence_t *rechercherCelluleIncidence(listeIncidence_t *pliste,
		int origine, int extremite);
void supprimerCelluleIncidence(listeIncidence_t *pliste,
		celluleIncidence_t *pcell);
void detruireListeIncidence(listeIncidence_t *pliste);

#endif /* LISTEINCIDENCE_H_ */
