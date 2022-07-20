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
 * bubble_sort - sorts an array of integers in ascending order
 * @array: pointer to the array
 * @size: size of the array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
