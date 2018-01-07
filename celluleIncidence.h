/*
 * celluleIncidence.h
 *
 *      Author: Florent
 */

#ifndef CELLULEINCIDENCE_H_
#define CELLULEINCIDENCE_H_

#include "arete.h"

typedef struct celluleIncidence_type
{
	struct celluleIncidence_type *pred;
	struct celluleIncidence_type *succ;
	arete_t *arete;
} celluleIncidence_t;

celluleIncidence_t *initialiserCelluleIncidence(arete_t *a); /*Valide*/
void detruireCelluleIncidence(celluleIncidence_t **dead); /*Valide*/
#endif /* CELLULEINCIDENCE_H_ */
