#include "sort.h"

/**
 *
 *
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		return;

	if (array == NULL || size < 2)
		return;

	merge_sort_recursion(array, 0, size - 1, tmp);

	free(tmp);
}

/**
 *
 *
 *
 */
void merge_sort_recursion(int *array, size_t left, size_t right, int *tmp)
{
	size_t mid;

	if (left < right)
	{
		mid = (right + left) / 2;

		merge_sort_recursion(array, left, mid, tmp);
		merge_sort_recursion(array, mid + 1, right, tmp);

		merge_sorted_arrays(array, left, mid, right, tmp);
	}
}

/**
 *
 *
 */
void merge_sorted_arrays(int *array, size_t left, size_t mid, size_t right, int *tmp)
{
	size_t i = 0;
	size_t left_pos = left;
	size_t right_pos = mid + 1;

	printf("Merging..\n[left]: ");
	print_array(array + left, mid + 1);

	printf("[right]: ");
	print_array(array + mid + 1, right - mid);

	for (i = left; left_pos <= mid && right_pos <= right; i++)
	{
		if (array[left_pos] <= array[right_pos])
			tmp[i] = array[left_pos++];
		else
			tmp[i] = array[right_pos++];
	}

	while (left_pos <= mid)
		tmp[i++] = array[left_pos++];

	while (right_pos <= right)
		tmp[i++] = array[right_pos++];

	for (i = 0; i <= right; i++)
		array[i] = tmp[i];

	printf("[Done]: ");
	print_array(tmp, i);
}
