#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"
#include "algo_parcours.h"

/**
 * arguments : nom_texte choix_liste/matrice sommet_origine_parcours
 */
int main(int argc, char *argv[])
{
	int choix, sommet;
	graphe_t *graphe2 = NULL;
	if (argc != 4)
	{
		fprintf(stderr, "Erreur, trois arguments requis.\n");
		exit(EXIT_FAILURE);
	}
	choix = atoi(argv[2]), sommet = atoi(argv[3]);
	graphe2 = creerGraphe(choix, argv[1]);
	afficherListesAdjacences(graphe2);
	/* parcoursLargeur(graphe2, sommet); */
	detruireGraphe(graphe2);
	return EXIT_SUCCESS;
}
