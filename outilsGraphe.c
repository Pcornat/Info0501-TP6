#include "outilsGraphe.h"
#include <stdio.h>
#include <stdlib.h>

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