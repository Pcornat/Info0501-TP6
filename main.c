#include <stdio.h>
#include <stdlib.h>

#include "algo_parcours.h"
#include "arete.h"
#include "graphe.h"

/**
 * arguments : nom_texte sommet_origine_Prim
 */
int main(int argc, char *argv[])
{
	int sommetOrigine;
	graphe_t *graphe = NULL;
	arete_t *aretes = NULL;
	sommet_t *tabSommets = NULL;
	int longueurTabAretes = 0;
	if (argc != 3)
	{
		fprintf(stderr, "Erreur, 3 arguments requis.\n");
		exit(EXIT_FAILURE);
	}
	sommetOrigine = atoi(argv[2]);
	graphe = creerGraphe(argv[1]);
	afficherListesAdjacences(graphe);
	afficherMatriceAdjacences(graphe);
	afficherListesIncidences(graphe);
	longueurTabAretes = genererAcpmKruskal(graphe, &aretes);
	afficherAcpmKruskal(aretes, longueurTabAretes);
	genererAcpmPrim(graphe, &tabSommets, sommetOrigine);
	afficherAcpmPrim(&tabSommets, graphe->nSommets);
	detruireGraphe(graphe);
	return EXIT_SUCCESS;
}
