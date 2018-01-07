#include "util.h"

void echanger(arete_t *a, arete_t *b)
{
	arete_t p = *a;
	*a = *b;
	*b = p;
}
