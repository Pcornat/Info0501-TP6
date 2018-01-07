/*
 * listeIncidence.c
 *
 *      Author: Florent
 */

#include "listeIncidence.h"

#include <stdlib.h>


listeIncidence_t *initialiserListeIncidence()
{
	listeIncidence_t *liste = NULL;
	liste = (listeIncidence_t*) malloc(sizeof(listeIncidence_t));
	liste->tete = NULL;
	return liste;
}

void insererCelluleIncidence(listeIncidence_t *pliste,
		celluleIncidence_t *pcell)
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

celluleIncidence_t *rechercherCelluleIncidence(listeIncidence_t *pliste,
		int origine, int extremite, int poids)
{
	celluleIncidence_t *pcell = NULL;
	pcell = pliste->tete;
	while ((origine != pcell->arete->origine
			&& extremite != pcell->arete->extremite
			&& poids != pcell->arete->poids)
			|| (origine != pcell->arete->extremite
					&& extremite != pcell->arete->origine
					&& poids != pcell->arete->poids))
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

void supprimerCelluleIncidence(listeIncidence_t *pliste,
		celluleIncidence_t *pcell)
{
	celluleIncidence_t *ptemp;
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

void detruireListeIncidence(listeIncidence_t *pliste)
{
	/* Pointeurs pour parcourir la liste et mémoriser "celui à détruire" */
	celluleIncidence_t *ptemp = NULL, *pdel = NULL;
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
