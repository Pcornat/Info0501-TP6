#include "arete.h"

#include <stdlib.h>

arete_t* creerArete(int origine, int extremite, int poids)
{
	arete_t *a = (arete_t*) malloc(sizeof(arete_t));
	a->origine = origine;
	a->extremite = extremite;
	a->poids = poids;
	return a;
}

void detruireArete(arete_t **a)
{
	free(*a);
	*a = NULL;
}
