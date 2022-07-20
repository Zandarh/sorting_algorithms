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
	size_t j;
	bool flag = true;

	if (array == NULL || size < 2)
		return;

	/* Running through each sort pass */
	while (flag == true)
	{
		flag = false;

		/* Looping the individul elements */
		for (j = 0; j < size - 1; j++)
		{
			/* Checking if one element is greater than the next */
			if (array[j] > array[j + 1])
			{
				/* Changing the value of flag indicating a swap */
				flag = true;
				/* Swapping them if it is greater */
				swap(array, j, j + 1);
				print_array(array, size);
			}
		}
	}
}
