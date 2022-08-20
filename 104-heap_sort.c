#include "sort.h"

/**
 * sift_down 
 * @array: 
 * @root: the root 
 * @end: the last index 
 * @size: size 
 *
 * Return: void
 */
void sift_down(int *array, size_t root, size_t end, size_t size)
{
	size_t left_chd, right_chd, swap;
	int tmp;

	while ((left_chd = (2 * root) + 1) <= end)
	{
		swap = root;
		right_chd = left_chd + 1;
		if (array[swap] < array[left_chd])
			swap = left_chd;
		if (right_chd <= end && array[swap] < array[right_chd])
			swap = right_chd;
		if (swap == root)
			return;
		tmp = array[root];
		array[root] = array[swap];
		array[swap] = tmp;
		print_array(array, size);
		root = swap;
	}
}

/**
 * make_heap - makes a heap
 * @array: array 
 * @size: size 
 *
 * Return: void
 */
void make_heap(int *array, size_t size)
{
	size_t prt;

	for (prt = ((size - 1) - 1) / 2; 1; prt--)
	{
		sift_down(array, prt, size - 1, size);
		if (prt == 0)
			break;
	}
}

/**
 * heap_sort - sorts
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	int tmp;

	if (array == NULL || size < 2)
		return;
	make_heap(array, size);
	end = size - 1;
	while (end > 0)
	{
		tmp = array[end];
		array[end] = array[0];
		array[0] = tmp;
		print_array(array, size);
		end--;
		sift_down(array, 0, end, size);
	}
}
