#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"

int main(void)
{
	graphe_t *graphe2 = creerGraphe(1);
	afficherListesAdjacences(graphe2);
	parcoursLargeur(graphe2, 0);
	detruireGraphe(graphe2);
	return EXIT_SUCCESS;
}
