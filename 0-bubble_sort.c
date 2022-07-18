#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: pointer to the array
 * @size: size of the array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int flag = 1;

	if (size < 2)
		return;

	/* Running through each sort pass */
	while (flag)
	{
		flag = 0;

		/* Looping the individul elements */
		for (j = 0; j < size - 1 - i; j++)
		{
			/* Checking if one element is greater than the next */
			if (array[j] > array[j + 1])
			{
				/* Swapping them if it is greater */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				/* Changing the value of flag indicating a swap */
				flag = 1;
			}
		}
	}
}
