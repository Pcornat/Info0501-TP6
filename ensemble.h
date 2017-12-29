#ifndef ENSEMBLE_H_
#define ENSEMBLE_H_

#include "algo_parcours.h"
#include "cellule.h"

typedef struct
{
	cellule_t *tete;
	cellule_t *queue;
} set_t;

void creerEnsemble(set_t *a, sommet_t *x);
void trouverEnsemble(set_t *a, sommet_t *x);
void union_ensemble(set_t *a, sommet_t *x, sommet_t *y);

#endif /* ENSEMBLE_H_ */
