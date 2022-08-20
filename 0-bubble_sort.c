#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts an array 
 * @array: array of ints to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int x, y;
	int tmp;

	if (size < 2)
		return;

	for (x = 0; x < size; x++)
	{
		for (y = 0; y < size - x - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				tmp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
