#include "tas.h"
#include "util.h"

int parent(int i)
{
	++i;
	i >>= 1;
	return --i;
}

int droite(int i)
{
	return (i <<= 1) + 2;
}

int gauche(int i) /* En C, gauche les indices sont impaires */
{
	return (i <<= 1) + 1;
}

void entasserMax(tas_t * t, int i)
{
	int g = gauche(i), d = droite(i), max;
	if ((g < t->taille) && (t->tab[g].poids > t->tab[i].poids))
		max = g;
	else
		max = i;
	if ((d < t->taille) && (t->tab[d].poids > t->tab[max].poids))
		max = d;
	if (max != i)
	{
		echanger(&(t->tab[max]), &(t->tab[i]));
		entasserMax(t, max);
	}
}

void construireTasMax(tas_t * t)
{
	int i;
	t->taille = t->longueur;
	for (i = parent(t->longueur - 1); i >= 0; --i)
	{
		entasserMax(t, i);
	}
}
