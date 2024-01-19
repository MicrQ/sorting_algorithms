#include "sort.h"

/**
 * bubble_sort - a sorting algorithm
 * 
*/

void bubble_sort(int *array, size_t size)
{
	int i, j, tmp;

	for (i = size; i >= 0; i--)
	{
		for (j = 1; j < i; j++)
		{
			if (array[j] < array[j - 1])
			{
				tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
