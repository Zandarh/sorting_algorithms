#include "sort.h"

/**
 * merge_arrays - merges all the arrays created.
 * @array: pointer to the array
 * @array_buffer: pointer to dynamically created array
 * @low: lower bound
 * @mid: the mid element
 * @high: the higher bound
 * Return: void
 */

void merge_arrays(int *array, int *array_buffer,
		size_t low, size_t mid, size_t high)
{
	 size_t i, j, k;

	i = low;
	j = mid;
	k = low;
	printf("Merging...\n[left]: ");
	print_array(array + low, mid - low);
	printf("[right]: ");
	print_array(array + mid, high - mid);

	while (i != mid && j != high)
	{
		if (array[i] < array[j])
			array_buffer[k++] = array[i++];
		else
			array_buffer[k++] = array[j++];
	}

	while (i < mid)
		array_buffer[k++] = array[i++];
	while (j < high)
		array_buffer[k++] = array[j++];
	for (i = low; i < high; i++)
		array[i] = array_buffer[i];
	printf("[Done]: ");
	print_array(array + low, high - low);
}

/**
 * merge_recursion - recursively divides the array to only one element
 * @array: pointer to the array
 * @array_buffer: pointer to dynamically created array
 * @low: the lower bound in the array
 * @high: the higher boundim the array
 * Return: Void
 */

void merge_recursion(int *array, int *array_buffer, size_t low, size_t high)
{
	size_t mid;

	if (high - low >= 2)
	{
		mid = (high + low) / 2;
		merge_recursion(array, array_buffer, low, mid);
		merge_recursion(array, array_buffer, mid, high);
		merge_arrays(array, array_buffer, low, mid, high);
	}
}

/**
 * merge_sort - sorts an array of int in ascending order
 * @array: pointer to the array
 * @size: the array size
 * Return: Void
 * Descripton: sorts an array of integers using the Merge sort
 */

void merge_sort(int *array, size_t size)
{
	int *array_buffer;
	size_t i;

	if (size < 2)
		return;

	array_buffer = malloc(sizeof(*array_buffer) * size);
	if (array_buffer == NULL)
		return;
	for (i = 0; i < size; i++)
		array_buffer[i] = 0;
	merge_recursion(array, array_buffer, 0, size);
	free(array_buffer);
}
