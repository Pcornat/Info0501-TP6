#include <stdlib.h>
#include "cellule_adjacence.h"

celluleAdjacence_t *initialiserCelluleAdjacence(int noeud)
{
	celluleAdjacence_t *cell = NULL;
	cell = (celluleAdjacence_t*) malloc(sizeof(celluleAdjacence_t));
	cell->succ = cell->pred = NULL;
	cell->noeud = noeud;
	return cell;
}

void detruireCelluleAdjacence(celluleAdjacence_t **dead)
{
	(*dead)->pred = (*dead)->succ = NULL;
	free(*dead);
	*dead = NULL;
}
