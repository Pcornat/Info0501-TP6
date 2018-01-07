#include "util.h"

void echanger(int * a, int * b)
{
	int p = *a;
	*a = *b;
	*b = p;
}