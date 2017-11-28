#include "outilsListe.h"
#include <stdio.h>
#include <stdlib.h>

void afficherListe(liste_t *pliste)
{
	cellule_t *ptemp;
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
