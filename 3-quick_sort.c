#include "sort.h"

/**
 * partition - partitions an array using Lumoto partition scheme
 * @array: pointer to the array
 * @low: lower bound
 * @high: higher bound
 * @size: size of the array
 * Return: position of the pivot
 **/

size_t partition(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot, i, j;

	i = low;

	pivot = high;  /* assigns pivot to the last element */

	/* loop from element 0 to element high */
	for (j = low; j < high; j++)
	{
		/* if current element is smaller than pivot */
		if (array[j] < array[pivot])
		{
			/* check that index of lower bound is not equal to upper bound */
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, size);
			}

			i++;
		}
	}

	if (i != j)
	{
		swap(array, i, j);
		print_array(array, size);
	}

	/* return the new position of the pivot */
	return (i);
}

/**
 * quick_sort_recursion - recusrsivly sorts the partition array
 * @array: ointer to the array
 * @low: lower bound
 * @high: higher bound
 * @size: size of the array
 * Return: void
 */

void quick_sort_recursion(int *array, size_t low, size_t high, size_t size)
{
	size_t sorted_size;

	/* recursive breakpoint */
	if (low < high)
	{
		sorted_size = partition(array, low, high, size);

		/* checks if the lower partion is more than 2 */
		if (sorted_size - low > 1)
			/* sort new lower array */
			quick_sort_recursion(array, low, sorted_size - 1, size);

		/* cecks if the upper partion is more than two */
		if (high - sorted_size > 1)
			/* sort new upper array */
			quick_sort_recursion(array, sorted_size + 1, high, size);
	}
}

/**
 * swap - swaps the elemnts in a array
 * @array: pointer to the aray
 * @first: first element
 * @second: second element
 * Return: Void
 */

void swap(int *array, size_t first, size_t second)
{
	int temp;

	temp = array[first];
	array[first] = array[second];
	array[second] = temp;
}

/**
 * quick_sort - sorts array of int in ascending order with Qs
 * @array: Pointer to the array
 * @size: Size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_sort_recursion(array, 0, size - 1, size);
}
