#include "sort.h"

/**
 * selection_sort - sorts an array of integers
 * Select
 * @array: array
 * @size: size
 */
void selection_sort(int *array, size_t size)
{
	size_t x, y, min;
	int swap;

	if (array == NULL || size < 2)
		return;

	for (x = 0; x < size - 1; x++)
	{
		min = x;
		for (y = x + 1; y < size; y++)
		{
			if (array[y] < array[min])
				min = y;
		}
		if (x != min)
		{
			swap = array[x];
			array[x] = array[min];
			array[min] = swap;
			print_array(array, size);
		}
	}
}
