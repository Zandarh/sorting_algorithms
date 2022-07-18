#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: pointer to the array
 * @size: size of the array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t min;
	int temp;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;

		/* looping to get the lowest. swap it with first in the unsorted array */
		for (j = i + 1; j < size; j++)
		{
			/* checking to find the lowest number, and updating min */
			if (array[j] < array[min])
			{
				min = j;
			}
		}

		/* Checking if the lowest number == i(The first no in the unsorted array */
		if (min != i)
		{
			/* sawp the value first in the unsorted list with the lowest number */
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
