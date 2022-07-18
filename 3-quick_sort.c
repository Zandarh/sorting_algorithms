#include "sort.h"
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

void quick_sort_recursion(int *array, size_t low, size_t high, size_t size)
{
     size_t sorted_size;

	/* recursive breakpoint */

    if (low < high)
    {
        sorted_size = partition(array, low, high, size);


        if (sorted_size - low > 1)
            	quick_sort_recursion(array, low, sorted_size - 1, size);    /* sort  new lower */
        if (high - sorted_size > 1)
        		quick_sort_recursion(array, sorted_size + 1, high, size);    /* sort new upper array */
    }
}

size_t partition(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot, i, j;

    i = low;
    pivot = high;

    for (j = low; j < high; j++)
    {
        /* if current element is smaller than pivot */
        if (array[j] < array[pivot])
        {
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
	return (i);
	
}

void swap(int *array, size_t first, size_t second)
{
    int temp;

    temp = array[first];
    array[first] = array[second];
    array[second] = temp;

}