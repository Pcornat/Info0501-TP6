#ifndef __ALGO_PARCOURS_H__
#define __ALGO_PARCOURS_H__
#include "graphe.h"

void parcoursLargeur(graphe_t *graph, int sommetOrigine);
void visiter_PP(int u);
void parcoursProfondeur(graphe_t *graph, int sommetOrigine);

#endif