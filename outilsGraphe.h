#ifndef __OUTILSGRAPHE_H__
#define __OUTILSGRAPHE_H__

#include "algo_parcours.h"
#include "graphe.h"

void afficherChemin(graphe_t *graph, int s, int v, sommet_t *sommet);
void afficherPP(int u, graphe_t *graph, sommet_t *sommet, int *d, int *f);

#endif
