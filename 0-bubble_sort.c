#include "sort.h"

/*
 * bubble_sort - sorts an array of integers in ascending order
 * @array: pointer to the array
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i;
	int tmp = 0;
	int f_swapped;

	if (size >= 2)
	{
		do
		{
			f_swapped = 0;
			for (i = 0; i < size - 1; i++)
			{
				if (array[i] > array[i + 1])
				{
					tmp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = tmp;
					f_swapped = 1;
				}
			}
			print_array(array, size);
		} while (f_swapped == 1);
	}
}
