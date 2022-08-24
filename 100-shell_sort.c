#include "sort.h"

/**
 * shell_sort - sorts an array using shell sort algorithm, knuth sequence
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	int incr, i, j, k, n = size;

	if (array == NULL || size < 2)
		return;

	incr = 1;
	while (incr <= (n / 3))
		incr = 3 * incr + 1;

	while (incr >= 1)
	{
		for (i = incr; i < n; i++)
		{
			k = array[i];

			for (j = i - incr; j >= 0 && k < array[j]; j = j - incr)
				array[j + incr] = array[j];
			array[j + incr] = k;
		}
		incr = incr / 3;
		print_array(array, size);
	}
}
