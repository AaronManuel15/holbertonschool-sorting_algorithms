#include "sort.h"
#include <stdio.h>


/**
 * maxValueLen - gets largest number in array and returns len of it
 *
 * @array: The array to be looked at
 * @size: Number of elements in @array
 * Return: max value in array
 */
size_t maxValueLen(int *array, size_t size)
{
	int max = array[0];
	size_t i = 0;

	for (i = i; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
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
	int count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int output[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int *temp = malloc(sizeof(*array) * size);
	size_t i;

	for (i = 0; i < size; i++)
	{
		count[(array[i] % (place * 10) / place)]++;
	}
	for (i = 0; i < 9 ; i++)
		output[i + 1] += output[i] + count[i];

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
	if (array && size > 1)
	{
		size_t place;
		int max = maxValueLen(array, size);

		for (place = 1; max / place > 0; place *= 10)
		{
			countingSort(array, size, place);
			print_array(array, size);
		}
	}
}
