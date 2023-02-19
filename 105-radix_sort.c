#include "sort.h"
#include <stdio.h>
#include <math.h>
#define BASE 10

/**
 * maxValueLen - gets largest number in array and returns len of it
 *
 * @array: The array to be looked at
 * @size: Number of elements in @array
 * Return: digit length
 */
size_t maxValueLen(int *array, size_t size)
{
	int max = array[0], len = 1;
	size_t i = 0, count = 1;

	for (i = i; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	while ((max / len) > 0)
	{
		len *= 10;
		count += 1;
	}
	return (--count);
}
/**
 * countingSort - sorts an array of ints in ascending order by place
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @place: base value of 10s position to sort by
 */
void countingSort(int *array, size_t size, size_t place)
{
	size_t output[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
	size_t count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t *temp = malloc(sizeof(*array) * size);
	size_t i;

	for (i = 0; i < size; ++i)
	{
		count[i] = 0;
		output[i] = 0;
		temp[i] = 0;
	}

	for (i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;

	for (i = 1; i <= size; i++)
		output[i] += output[i - 1] + count[i - 1];

	for (i = 0; i < size; i++)
	{
		temp[output[array[i] % (place * 10) / place]] = array[i];
		output[array[i] % (place * 10) / place]++;
	}

	for (i = 0; i < size; i++)
		array[i] = temp[i];

	free(temp);
}
/**
 * radix_sort - sorts an array of ints in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */

void radix_sort(int *array, size_t size)
{
	size_t place, digitCount = maxValueLen(array, size), i;

	for (i = 1, place = 1; i <= digitCount; i++, place *= BASE)
	{
		countingSort(array, size, place);
		print_array(array, size);
	}
}
