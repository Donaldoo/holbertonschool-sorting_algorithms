#include "sort.h"

/**
 * swap - swaps 2 integers
 * @a: int
 * @b: int
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
