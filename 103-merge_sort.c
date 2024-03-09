#include "sort.h"

void mergeSort(int *arr, size_t low, size_t high);
void merge(int *arr, size_t low, size_t mid, size_t high);

/**
 * merge_sort - an implemetation of mergeSort sorting alogorithm.
 *
 * @array: the array to be sorted.
 * @size: the size of the array.
 */

void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	mergeSort(array, 0, size);
}


/**
 * mergeSort - the array dividing function.
 *
 * @arr: the array to be sorted.
 * @low: the first index of the given array where the array begins.
 * @high: the highest bound of the array index(max index + 1).
 */

void mergeSort(int *arr, size_t low, size_t high)
{
	size_t mid = (low + high) / 2;

	if (high - low == 1)
		return;

	mergeSort(arr, low, mid);
	mergeSort(arr, mid, high);

	merge(arr, low, mid, high);
}

/**
 * merge - a function that merges a given arrays in increasing order.
 *
 * @arr: the array to be merged.
 * @low: the lower index of the array.
 * @mid: the middle index of the array.
 * @high: the maximum bound of the array.
 */

void merge(int *arr, size_t low, size_t mid, size_t high)
{
	size_t i = low, j = mid, k;
	int *mix = malloc(sizeof(int) * (high - low));

	if (!mix)
		return;

	printf("Merging...\n");
	printf("[left]: ");
	for (k = low; k < mid; k++)
	{
		printf("%d", arr[k]);
		if (k < mid - 1)
			printf(", ");
	}
	printf("\n");

	printf("[right]: ");
	for (k = mid; k < high; k++)
	{
		printf("%d", arr[k]);
		if (k < high - 1)
			printf(", ");
	}
	printf("\n");

	k = 0;
	while (i < mid && j < high)
	{
		if (arr[i] < arr[j])
		{
			mix[k] = arr[i];
			i++;
		}
		else
		{
			mix[k] = arr[j];
			j++;
		}
		k++;
	}

	while (i < mid)
	{
		mix[k] = arr[i];
		k++;
		i++;
	}
	while (j < high)
	{
		mix[k] = arr[j];
		k++;
		j++;
	}

	printf("[Done]: ");
	for (k = 0; k < high - low; k++)
	{
		arr[low + k] = mix[k];
		printf("%d", mix[k]);
		if (k < high - low - 1)
			printf(", ");
	}
	printf("\n");
	free(mix);
}
