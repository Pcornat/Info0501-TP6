/*
 * filePrioriteMin.c
 *
 *      Author: Florent
 */

#include "filePrioriteMin.h"

#include <stdlib.h>
#include <limits.h>

#include "util.h"

filePrioriteMin* creerFileMin(void)
{
	filePrioriteMin *file = NULL;
	file = (filePrioriteMin*) malloc(sizeof(filePrioriteMin));
	file->taille = file->longueur = 0;
	file->noeuds = NULL;
	return file;
}

void inserer(filePrioriteMin *file, sommet_t *som)
{
	++(file->longueur);
	file->noeuds = (sommet_t**) realloc(file->noeuds,
			file->longueur * sizeof(sommet_t*));
	file->noeuds[file->longueur - 1] = som;
	construireTasMin(file);
}

int parentMin(int i)
{
	++i;
	i >>= 1;
	return --i;
}

int droiteMin(int i)
{
	return (i <<= 1) + 2;
}

int gaucheMin(int i) /* En C, gauche les indices sont impaires */
{
	return (i <<= 1) + 1;
}

void entasserMin(filePrioriteMin *file, int i)
{
	int g = gaucheMin(i), d = droiteMin(i), min;
	if ((g < file->taille) && (file->noeuds[g]->key < file->noeuds[i]->key))
		min = g;
	else
		min = i;
	if ((d < file->taille) && (file->noeuds[d]->key < file->noeuds[min]->key))
		min = d;
	if (min != i)
	{
		echangerMin(file->noeuds[min], file->noeuds[i]);
		entasserMin(file, min);
	}
}

void construireTasMin(filePrioriteMin * file)
{
	int i;
	file->taille = file->longueur;
	for (i = parentMin(file->longueur - 1); i >= 0; --i)
	{
		entasserMin(file, i);
	}
}

sommet_t* extraireMin(filePrioriteMin *file)
{
	sommet_t *min;
	min = file->noeuds[0];
	file->noeuds[0] = file->noeuds[file->taille - 1];
	file->noeuds[file->taille - 1] = NULL;
	--(file->longueur);
	file->noeuds = (sommet_t**) realloc(file->noeuds,
			file->longueur * sizeof(sommet_t*));
	construireTasMin(file);
	return min;
}

int isEmpty(filePrioriteMin *file)
{
	return (file->longueur == 0) ? 1 : 0;
}

/*
 int chercherNoeud(filePrioriteMin *file, int noeud)
 {
 int i;
 for (i = 0; i < file->longueur; ++i)
 {
 if (file->noeuds[i] == noeud)
 return 1;
 }
 return 0;
 }*/

void detruireFileMin(filePrioriteMin **file)
{
	(*file)->longueur = (*file)->taille = 0;
	free((*file)->noeuds), free(*file);
	*file = NULL;
}
