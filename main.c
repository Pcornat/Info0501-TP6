#include <stdio.h>
#include <stdlib.h>

#include "algo_parcours.h"
#include "graphe.h"

/**
 * arguments : nom_texte choix_liste/matrice sommet_origine_parcours sommet_à_atteindre_avec_PL_ou_PP
 */
int main(int argc, char *argv[]) {
	int choix, sommetOrigine, sommetFin;
	graphe_t *graphe2 = NULL;
	if (argc != 5) {
		fprintf(stderr, "Erreur, 4 arguments requis.\n");
		exit(EXIT_FAILURE);
	}
	choix = atoi(argv[2]), sommetOrigine = atoi(argv[3]), sommetFin = atoi(
			argv[4]);
	graphe2 = creerGraphe(choix, argv[1]);
	/*afficherListesAdjacences(graphe2);*/
	parcoursLargeur(graphe2, sommetOrigine, sommetFin);
	parcoursProfondeurRecursif(graphe2);
	detruireGraphe(graphe2);
	return EXIT_SUCCESS;
}
