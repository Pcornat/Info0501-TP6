#ifndef FILE_H_
#define FILE_H_

#include "cellule.h"

typedef struct file
{
	int front, rear, size, capacity;
	int *array;
} file_t;

file_t *creerFile(unsigned int capacite);
void detruireFile(file_t *queue);
int file_isFull(file_t *queue);
int file_isEmpty(file_t *queue);
void enfile(file_t *queue, int item);
int defile(file_t *queue);
int front(file_t *queue);
int rear(file_t *queue);

#endif /* FILE_H_ */
