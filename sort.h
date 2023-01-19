#ifndef _SORT_H_
#define _SORT_H_


#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

void merge_sort(int *array, size_t size);
void merge(int *array, int *newArray, int left, int mid, int right);
void print_array_2(int *array, int left, int right);
void copy_array(int *array, int start, int end, int *newArray);
void splitting(int *newArray, int *array, int left, int right);

#endif
