#include "sort.h"

/**
 *
 *
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	merge_sort_recursion(array, 0, size - 1);
}

/**
 *
 *
 *
 */
void merge_sort_recursion(int *array, size_t left, size_t right)
{
	size_t mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;

		merge_sort_recursion(array, left, mid);
		merge_sort_recursion(array, mid + 1, right);

		merge_sorted_arrays(array, left, mid, right);
	}
}

/**
 *
 *
 */
void merge_sorted_arrays(int *array, size_t left, size_t mid, size_t right)
{
	size_t i, j, k = 0;
	size_t left_len = mid - left + 1;
	size_t right_len = right - mid;
	int tmp_left[left_len];
	int tmp_right[right_len];

	printf("Merging..\n[left]: ");
	print_array(array + left, mid - left);

	printf("[right]: ");
	print_array(array + mid + 1, right - mid);

	for (i = 0; i < left_len; i++)
		tmp_left[i] = array[left + i];

	for (i = 0; i < right_len; i++)
		tmp_right[i] = array[mid + 1 + i];

	for (i = 0, j = 0, k = left; k <= right; k++)
	{
		if ((i < left_len) && (j >= right_len || tmp_left[i] <= tmp_right[j]))
		{
			array[k] = tmp_left[i];
			i++;
		}
		else
		{
			array[k] = tmp_right[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(array + left, right - left);
}
