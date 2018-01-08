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

void inserer(filePrioriteMin *file, int noeud)
{
	++(file->longueur);
	file->noeuds = (int*) realloc(file->noeuds, file->longueur * sizeof(int));
	file->noeuds[file->longueur - 1] = noeud;
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
	if ((g < file->taille) && (file->noeuds[g] < file->noeuds[i]))
		min = g;
	else
		min = i;
	if ((d < file->taille) && (file->noeuds[d] < file->noeuds[min]))
		min = d;
	if (min != i)
	{
		echangerMin(&(file->noeuds[min]), &(file->noeuds[i]));
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

int extraireMin(filePrioriteMin *file)
{
	int min;
	min = file->noeuds[0];
	file->noeuds[0] = file->noeuds[file->taille - 1];
	file->noeuds[file->taille - 1] = INT_MAX;
	--(file->longueur);
	file->noeuds = (int*) realloc(file->noeuds, file->longueur);
	construireTasMin(file);
	return min;
}

int isEmpty(filePrioriteMin *file)
{
	return (file->noeuds == NULL) ? 1 : 0;
}

void detruireFileMin(filePrioriteMin **file)
{
	(*file)->longueur = (*file)->taille = 0;
	free((*file)->noeuds), free(*file);
	*file = NULL;
}
