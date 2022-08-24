#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/* Gived print functions */

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);


/* prototypes of functions used in this project */

void swap(int *a, int *b);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_sorted_arrays(int *array, size_t left, size_t mid, size_t right);
void merge_sort_recursion(int *array, size_t left, size_t right);

#endif
