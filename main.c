#include <stdio.h>
#include <stdlib.h>

#include "algo_parcours.h"
#include "arete.h"
#include "graphe.h"

/**
 * arguments : nom_texte sommet_origine_parcours sommet_à_atteindre_avec_PL_ou_PP
 */
int main(int argc, char *argv[])
{
	int sommetOrigine, sommetFin;
	graphe_t *graphe = NULL;
	arete_t *aretes = NULL;
	int longueurTabAretes = 0;
	if (argc != 4)
	{
		fprintf(stderr, "Erreur, 4 arguments requis.\n");
		exit(EXIT_FAILURE);
	}
	sommetOrigine = atoi(argv[2]), sommetFin = atoi(argv[3]);
	graphe = creerGraphe(argv[1]);
	afficherListesAdjacences(graphe);
	afficherMatriceAdjacences(graphe);
	afficherListesIncidences(graphe);
	longueurTabAretes = genererAcpmKruskal(graphe, &aretes);
	afficherAcpmKruskal(aretes, longueurTabAretes);
	detruireGraphe(graphe);
	return EXIT_SUCCESS;
}
