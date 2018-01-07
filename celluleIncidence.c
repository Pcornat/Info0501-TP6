/*
 * celluleIncidence.c
 *
 *      Author: Florent
 */

#include "celluleIncidence.h"

#include <stdlib.h>

celluleIncidence_t *initialiserCelluleIncidence(arete_t *a)
{
	celluleIncidence_t *cell = NULL;
	cell = (celluleIncidence_t*) malloc(sizeof(celluleIncidence_t));
	cell->succ = cell->pred = NULL;
	cell->arete = a;
	return cell;
}

void detruireCelluleIncidence(celluleIncidence_t **dead)
{
	(*dead)->pred = (*dead)->succ = NULL;
	detruireArete(&((*dead)->arete));
	free(*dead);
	*dead = NULL;
}
