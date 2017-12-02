#include "algo_parcours.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "cellule.h"
#include "outilsListe.h"
#include "file.h"
#include "outilsGraphe.h"

void parcoursLargeur(graphe_t *graph, int sommetOrigine)
{
    /**
	 * Implémentation avec les indices : faite.
	 * Succès : réussis, mauvais placement du defile, bravo le livre !
	*/
    sommet_t sommet[graph->nSommets];
    int u, i;
    file_t *queue = creerFile(graph->nSommets);
    cellule_t *cell = NULL;
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
    detruireFile(queue);
}
