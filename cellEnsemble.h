/*
 * cellEnsemble.h
 * Utiliser comme cellule adaptée pour les ensembles disjoints.
 *
 */

#ifndef CELLENSEMBLE_H_
#define CELLENSEMBLE_H_


typedef struct cell_ensemble
{
	struct setter_t* representant;
	struct cell_ensemble *succ;
	int noeud;
} cell_ensemble_t;

cell_ensemble_t* creerCellEnsemble(int noeud);
void detruireCellEnsemble(cell_ensemble_t** cell);

#endif /* CELLENSEMBLE_H_ */
