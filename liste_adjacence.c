#include <stdlib.h>
#include "liste_adjacence.h"

listeAdjacence_t *initialiserListeAdjacence()
{
	listeAdjacence_t *liste = NULL;
	liste = (listeAdjacence_t*) malloc(sizeof(listeAdjacence_t));
	liste->tete = NULL;
	return liste;
}

void insererCelluleAdjacence(listeAdjacence_t *pliste,
		celluleAdjacence_t *pcell)
{
	if (pliste->tete != NULL)
	{
		pcell->succ = pliste->tete;
		pcell->pred = NULL;
		pliste->tete->pred = pcell;
		pliste->tete = pcell;
	}
	else
	{
		pcell->succ = pcell->pred = NULL;
		pliste->tete = pcell;
	}
}

celluleAdjacence_t *rechercherCelluleAdjacence(listeAdjacence_t *pliste,
		int value)
{
	celluleAdjacence_t *pcell = NULL;
	pcell = pliste->tete;
	while (value != pcell->noeud)
	{
		if (pcell->succ != NULL)
		{
			pcell = pcell->succ;
		}
		else
			return NULL;
	}
	return pcell;
}

void supprimerCelluleAdjacence(listeAdjacence_t *pliste,
		celluleAdjacence_t *pcell)
{
	celluleAdjacence_t *ptemp;
	ptemp = pliste->tete;
	while (ptemp != pcell)
	{
		ptemp = ptemp->succ;
	}
	if (ptemp->succ == NULL && ptemp->pred != NULL)
	{ /*En fin de liste*/
		ptemp->pred->succ = NULL;
		free(ptemp);
	}
	else if (ptemp->pred == NULL && ptemp->succ != NULL)
	{ /*Tête de liste*/
		pliste->tete = ptemp->succ;
		ptemp->succ->pred = NULL;
		free(ptemp);
	}
	else if (ptemp->succ != NULL && ptemp->pred != NULL)
	{ /*Dans liste*/
		ptemp->pred->succ = ptemp->succ;
		ptemp->succ->pred = ptemp->pred;
		free(ptemp);
	}
	else
	{ /* Si seul*/
		pliste->tete = NULL;
		free(ptemp);
	}
}

void detruireListeAdjacence(listeAdjacence_t *pliste)
{
	/* Pointeurs pour parcourir la liste et mémoriser "celui à détruire" */
	celluleAdjacence_t *ptemp = NULL, *pdel = NULL;
	if (pliste != NULL)
	{
		ptemp = pliste->tete;
		while (ptemp != NULL)
		{
			pdel = ptemp;
			ptemp = ptemp->succ;
			free(pdel);
		}
	}
}
