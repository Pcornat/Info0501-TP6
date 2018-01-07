#ifndef GRAPHE_H_
#define GRAPHE_H_

#include "liste_adjacence.h"
#include "listeIncidence.h"

typedef struct
{
	int nSommets; /* nombre de sommets*/
	int oriente; /* oriente : 1 ; sinon 0 */
	int evalue; /* évalué : 1 ; sinon 0 */
	int complet; /* complet : 1 ; sinon 0 */
	listeAdjacence_t **adj; /* Pointeur de tableau de pointeur de listeAdjacence_t */
	listeIncidence_t **inc;
	int **matrice_adj; /* Matrice d'adjacence, toujours carrée */
} graphe_t;

/*Valide*/
void creerListesAdjacences(graphe_t *graph, char *fileName);
/*Valide*/
void afficherListesAdjacences(graphe_t *graph);
void creerMatriceAdjacences(graphe_t *graph, char *fileName);
void afficherMatriceAdjacences(graphe_t *graph);
graphe_t *creerGraphe(char *fileName);
void detruireGraphe(graphe_t *graph);

#endif /* GRAPHE_H_ */
