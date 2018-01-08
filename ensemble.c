#include "ensemble.h"

#include <stdlib.h>

set_t* creerEnsembleVide(void)
{
	set_t *a = (set_t*) malloc(sizeof(set_t));
	a->queue = a->tete = NULL;
	a->size = 0;
	return a;
}

set_t* creerEnsemble(cell_ensemble_t *sommet)
{
	set_t *a = (set_t*) malloc(sizeof(set_t));
	a->tete = a->queue = NULL;
	a->queue = a->tete = sommet;
	a->tete->representant = a;
	a->size = 1;
	return a;
}

set_t* trouverEnsemble(cell_ensemble_t *x)
{
	return x->representant;
}

/**
 * Application avec l'heuristique de l'union pondérée
 * pour un temps d'exécution plus faible.
 */
void union_ensemble(cell_ensemble_t *x, cell_ensemble_t *y)
{
	set_t *a = x->representant, *b = y->representant;
	cell_ensemble_t *cell = NULL;
	if (b->size <= a->size)
	{
		a->size += b->size;
		a->queue->succ = b->tete;
		a->queue = b->queue;
		for (cell = b->tete; cell != NULL; cell = cell->succ)
		{
			cell->representant = a;
		}
	}
	else
	{
		b->size += a->size;
		b->queue->succ = a->tete;
		b->queue = a->queue;
		for (cell = a->tete; cell != NULL; cell = cell->succ)
		{
			cell->representant = b;
		}
	}
}
