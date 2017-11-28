#ifndef CELLULE_H_
#define CELLULE_H_

typedef struct cellule_type
{
	struct cellule_type *pred;
	struct cellule_type *succ;
	int noeud;
	int poids;
} cellule_t;

cellule_t *initialiserCellule(int noeud, int poids); /*Valide*/
void detruireCellule(cellule_t **dead);   /*Valide*/

#endif /* CELLULE_H_ */
