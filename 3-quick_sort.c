#include "sort.h"

/**
* swap - swap two integers together
* @a: "int *" second to be swaped
* @b: "int *" first to be swaped
*
* Return: "void" Nothing
*/
void swap(int *a, int *b)
{
	int t = *a;

	*a = *b;
	*b = t;
}

/**
* partition - partition sort of an array in assending order
* @arr: "int *" array to be sorted
* @low: "int" low of the array
* @high: "int" high of the array
* @size: "size_t" size of array
*
* Return: "int" The index of the pivoting element
*/
int partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	print_array(arr, size);
	return (i + 1);
}

/**
* quickSort - quick sort of an array in assending order
* @arr: "int *" array to be sorted
* @low: "int" low of the array
* @high: "int" high of the array
* @size: "size_t" size of array
*
* Return: "void" Nothing
*/
void quickSort(int *arr, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(arr, low, high, size);

		quickSort(arr, low, pi - 1, size);
		quickSort(arr, pi + 1, high, size);
	}
}

/**
* quick_sort - quick sort of an array in assending order
* @array: "int *" array to be sorted
* @size: "size_t" size of array
*
* Return: "void" Nothing
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}
