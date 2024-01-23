#include "sort.h"

/**
* bubble_sort - A sorting algorithm implementing bubble sort
* @array: "int *" The unsorted array to be sorted in-place
* @size: "size_t" Size of the array
*
* Return: "void" Nothing
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, swapped = 0;

	if (!array || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				swapped = 1;
			}
		}
		if (swapped == 0)
		{
			break;
		}
	}
}

