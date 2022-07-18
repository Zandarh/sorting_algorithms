#include "sort.h"

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
 * shell_sort_with_gap - Insertion sort with a defined gap
 * @array: Array to sort
 * @gap: Gap between values to swap
 * @size: Size of array
 */
void shell_sort_with_gap(int *array, int gap, int size)
{
	int	i = 0, j = 0;

	while (i + gap < size)
	{
		if (array[i] > array[i + gap])
		{
			j = i;
			while (j >= 0 && array[j] > array[j + gap])
			{
                swap(array, j, j + gap);
				j -= gap;
			}
		}
		i++;
	}
}

/**
 * knuth_sequence - Returns the number of the Knuth sequence
 * @i: Index of the number
 * Return: Number at index @i of the Knuth squence
 */
size_t knuth_sequence(int i)
{
	size_t	n = 1;

	while (i--)
		n = n * 3 + 1;
	return (n);
}

/**
 * shell_sort - Sorts an array using Shell Sort method
 * @array: Array to sort
 * @size: size of @array
 */
void shell_sort(int *array, size_t size)
{
	int i = 0;

	if (size < 2)
		return;

	while (knuth_sequence(i + 1) < size)
		i++;
	while (i >= 0)
	{
		shell_sort_with_gap(array, knuth_sequence(i), size);
		print_array(array, size);
		i--;
	}
}