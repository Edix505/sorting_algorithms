#include "sort.h"
#include <stdio.h>

/**
 * partition - finds partition 
 * @array: array
 * @lo: lowest index 
 * @hi: highest index 
 * @size: size
 *
 * Return: index of the partition
 */
size_t partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t x, y;
	int swap, pivot;

	pivot = array[hi];
	x = lo - 1;
	for (y = lo; y < hi; y++)
	{
		if (array[y] < pivot)
		{
			x++;
			if (x != y)
			{
				swap = array[x];
				array[x] = array[y];
				array[y] = swap;
				print_array(array, size);
			}
		}
	}
	if (array[hi] < array[x + 1])
	{
		swap = array[x + 1];
		array[x + 1] = array[hi];
		array[hi] = swap;
		print_array(array, size);
	}
	return (x + 1);
}

/**
 * quicksort - sort partition 
 * @array: array
 * @lo: lowest index
 * @hi: highest index
 * @size: size
 *
 * Return: void
 */
void quicksort(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		quicksort(array, lo, pivot - 1, size);
		quicksort(array, pivot + 1, hi, size);

	}
}

/**
 * quick_sort - sort an array
 * Quick sort
 * @array: array
 * @size: size 
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
