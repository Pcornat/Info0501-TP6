#include "graphe.h"

#include <bits/types/FILE.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cellule_adjacence.h"
#include "outilsListe.h"

void creerListesAdjacences(graphe_t *graph, char *fileName)
{
	FILE *file = NULL;
	int indice, donnee, poids, i;
	char buffer[27]; /* buffer suffisamment grand */
	file = fopen(fileName, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Ouverture du fichier impossible\n");
		exit(EXIT_FAILURE);
	}

	while (fscanf(file, "%s", buffer), !feof(file))
	{
		if (strcmp(buffer, "nSommets") == 0)
		{
			fscanf(file, "%d", &graph->nSommets);
			graph->adj = (listeAdjacence_t **) malloc(
					graph->nSommets * sizeof(listeAdjacence_t *));

			/* Créer tableau de listes adjacences */
			for (i = 0; i < graph->nSommets; ++i)
			{
				graph->adj[i] = initialiserListeAdjacence();
			}
		}
		else if (strcmp(buffer, "oriente") == 0)
		{
			fscanf(file, "%d", &graph->oriente);
			if (graph->oriente)
			{
				graph->inc = (listeIncidence_t**) malloc(
						graph->nSommets * sizeof(listeIncidence_t*));
				for (i = 0; i < graph->nSommets; ++i)
				{
					graph->inc[i] = initialiserListeIncidence();
				}
			}
		}
		else if (strcmp(buffer, "value") == 0)
		{
			fscanf(file, "%d", &graph->evalue);
		}
		else if (strcmp(buffer, "complet") == 0)
		{
			fscanf(file, "%d", &graph->complet);
		}
		else if (strcmp(buffer, "debutDefAretes") == 0)
		{
			while (fscanf(file, "%s", buffer), strcmp(buffer, "finDefAretes")
					!= 0)
			{
				indice = atoi(buffer);
				fscanf(file, "%s", buffer);
				donnee = atoi(buffer);
				/**
				 * Si le graphe est évalué, création de la liste d'incidence en même temps.
				 */
				if (graph->evalue)
				{
					fscanf(file, "%s", buffer);
					poids = atoi(buffer);
					insererCelluleAdjacence(graph->adj[indice],
							initialiserCelluleAdjacence(donnee));
					insererCelluleIncidence(graph->inc[indice],
							initialiserCelluleIncidence(
									creerArete(indice, donnee, poids)));
					if (!graph->oriente)
					{
						insererCelluleAdjacence(graph->adj[donnee],
								initialiserCelluleAdjacence(indice));
						insererCelluleIncidence(graph->inc[donnee],
								initialiserCelluleIncidence(
										creerArete(donnee, indice, poids)));
					}
				}
				else
				{
					insererCelluleAdjacence(graph->adj[indice],
							initialiserCelluleAdjacence(donnee));
					if (!graph->oriente)
					{
						insererCelluleAdjacence(graph->adj[donnee],
								initialiserCelluleAdjacence(indice));
					}
				}

			}
		}
	}
	fclose(file);
}

void afficherListesAdjacences(graphe_t *graph)
{
	int i;
	for (i = 0; i < graph->nSommets; ++i)
	{
		printf("(%d)\t", i);
		afficherListeAdjacence(&graph->adj[i][0]);
		printf("\n");
	}
}

void afficherListesIncidences(graphe_t *graph)
{
	int i;
	for (i = 0; graph->nSommets; ++i)
	{
		printf("(%d)\t");
		afficherListeIncidence(graph->inc[i]);
		printf("\n");
	}
}

void creerMatriceAdjacences(graphe_t *graph, char *fileName)
{
	FILE *file = NULL;
	int indice = 0, donnee = 0, poids, i, j;
	char buffer[27];
	file = fopen(fileName, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Ouverture du fichier impossible\n");
		exit(EXIT_FAILURE);
	}
	while (fscanf(file, "%s", buffer), !feof(file))
	{
		if (strcmp(buffer, "nSommets") == 0)
		{
			fscanf(file, "%d", &graph->nSommets);
			graph->matrice_adj = (int **) malloc(
					sizeof(int *) * graph->nSommets);
			/* Créer tableau de listes adjacences */
			for (i = 0; i < graph->nSommets; ++i)
			{
				graph->matrice_adj[i] = (int *) malloc(
						sizeof(int) * graph->nSommets);
			}
			for (i = 0; i < graph->nSommets; ++i)
			{
				for (j = 0; j < graph->nSommets; ++j)
				{
					graph->matrice_adj[i][j] = 0;
				}
			}
		}
		else if (strcmp(buffer, "oriente") == 0)
		{
			fscanf(file, "%d", &graph->oriente);
		}
		else if (strcmp(buffer, "value") == 0)
		{
			fscanf(file, "%d", &graph->evalue);
		}
		else if (strcmp(buffer, "complet") == 0)
		{
			fscanf(file, "%d", &graph->complet);
		}
		else if (strcmp(buffer, "debutDefAretes") == 0)
		{
			while (fscanf(file, "%s", buffer), strcmp(buffer, "finDefAretes")
					!= 0)
			{
				indice = atoi(buffer);
				fscanf(file, "%s", buffer);
				donnee = atoi(buffer);
				if (graph->evalue)
				{
					fscanf(file, "%s", buffer);
					poids = atoi(buffer);
					graph->matrice_adj[indice][donnee] = poids;
					if (!graph->oriente)
					{
						graph->matrice_adj[donnee][indice] = poids;
					}
				}
				else
				{
					graph->matrice_adj[indice][donnee] = 1;
					if (!graph->oriente)
					{
						graph->matrice_adj[donnee][indice] = 1;
					}
				}

			}
		}
	}
}

void afficherMatriceAdjacences(graphe_t *graph)
{
	int i, j;
	printf("\t");
	for (i = 0; i < graph->nSommets; ++i)
	{
		printf("%d\t", i);
	}
	puts("");
	for (i = 0; i < graph->nSommets; ++i)
	{
		printf("%d\t", i);
		for (j = 0; j < graph->nSommets; ++j)
		{
			printf("%d\t", graph->matrice_adj[i][j]);
		}
		printf("\n");
	}
}

graphe_t* creerGraphe(char *fileName)
{
	graphe_t *graph = NULL;
	graph = (graphe_t*) malloc(sizeof(graphe_t));
	creerListesAdjacences(graph, fileName);
	creerMatriceAdjacences(graph, fileName);
	return graph;
}

void detruireGraphe(graphe_t *graph)
{
	int i;
	if (graph->adj != NULL)
	{
		for (i = 0; i < graph->nSommets; ++i)
		{
			detruireListeAdjacence(graph->adj[i]);
		}
		free(graph->adj);
		graph->adj = NULL;
	}
	if (graph->matrice_adj != NULL)
	{
		for (i = 0; i < graph->nSommets; ++i)
		{
			free(graph->matrice_adj[i]);
		}
		free(graph->matrice_adj);
		graph->matrice_adj = NULL;
	}
	if (graph->inc != NULL)
	{
		for (i = 0; i < graph->nSommets; ++i)
		{
			detruireListeIncidence(graph->inc[i]);
		}
		free(graph->inc);
		graph->inc = NULL;
	}
	free(graph);
}
