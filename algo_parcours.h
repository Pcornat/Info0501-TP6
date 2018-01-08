#ifndef __ALGO_PARCOURS_H__
#define __ALGO_PARCOURS_H__

#include "graphe.h"

typedef enum
{
	blanc, gris, noir
} couleur_t;

typedef struct
{
	couleur_t couleur;
	int noeud;
	int distance;
	int pere;
} sommet_t;

void parcoursLargeur(graphe_t *graph, int sommetOrigine, int sommetFin);
void visiter_PP(int u, graphe_t *graph, sommet_t *sommet, int *date, int *d,
		int *f);
void parcoursProfondeurRecursif(graphe_t *graph);
int genererAcpmKruskal(graphe_t *graph, arete_t **aretesRetenues);
void afficherAcpmKruskal(arete_t *tabAretesRetenues, int longueurTabArete);

#endif
