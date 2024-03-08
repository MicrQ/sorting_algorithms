#include "sort.h"
#include <stdio.h>

/**
 * counting_sort - an implementation of count sort.
 *
 * @array: the array to be sorted.
 * @size: the size of the array.
 */

void counting_sort(int *array, size_t size)
{
	unsigned int i;
	int j, max, *frq;

	if (!array || size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	frq = malloc(sizeof(int) * max + 1);
	if (!frq)
		return;

	for (j = 0; j < max + 1; j++)
		frq[j] = 0;

	for (i = 0; i < size; i++)
		frq[array[i]]++;

	for (j = 0; j < max; j++)
		printf("%d, ", frq[j]);
	printf("%d\n", frq[j]);

	i = 0;
	for (j = 0; j < max + 1; j++)
	{
		while (frq[j] > 0)
		{
			array[i] = j;
			i++;
			frq[j]--;
		}
	}
}
