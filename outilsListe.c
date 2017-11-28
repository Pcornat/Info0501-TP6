#include "outilsListe.h"
#include <stdio.h>
#include <stdlib.h>

void afficherListe(liste_t *pliste)
{
	cellule_t *ptemp;
	ptemp = pliste->tete;
	do
	{
		printf("%d --> ", ptemp->value);
		if (ptemp->succ != NULL)
		{
			ptemp = ptemp->succ;
		}
		else
		{
			printf("NULL");
			ptemp = NULL;
		}
	} while (ptemp != NULL);
}
