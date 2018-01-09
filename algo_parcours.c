#include "algo_parcours.h"

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "arete.h"
#include "cellEnsemble.h"
#include "cellule_adjacence.h"
#include "celluleIncidence.h"
#include "ensemble.h"
#include "file.h"
#include "filePrioriteMin.h"
#include "outilsGraphe.h"
#include "tas.h"
#include "tri.h"

void parcoursLargeur(graphe_t *graph, int sommetOrigine, int sommetFin)
{
	/**
	 * Implémentation avec les indices : faite.
	 * Résultat : réussis, mauvais placement du defile, bravo le livre !
	 */
	sommet_t *sommet = (sommet_t*) malloc(graph->nSommets * sizeof(sommet_t));
	int u, i;
	file_t *queue = creerFile(graph->nSommets);
	celluleAdjacence_t *cell = NULL;
	for (i = 0; i < graph->nSommets; ++i)
	{
		sommet[i].couleur = blanc;
		sommet[i].distance = INT_MAX;
		sommet[i].pere = -1;
	}
	sommet[sommetOrigine].couleur = gris;
	sommet[sommetOrigine].distance = 0;
	sommet[sommetOrigine].pere = -1;
	enfile(queue, sommetOrigine);
	while (!file_isEmpty(queue))
	{
		u = front(queue);
		for (cell = graph->adj[u]->tete; cell != NULL; cell = cell->succ)
		{
			if (sommet[cell->noeud].couleur == blanc)
			{
				sommet[cell->noeud].couleur = gris;
				sommet[cell->noeud].distance = sommet[u].distance + 1;
				sommet[cell->noeud].pere = u;
				enfile(queue, cell->noeud);
			}
		}
		sommet[u].couleur = noir;
		defile(queue);
	}
	detruireFile(&queue);
	afficherChemin(graph, sommetOrigine, sommetFin, sommet);
	free(sommet);
}

/**
 * ATTENTION : les d et f seront créés à chaque fois -> récursivité ! Il faut les créer avant la première
 * invocation de visiter_PP, c'est-à-dire dans parcoursProfondeurRecursif
 */
void visiter_PP(int u, graphe_t *graph, sommet_t *sommet, int *date, int *d,
		int *f)
{
	celluleAdjacence_t *cell;
	sommet[u].couleur = gris;
	++(*date);
	d[u] = *date;
	for (cell = graph->adj[u]->tete; cell != NULL; cell = cell->succ)
	{
		if (sommet[cell->noeud].couleur == blanc)
		{
			sommet[cell->noeud].pere = u;
			visiter_PP(cell->noeud, graph, sommet, date, d, f);
		}
	}
	sommet[u].couleur = noir;
	f[u] = ++(*date);
}

void parcoursProfondeurRecursif(graphe_t *graph)
{
	int i, date, *f = (int*) malloc(graph->nSommets * sizeof(int)), *d =
			(int*) malloc(graph->nSommets * sizeof(int));
	sommet_t *sommet = (sommet_t*) malloc(graph->nSommets * sizeof(sommet_t));
	for (i = 0; i < graph->nSommets; ++i)
	{
		sommet[i].couleur = blanc;
		sommet[i].pere = -1;
	}
	date = 0;
	for (i = 0; i < graph->nSommets; ++i)
	{
		if (sommet[i].couleur == blanc)
		{
			visiter_PP(i, graph, sommet, &date, d, f);
		}
	}
	afficherPP(0, graph, sommet, d, f);
	free(d), free(f), free(sommet);
}

