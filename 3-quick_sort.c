#include "sort.h"
/*
 * partition - Function that will find the partition as Lomuto scheme requires
 * @array: array to partition
 * @low: size to partition
 * @high: size to partition
 * @size: size of array
 * Return: Always an unsigned partition index
 */
size_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t i, j;
	int swap, pivot;

	pivot =  array[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		swap = array[i + 1];
		array[i + 1] = array[high];
		array[high] = swap;
		print_array(array, size);
	}
	return (i + 1);
}
/*
 * compare_sort - Function that will compare the numbers in the indexed positions
 * @array: array to be compared and sorted
 * @low: index of element to be compared
 * @high: index of element to be compared
 * @size: size of array
 */
void compare_sort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		compare_sort(array, low, pivot - 1, size);
		compare_sort(array, pivot + 1, high, size);
	}
}
/*
 * quick_sort - Function that will do quic sorting as per Lomuto scheme
 * @array: array that will be sorted
 * @size: size of the array that will be sorted
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	compare_sort(array, 0, size - 1, size);
}
