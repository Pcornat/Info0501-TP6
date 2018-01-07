#ifndef __TAS_H__
#define  __TAS_H__

typedef struct
{
	int longueur;
	int taille;
	int * tab;
} tas_t;

int parent(int i);
int gauche(int i);
int droite(int i);
void entasserMin(tas_t * t, int i);
void construireTasMin(tas_t * t);
/*void construireTasMax(tas_t * t, int * tab, int longueur_tab);*/

#endif
