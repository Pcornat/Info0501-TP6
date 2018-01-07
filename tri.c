#include "tri.h"

#include "util.h"

void tri_par_tas(tas_t *t)
{
	int i;
	construireTasMin(t);
	for (i = t->longueur; i >= 1; --i)
	{
		echanger(&t->tab[0], &t->tab[i]);
		--(t->taille);
		entasserMin(t, 0);
	}
}
