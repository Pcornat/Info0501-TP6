#ifndef CELLULE_H_
#define CELLULE_H_

typedef struct cellule_type
{
	struct cellule_type *pred;
	struct cellule_type *succ;
	int value;
} cellule_t;

cellule_t *initialiserCellule(int value); //Valide
void detruireCellule(cellule_t **dead);   //Valide

#endif /* CELLULE_H_ */
