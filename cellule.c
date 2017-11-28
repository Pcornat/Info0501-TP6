#include "cellule.h"
#include <stdlib.h>

cellule_t *initialiserCellule(int value)
{
	cellule_t *cell = NULL;
	cell = malloc(sizeof(cellule_t));
	cell->succ = cell->pred = NULL;
	cell->value = value;
	return cell;
}

void detruireCellule(cellule_t **dead)
{
	(*dead)->pred = (*dead)->succ = NULL;
	free(*dead);
}
