#include "cellule.h"

#include <stdlib.h>

cellule_t *initialiserCellule(int noeud, int poids)
{
	cellule_t *cell = NULL;
	cell = (cellule_t*) malloc(sizeof(cellule_t));
	cell->succ = cell->pred = NULL;
	cell->noeud = noeud;
	cell->poids = poids;
	return cell;
}

void detruireCellule(cellule_t **dead)
{
	(*dead)->pred = (*dead)->succ = NULL;
	free(*dead);
	*dead = NULL;
}
