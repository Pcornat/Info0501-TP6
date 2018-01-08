/*
 * filePrioriteMin.h
 *
 *      Author: Florent
 */

#ifndef FILEPRIORITEMIN_H_
#define FILEPRIORITEMIN_H_

typedef struct
{
	int taille;
	int longueur;
	int *noeuds;
} filePrioriteMin;

filePrioriteMin* creerFileMin(void);
void inserer(filePrioriteMin *file, int noeud);
int parentMin(int i);
int gaucheMin(int i);
int droiteMin(int i);
void entasserMin(filePrioriteMin * file, int i);
void construireTasMin(filePrioriteMin * file);
int extraireMin(filePrioriteMin *file);
int isEmpty(filePrioriteMin *file);
int chercherNoeud(filePrioriteMin *file, int noeud);
void detruireFileMin(filePrioriteMin **file);

#endif /* FILEPRIORITEMIN_H_ */
