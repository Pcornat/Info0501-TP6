#ifndef __TAS_H__
#define  __TAS_H__

#include "arete.h"

typedef struct
{
	int longueur;
	int taille;
	arete_t *tab;
} tas_t;

int parent(int i);
int gauche(int i);
int droite(int i);
void entasserMax(tas_t * t, int i);
void construireTasMax(tas_t * t);
/*void construireTasMax(tas_t * t, int * tab, int longueur_tab);*/

#endif
