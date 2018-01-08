#include "tri.h"

#include "util.h"

void tri_par_tas(tas_t *t)
{
	int i;
	construireTasMax(t);
	for (i = t->longueur - 1; i >= 0; --i)
	{
		echanger(&(t->tab[0]), &(t->tab[i]));
		--(t->taille);
		entasserMax(t, 0);
	}
}
