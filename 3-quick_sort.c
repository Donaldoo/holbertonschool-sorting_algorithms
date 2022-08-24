#include "sort.h"
/*
 *
 *
 *
 *
 */
void swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}
/*
 *
 *
 *
 *
 */
int partition(int *array, size_t size)
{
	int low, high, pivot, i, j;

	high = size;
	low = high - (high - 1);
	pivot = array[high];
	i = (low - 1);
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(array + i, array + j);
		}
	}
	swap(array + i + 1, array + high);
	return (i + 1);
}
/*
 *
 *
 *
 */
void quick_sort(int *array, size_t size)
{
	int low, high;


}
