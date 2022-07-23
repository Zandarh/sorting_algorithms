#include "sort.h"

/**
 * swap - swaps two integers in an array
 * @first: first integer
 * @second: second integer
 * Return: void
 */

void swap(int *first, int *second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

/**
 * max_heapify = Converts a binary tree into a binary heap
 * @array: pointer to the array
 * @size: size of the array/tree
 * @base: The index of the base row of the tree
 * @root: The root node pf the binary tree
 * Return: void
 *
 */

void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t right, left, large;

	left = 2 * root + 1;
	large = root;
	right = 2 * root + 2;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}


/**
 * heap_sort - sorts an array of integers in ascending order using the Heap sort algorithm
 * @array: pointer to the array
 * @size: size of the array
 * Return: void
 *
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;
	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);
	
	for (i = size - 1; i > 0; i--)
	{
		swap(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
