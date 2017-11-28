#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "graphe.h"
#include "cellule.h"
#include "outilsListe.h"
#include "file.h"

void creerListesAdjacences(graphe_t *graph)
{
	FILE *file = NULL;
	int indice, donnee, poids, i;
	char buffer[27]; /* buffer suffisamment grand */
	file = fopen("graphe1.txt", "r");
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
			graph->adj = (liste_t **)malloc(graph->nSommets * sizeof(liste_t *));
			/* Créer tableau de listes adjacences */
			for (i = 0; i < graph->nSommets; ++i)
			{
				graph->adj[i] = initialiserListe();
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
			/**
			 * TODO: modifier pour intégrer le poids dans la création des cellules.
			 * Faite.
			 */
			while (fscanf(file, "%s", buffer), strcmp(buffer, "finDefAretes") != 0)
			{
				indice = atoi(buffer);
				fscanf(file, "%s", buffer);
				donnee = atoi(buffer);
				fscanf(file, "%s", buffer);
				poids = atoi(buffer);
				inserer(graph->adj[indice], initialiserCellule(donnee, poids));
				if (!graph->oriente)
				{
					inserer(graph->adj[donnee], initialiserCellule(indice, poids));
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
		afficherListe(&graph->adj[i][0]);
		printf("\n");
	}
}

void creerMatriceAdjacences(graphe_t *graph)
{
	FILE *file = NULL;
	int indice = 0, donnee = 0, i, j;
	char buffer[27];
	file = fopen("graphe1.txt", "r");
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
			graph->matrice_adj = (int **)malloc(
				sizeof(int *) * graph->nSommets);
			/* Créer tableau de listes adjacences */
			for (i = 0; i < graph->nSommets; ++i)
			{
				graph->matrice_adj[i] = (int *)malloc(
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
			while (fscanf(file, "%s", buffer), strcmp(buffer, "finDefAretes") != 0)
			{
				indice = atoi(buffer);
				fscanf(file, "%s", buffer);
				donnee = atoi(buffer);
				graph->matrice_adj[indice][donnee] = 1;
				if (!graph->oriente)
				{
					graph->matrice_adj[donnee][indice] = 1;
				}
			}
		}
	}
}

void afficherMatriceAdjacences(graphe_t *graph)
{
	int i, j;
	for (i = 0; i < graph->nSommets; ++i)
	{
		for (j = 0; j < graph->nSommets; ++j)
		{
			printf("%d\t", graph->matrice_adj[i][j]);
		}
		printf("\n");
	}
}

graphe_t *creerGraphe(int choice)
{ /* choice = 1 : liste ; matrice */
	graphe_t *graph = NULL;
	graph = malloc(sizeof(graphe_t));
	if (choice)
	{
		creerListesAdjacences(graph);
	}
	else
	{
		creerMatriceAdjacences(graph);
	}
	return graph;
}

void detruireGraphe(graphe_t *graph)
{
	int i;
	if (graph->adj != NULL)
	{
		for (i = 0; i < graph->nSommets; ++i)
		{
			detruireListe(graph->adj[i]);
		}
		free(graph->adj);
	}
	else if (graph->matrice_adj != NULL)
	{
		for (i = 0; i < graph->nSommets; ++i)
		{
			free(graph->matrice_adj[i]);
		}
		free(graph->matrice_adj);
		graph->matrice_adj = NULL;
	}
	free(graph);
}

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
		sommet[i].pere = NULL;
	}
	sommet[sommetOrigine].couleur = gris;
	sommet[sommetOrigine].distance = 0;
	sommet[sommetOrigine].pere = NULL;
	enfile(queue, graph->adj[sommetOrigine]->tete->noeud);
	while (!file_isEmpty(queue))
	{
		u = front(queue);
		for (cell = graph->adj[u]->tete; cell != NULL; cell = cell->succ)
		{
			if (sommet[cell->noeud].couleur == blanc)
			{
				sommet[cell->noeud].couleur = gris;
				sommet[cell->noeud].distance = sommet[u].distance + 1;
				sommet[cell->noeud].pere = &(sommet[u]);
				enfile(queue, cell->noeud);
			}
		}
		sommet[u].couleur = noir;
		defile(queue);
	}
	detruireFile(queue);
}
