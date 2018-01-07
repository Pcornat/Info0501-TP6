#include "outilsListe.h"

#include <stdio.h>

#include "cellule_adjacence.h"
#include "celluleIncidence.h"

void afficherListeAdjacence(listeAdjacence_t *pliste)
{
	celluleAdjacence_t *ptemp;
	for (ptemp = pliste->tete; ptemp != NULL; ptemp = ptemp->succ)
	{
		printf("noeud : (%d) --> ", ptemp->noeud);
	}
	printf("NULL");
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
