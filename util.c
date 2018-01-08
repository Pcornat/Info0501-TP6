#include "util.h"

void echanger(arete_t *a, arete_t *b)
{
	arete_t p;
	p = *a;
	*a = *b;
	*b = p;
}

void echangerMin(int *a, int *b)
{
	int p;
	p = *a;
	*a = *b;
	*b = p;
}
