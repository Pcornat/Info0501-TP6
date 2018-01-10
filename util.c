#include "util.h"

void echanger(arete_t *a, arete_t *b)
{
	arete_t p;
	p = *a;
	*a = *b;
	*b = p;
}

void echangerMin(sommet_t *a, sommet_t *b)
{
	sommet_t p;
	p = *a;
	*a = *b;
	*b = p;
}
