/*
 * cellEnsemble.c
 *
 */

#include "cellEnsemble.h"

#include <stdlib.h>

#include "ensemble.h"

cell_ensemble_t* creerCellEnsemble(int noeud)
{
	cell_ensemble_t* cell = (cell_ensemble_t*) malloc(sizeof(cell_ensemble_t));
	cell->noeud = noeud;
	cell->succ = NULL;
	cell->representant = NULL;
	return cell;
}

void detruireCellEnsemble(cell_ensemble_t** cell)
{
	free(*cell);
	*cell = NULL;
}
