#include "graphe.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cellule.h"
#include "outilsListe.h"

void creerListesAdjacences(graphe_t *graph, char *fileName) {
	FILE *file = NULL;
	int indice, donnee, poids, i;
	char buffer[27]; /* buffer suffisamment grand */
	file = fopen(fileName, "r");
	if (file == NULL) {
		fprintf(stderr, "Ouverture du fichier impossible\n");
		exit(EXIT_FAILURE);
	}

	while (fscanf(file, "%s", buffer), !feof(file)) {
		if (strcmp(buffer, "nSommets") == 0) {
			fscanf(file, "%d", &graph->nSommets);
			graph->adj = (liste_t **) malloc(
					graph->nSommets * sizeof(liste_t *));
			/* Créer tableau de listes adjacences */
			for (i = 0; i < graph->nSommets; ++i) {
				graph->adj[i] = initialiserListe();
			}
		} else if (strcmp(buffer, "oriente") == 0) {
			fscanf(file, "%d", &graph->oriente);
		} else if (strcmp(buffer, "value") == 0) {
			fscanf(file, "%d", &graph->evalue);
		} else if (strcmp(buffer, "complet") == 0) {
			fscanf(file, "%d", &graph->complet);
		} else if (strcmp(buffer, "debutDefAretes") == 0) {
			while (fscanf(file, "%s", buffer), strcmp(buffer, "finDefAretes")
					!= 0) {
				indice = atoi(buffer);
				fscanf(file, "%s", buffer);
				donnee = atoi(buffer);
				fscanf(file, "%s", buffer);
				poids = atoi(buffer);
				inserer(graph->adj[indice], initialiserCellule(donnee, poids));
				if (!graph->oriente) {
					inserer(graph->adj[donnee],
							initialiserCellule(indice, poids));
				}
			}
		}
	}
	fclose(file);
}

void afficherListesAdjacences(graphe_t *graph) {
	int i;
	for (i = 0; i < graph->nSommets; ++i) {
		printf("(%d)\t", i);
		afficherListe(&graph->adj[i][0]);
		printf("\n");
	}
}

void creerMatriceAdjacences(graphe_t *graph, char *fileName) {
	FILE *file = NULL;
	int indice = 0, donnee = 0, i, j;
	char buffer[27];
	file = fopen(fileName, "r");
	if (file == NULL) {
		fprintf(stderr, "Ouverture du fichier impossible\n");
		exit(EXIT_FAILURE);
	}
	while (fscanf(file, "%s", buffer), !feof(file)) {
		if (strcmp(buffer, "nSommets") == 0) {
			fscanf(file, "%d", &graph->nSommets);
			graph->matrice_adj = (int **) malloc(
					sizeof(int *) * graph->nSommets);
			/* Créer tableau de listes adjacences */
			for (i = 0; i < graph->nSommets; ++i) {
				graph->matrice_adj[i] = (int *) malloc(
						sizeof(int) * graph->nSommets);
			}
			for (i = 0; i < graph->nSommets; ++i) {
				for (j = 0; j < graph->nSommets; ++j) {
					graph->matrice_adj[i][j] = 0;
				}
			}
		} else if (strcmp(buffer, "oriente") == 0) {
			fscanf(file, "%d", &graph->oriente);
		} else if (strcmp(buffer, "value") == 0) {
			fscanf(file, "%d", &graph->evalue);
		} else if (strcmp(buffer, "complet") == 0) {
			fscanf(file, "%d", &graph->complet);
		} else if (strcmp(buffer, "debutDefAretes") == 0) {
			while (fscanf(file, "%s", buffer), strcmp(buffer, "finDefAretes")
					!= 0) {
				indice = atoi(buffer);
				fscanf(file, "%s", buffer);
				donnee = atoi(buffer);
				graph->matrice_adj[indice][donnee] = 1;
				if (!graph->oriente) {
					graph->matrice_adj[donnee][indice] = 1;
				}
			}
		}
	}
}

void afficherMatriceAdjacences(graphe_t *graph) {
	int i, j;
	for (i = 0; i < graph->nSommets; ++i) {
		for (j = 0; j < graph->nSommets; ++j) {
			printf("%d\t", graph->matrice_adj[i][j]);
		}
		printf("\n");
	}
}

graphe_t *creerGraphe(int choice, char *fileName) { /* choice = 1 : liste ; matrice */
	graphe_t *graph = NULL;
	graph = malloc(sizeof(graphe_t));
	if (choice) {
		creerListesAdjacences(graph, fileName);
	} else {
		creerMatriceAdjacences(graph, fileName);
	}
	return graph;
}

void detruireGraphe(graphe_t *graph) {
	int i;
	if (graph->adj != NULL) {
		for (i = 0; i < graph->nSommets; ++i) {
			detruireListe(graph->adj[i]);
		}
		free(graph->adj);
	} else if (graph->matrice_adj != NULL) {
		for (i = 0; i < graph->nSommets; ++i) {
			free(graph->matrice_adj[i]);
		}
		free(graph->matrice_adj);
		graph->matrice_adj = NULL;
	}
	free(graph);
}
