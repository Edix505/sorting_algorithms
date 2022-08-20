#include "sort.h"

/**
 * shell_sort - sorts an array 
 * @array: array 
 * @size: size 
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t x, y, gap = 1;
	int insert;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (x = gap; x < size; x++)
		{
			insert = array[x];
			for (y = x; y >= gap && array[y - gap] > insert; y = y - gap)
				array[y] = array[y - gap];
			array[y] = insert;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
