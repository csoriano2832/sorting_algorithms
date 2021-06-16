#include "sort.h"

/**
 * shell_sort - sorts an array of integers using the Shell sort algorithm
 * using the Knuth sequence
 * @array: an array of integers
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	unsigned int gap, i, j;

	if (!array || size < 2)
		return;

	gap = 1;
	while (gap < size / 3)
		gap = 3 * gap + 1;

	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap && array[j] < array[j - gap]; j -= gap)
				shell_swap(array, j, j - gap);
		}
		gap /= 3;
		print_array(array, size);
	}
}

/**
 * shell_swap - swaps two values in place
 * @array: an array of integers
 * @i: position of first value
 * @j: position of second value
 */
void shell_swap(int *array, int i, int j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
