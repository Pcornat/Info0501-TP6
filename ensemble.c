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
set_t* union_ensemble(cell_ensemble_t *x, cell_ensemble_t *y)
{
	set_t *c = NULL, *a = x->representant, *b = y->representant;
	cell_ensemble_t *cell = NULL;
	c = creerEnsembleVide();
	c->size = a->size + b->size;
	if (a->size >= b->size)
	{
		c->tete = a->tete;
		c->queue = b->queue;
		for (cell = b->tete; cell != NULL; cell = cell->succ)
		{
			cell->representant = c;
		}
		a->queue->succ = b->tete;
	}
	else
	{
		c->tete = b->tete;
		c->tete = a->queue;
		for (cell = a->tete; cell != NULL; cell = cell->succ)
		{
			cell->representant = c;
		}
		b->queue->succ = a->tete;
	}
	free(a), free(b);
	a = b = NULL;
	return c;
}
