#include "sort.h"

/**
 * quick_sort - main calling function
 * @array: an array of integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quickSort(array, 0, size - 1, size);
}

/**
 * quickSort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: an array of integers
 * @lo: all of the elements in the array whose value is less than pivot
 * @hi: all of the elements in the array whose value is greater than pivot
 * @size: size of the array
 */
void quickSort(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		quickSort(array, lo, p - 1, size);
		quickSort(array, p + 1, hi, size);
	}

}

/**
 * partition - divides the array into two smaller arrays
 * @array: an array of integers
 * @lo: all of the elements in the array whose value is less than pivot
 * @hi: all of the elements in the array whose value is greater than pivot
 * @size: size of the array
 *
 * Return: the pivot point position in which the elements will be divided
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot;
	int i, j;

	pivot = array[hi];
	i = lo;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			swap(array, i, j, size);
			i++;
		}
	}
	swap(array, i, hi, size);
	return (i);
}

/**
 * swap - swaps two values in an array
 * @array: an array of integers
 * @i: first position in the array to be swapped
 * @j: second position in the array to be swapped
 * @size: size of the array
 */
void swap(int *array, int i, int j, size_t size)
{
	int temp;

	if (array[i] != array[j])
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}
