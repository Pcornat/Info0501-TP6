#ifndef ENSEMBLE_H_
#define ENSEMBLE_H_

#include "cellEnsemble.h"

typedef struct setter_t
{
	cell_ensemble_t *tete;
	cell_ensemble_t *queue;
	int size; /* Heuristique de l'union pondérée */
} set_t;

set_t* creerEnsembleVide(void);
set_t* creerEnsemble(cell_ensemble_t *sommet);
set_t* trouverEnsemble(cell_ensemble_t *x);
set_t* union_ensemble(set_t **a, set_t **b); /* Plus rapide d'ajouter un ensemble petit à la queue d'un ensemble grand. */

#endif /* ENSEMBLE_H_ */