int genererAcpmKruskal(graphe_t *graph, arete_t **aretesRetenues)
{
	set_t **tabEnsembleSommet = NULL;
	celluleIncidence_t *cell = NULL;
	cell_ensemble_t **tabSommet = NULL;
	tas_t *tasArete = NULL;
	int i, j = 0, longueurTabArete;
	assert(*aretesRetenues == NULL);
	tabEnsembleSommet = (set_t**) malloc(graph->nSommets * sizeof(set_t*));
	tabSommet = (cell_ensemble_t **) malloc(
			graph->nSommets * sizeof(cell_ensemble_t*));
	tasArete = (tas_t*) malloc(sizeof(tas_t));
	tasArete->longueur = (graph->nSommets * (graph->nSommets - 1)) / 2; /* Nombre maximal d'arêtes possibles dans tou graphe de n nœuds. */
	tasArete->tab = NULL;
	for (i = 0; i < graph->nSommets; ++i)
	{
		/* Va servir de "traducteur" pour les différents sommets des listes d'adjacences */
		tabSommet[i] = creerCellEnsemble(i);
		tabEnsembleSommet[i] = creerEnsemble(tabSommet[i]);
	}
	/**
	 * Récupération de toutes les arêtes puis on les trie
	 */
	tasArete->tab = (arete_t*) malloc(tasArete->longueur * sizeof(arete_t));
	for (i = 0; i < graph->nSommets; ++i)
		for (cell = graph->inc[i]->tete; cell != NULL; cell = cell->succ, ++j)
		{
			tasArete->tab[j] = *(cell->arete);
		}
	tasArete->longueur = j;
	tasArete->tab = (arete_t*) realloc(tasArete->tab,
			tasArete->longueur * sizeof(arete_t));
	longueurTabArete = tasArete->longueur - 1;
	(*aretesRetenues) = (arete_t*) malloc(longueurTabArete * sizeof(arete_t));
	tri_par_tas(tasArete);
	for (i = 0; i < tasArete->longueur; ++i)
	{
		if (trouverEnsemble(tabSommet[tasArete->tab[i].origine])
				!= trouverEnsemble(tabSommet[tasArete->tab[i].extremite]))
		{
			(*aretesRetenues)[i] = tasArete->tab[i];
			union_ensemble(tabSommet[tasArete->tab[i].origine],
					tabSommet[tasArete->tab[i].extremite]);
		}
	}
	for (i = 0; i < graph->nSommets; ++i)
	{
		free(tabEnsembleSommet[i]), free(tabSommet[i]);
	}
	free(tasArete->tab), free(tasArete), free(tabEnsembleSommet), free(
			tabSommet);
	return longueurTabArete;
}

void afficherAcpmKruskal(arete_t *tabAretesRetenues, int longueurTabArete)
{
	int i, poidsMax = 0;
	for (i = 0; i < longueurTabArete; ++i)
	{
		poidsMax += tabAretesRetenues[i].poids;
	}
	printf("Poids maximal : %d\n", poidsMax);
	free(tabAretesRetenues);
}

/**
 * Permet de chercher et trouver le poids d'une arête dans son tableau.
 */
int chercherArete(arete_t *a, int origine, int extremite, int longueurTab)
{
	int i;
	for (i = 0; i < longueurTab; ++i)
	{
		if ((origine == a[i].origine && extremite == a[i].extremite)
				|| (origine == a[i].extremite && extremite == a[i].origine))
		{
			return a[i].poids;
		}
	}
	return 0;
}

void genererAcpmPrim(graphe_t *graph, int **key, int **pere, int sommetOrigine)
{
	filePrioriteMin *file = NULL;
	celluleAdjacence_t *cellAd = NULL;
	celluleIncidence_t *cell = NULL;
	arete_t* tabAretes = NULL;
	int i, j = 0, u, longueurTabArete = ((graph->nSommets
			* (graph->nSommets - 1)) / 2) - 1, poids;
	file = creerFileMin();
	*key = (int*) malloc(graph->nSommets * sizeof(int));
	*pere = (int*) malloc(graph->nSommets * sizeof(int));
	tabAretes = (arete_t*) malloc(longueurTabArete * sizeof(arete_t));
	for (i = 0; i < graph->nSommets; ++i)
	{
		(*key)[i] = INT_MAX;
		(*pere)[i] = INT_MAX; /* Implémentation par indice */
		inserer(file, i);
		for (cell = graph->inc[i]->tete; cell != NULL; cell = cell->succ, ++j)
		{
			tabAretes[j] = *(cell->arete);
		}
	}
	(*key)[sommetOrigine] = 0;
	longueurTabArete = j;
	tabAretes = (arete_t*) realloc(tabAretes,
			longueurTabArete * sizeof(arete_t));
	while (!isEmpty(file))
	{
		u = extraireMin(file);
		for (cellAd = graph->adj[u]->tete; cellAd != NULL; cellAd =
				cellAd->succ)
		{
			if (chercherNoeud(file, cellAd->noeud)
					&& ((poids = chercherArete(tabAretes, u, cellAd->noeud,
							longueurTabArete)) < (*key)[cellAd->noeud]))
			{
				(*pere)[cellAd->noeud] = u;
				(*key)[cellAd->noeud] = poids;
			}
		}
	}
	detruireFileMin(&file);
	free(tabAretes);
}

void afficherAcpmPrim(int **pere, int **key, int longueurTab)
{
	int i, poidsMax = 0;
	for (i = 0; i < longueurTab; ++i)
	{
		printf("origine : %d, extremite : %d, poids : %d\n", (*pere)[i], i,
				(*key)[i]);
		if ((*key)[i] != INT_MAX && (*pere)[i] != INT_MAX)
		{
			poidsMax += (*key)[i];
		}
	}
	printf("Poids maximal : %d\n", poidsMax);
	free(*key), free(*pere);
	*key = *pere = NULL;
}
