#ifndef ARETE_H_
#define ARETE_H_

typedef struct
{
	int origine;
	int extremite;
	int poids;
} arete_t;

arete_t* creerArete(int origine, int extremite, int poids);
void detruireArete(arete_t **a);

#endif /* ARETE_H_ */
