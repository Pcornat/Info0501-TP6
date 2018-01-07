#include "outilsListe.h"

#include <stdio.h>

#include "cellule_adjacence.h"
#include "celluleIncidence.h"

void afficherListeAdjacence(listeAdjacence_t *pliste)
{
	celluleAdjacence_t *ptemp;
	ptemp = pliste->tete;
	while (ptemp != NULL)
	{
		printf("noeud : (%d) --> ", ptemp->noeud);
		if (ptemp->succ != NULL)
		{
			ptemp = ptemp->succ;
		}
		else
		{
			printf("NULL");
			ptemp = NULL;
		}
	}
}

void afficherListeIncidence(listeIncidence_t *pliste)
{
	celluleIncidence_t *ptemp;
	for (ptemp = pliste->tete; ptemp != NULL; ptemp = ptemp->succ)
	{
		printf("origine (%d), extremite (%d), poids (%d) --> ",
				ptemp->arete->origine, ptemp->arete->extremite,
				ptemp->arete->poids);
	}
	printf("NULL");
}
