#include "search_algos.h"

/**
 * linear_search - Performs a linear search algo
 *
 * @array: pointer to first element of array being searched
 * @size: number of elements in array
 * @value: value to search for in array
 * Return: first index where value is found upon success, else -1
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i = 0;

	for (i = i; i < size; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
		{
			return (i);
		}
	}
	return (-1);
}
