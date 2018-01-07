#ifndef CELLULE_ADJACENCE_H_
#define CELLULE_ADJACENCE_H_

typedef struct cellule_type
{
	struct cellule_type *pred;
	struct cellule_type *succ;
	int noeud;
} celluleAdjacence_t;

celluleAdjacence_t *initialiserCelluleAdjacence(int noeud); /*Valide*/
void detruireCelluleAdjacence(celluleAdjacence_t **dead); /*Valide*/

#endif /* CELLULE_ADJACENCE_H_ */
