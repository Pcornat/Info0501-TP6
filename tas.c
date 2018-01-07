#include "tas.h"
#include "util.h"

int parent(int i) {
	++i;
	i >>= 1;
	return --i;
}

int droite(int i) {
	return (i <<= 1) + 2;
}

int gauche(int i) /* En C, gauche les indices sont impaires */
{
	return (i <<= 1) + 1;
}

void entasserMin(tas_t * t, int i) {
	int g = gauche(i), d = droite(i), min;
	if ((g < t->taille) && (t->tab[g] < t->tab[i]))
		min = g;
	else
		min = i;
	if ((d < t->taille) && (t->tab[d] < t->tab[min]))
		min = d;
	if (min != i) {
		echanger(&(t->tab[min]), &(t->tab[i]));
		entasserMin(t, min);
	}
}

void construireTasMin(tas_t * t) {
	int i;
	t->taille = t->longueur;
	for (i = parent(t->longueur - 1); i >= 0; --i) {
		entasserMin(t, i);
	}
}
