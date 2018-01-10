/*
 * filePrioriteMin.h
 *
 *      Author: Florent
 */

#ifndef FILEPRIORITEMIN_H_
#define FILEPRIORITEMIN_H_

#include "algo_parcours.h"

typedef struct
{
	int taille;
	int longueur;
	sommet_t **noeuds;
} filePrioriteMin;

filePrioriteMin* creerFileMin(void);
void inserer(filePrioriteMin *file, sommet_t *som);
int parentMin(int i);
int gaucheMin(int i);
int droiteMin(int i);
void entasserMin(filePrioriteMin * file, int i);
void construireTasMin(filePrioriteMin *file);
sommet_t* extraireMin(filePrioriteMin *file);
int isEmpty(filePrioriteMin *file);
/*int chercherNoeud(filePrioriteMin *file, int noeud);*/
void detruireFileMin(filePrioriteMin **file);

#endif /* FILEPRIORITEMIN_H_ */
