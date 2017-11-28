#include "file.h"
#include <stdlib.h>
#include <limits.h>

file_t *creerFile(unsigned int capacite)
{
	file_t *queue = (file_t *)malloc(sizeof(file_t));
	queue->capacity = capacite;
	queue->front = queue->size = 0;
	queue->rear = capacite - 1;
	queue->array = (int *)malloc(queue->capacity * sizeof(int ));
	return queue;
}

void detruireFile(file_t *queue)
{
	free(queue->array);
	free(queue);
	queue = NULL;
}

int file_isFull(file_t *queue)
{
	return (queue->size == queue->capacity);
}

int file_isEmpty(file_t *queue)
{
	return (queue->size == 0);
}

void enfile(file_t *queue, int item)
{
	if (file_isFull(queue))
		return;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	++(queue->size);
}

int defile(file_t *queue)
{
	if (file_isEmpty(queue))
		return INT_MAX;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	--(queue->size);
	return item;
}

int front(file_t *queue)
{
	if (file_isEmpty(queue))
		return INT_MAX;
	return queue->array[queue->front];
}

int rear(file_t *queue)
{
	if (file_isEmpty(queue))
		return INT_MAX;
	return queue->array[queue->rear];
}
