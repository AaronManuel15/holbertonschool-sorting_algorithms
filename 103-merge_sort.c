#include "sort.h"
#include <stddef.h>

/**
 * merge_sort - initiates the merge sort from given array
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */

void merge_sort(int *array, size_t size)
{
	int *newArray = malloc(sizeof(array[0]) * size);

	copy_array(array, 0, size, newArray);
	splitting(newArray, array, 0, size);
	free(newArray);
}

/**
 * splitting - recursively splits the array
 *
 * @newArray: newArray to help with sorting
 * @array: The array to be sorted
 * @left: far left element index
 * @right: far right element index
 */

void splitting(int *newArray, int *array, int left, int right)
{
	int mid = (left + right) / 2;

	if (right - left <= 1)
	{
		return;
	}
	splitting(array, newArray, left, mid);
	splitting(array, newArray, mid, right);

	merge(newArray, array, left, mid, right);
}

/**
 * merge - compares and merges elements back into original array
 *
 * @array: The array to be sorted
 * @newArray: newArray to help with sorting
 * @left: far left element index
 * @mid: middle element index where array is split
 * @right: far right element index
 */

void merge(int *array, int *newArray, int left, int mid, int right)
{
	int i, j, k;

	i = left;
	j = mid;
	k = left;
	while (k < right)
	{
		if (i < mid && (array[i] <= array[j] || j >= right))
		{
			newArray[k] = array[i];
			i++;
		}
		else
		{
			newArray[k] = array[j];
			j++;
		}
		k++;
	}
	printf("Merging...\n[left]: ");
	print_array_2(array, left, mid);
	printf("[right]: ");
	print_array_2(array, mid, right);
	printf("[Done]: ");
	print_array_2(newArray, left, k);
}

/**
 * print_array_2 - prints the given arrays elements in the provided range
 *
 * @array: The array to be printed
 * @left: left bound of index range to be printed
 * @right: right bound of index range to be printed
 */

void print_array_2(int *array, int left, int right)
{
	int i = left;

	while (array && i < right)
	{
		if (i > left)
			printf(", ");
		printf("%d", array[i]);
		i++;
	}
	printf("\n");
}

/**
 * copy_array - copies one array into another
 *
 * @array: The array to be copied
 * @start: left bound of index range to be copied
 * @end: right bound of index range to be copied
 * @newArray: new array that array is being copied to
 */

void copy_array(int *array, int start, int end, int *newArray)
{
	int i;

	for (i = start; i < end; i++)
		newArray[i] = array[i];
}
