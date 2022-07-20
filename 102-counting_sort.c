#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */

int get_max(int *array, size_t size)
{
	size_t i;
	int max = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - Sort an array of integers with counting sort
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: Void
 */
void counting_sort(int *array, size_t size)
{
	size_t max, i;
	int *count, *new_array;

	if (array == NULL || size < 2)
		return;
	max = get_max(array, size);
	new_array = malloc(sizeof(int) * size);
	count = malloc(sizeof(int) * max + 1);
	if (count == NULL)
	{
		free(count);
		return;
	}
	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		++count[array[i]];
	for (i = 1; i <= max; i++)
	{
		count[i] = count[i] + count[i - 1];
	}
	print_array(count, max + 1);
	for (i = 0; i < size; i++)
	{
		new_array[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}
	for (i = 0; i < size; i++)
		array[i] = new_array[i];
	free(new_array);
	free(count);
}
