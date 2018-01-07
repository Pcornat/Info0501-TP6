#include "outilsListe.h"
#include <stdio.h>
#include <stdlib.h>

void afficherListeAdjacence(listeAdjacence_t *pliste)
{
	celluleAdjacence_t *ptemp;
	ptemp = pliste->tete;
	while (ptemp != NULL)
	{
		printf("noeud : (%d), poids : (%d) --> ", ptemp->noeud, ptemp->poids);
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
