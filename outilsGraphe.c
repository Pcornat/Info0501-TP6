#include "outilsGraphe.h"

#include <stdio.h>

void afficherChemin(graphe_t *graph, int s, int v, sommet_t *sommet)
{
	if (v == s)
	{
		printf("%d\n", s);
	}
	else if (sommet[v].pere == -1)
	{
		printf("Il n'existe aucun chemin de %d à %d\n", s, v);
	}
	else
	{
		afficherChemin(graph, s, sommet[v].pere, sommet);
		printf("%d\n", v);
	}
}

void afficherPP(int u, graphe_t *graph, sommet_t *sommet, int *d, int *f)
{
	int i;
	for (i = 0; i < graph->nSommets; ++i)
	{
		printf("sommet %d qui commence à %d et finis à %d\n", i, d[i], f[i]);
	}
}
