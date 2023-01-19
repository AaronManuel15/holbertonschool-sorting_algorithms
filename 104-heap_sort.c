#include "sort.h"


/**
 * heap_sort - initiates the heap sort from given array
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */

void heap_sort(int *array, size_t size)
{
	int i = size / 2 - 1;

	for (i = i; i >= 0; i--)
	{
		heapify(array, size, i, size);
	}

	for (i = size - 1; i >= 0; i--)
	{
		int temp = array[i];

		array[i] = array[0];
		array[0] = temp;
		if (i > 0)
			print_array(array, size);
		heapify(array, i, 0, size);

	}
}


/**
 * heapify - reorders the tree with root i
 *
 * @array: The array to be reordered
 * @n: number of elements in array as well
 * @i: root to compare
 * @size: Number of elements in @array
 */

void heapify(int *array, int n, int i, size_t size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && array[left] > array[largest])
		largest = left;

	if (right < n && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		int temp = array[i];

		array[i] = array[largest];
		array[largest] = temp;
		print_array(array, size);

		heapify(array, n, largest, size);
	}
}
