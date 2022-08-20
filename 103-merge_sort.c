#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * TDMerge - sorts and merges
 * @start: starting index
 * @middle: end index 
 * starting index 
 * @end: end index 
 * @dest: destination
 * @source: source
 *
 * Return: void
 */
void TDMerge(size_t start, size_t middle, size_t end, int *dest, int *source)
{
	size_t a, b, c;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + start, middle - start);
	printf("[right]: ");
	print_array(source + middle, end - middle);
	a = start;
	b = middle;
	for (c = start; c < end; c++)
	{
		if (a < middle && (b >= end || source[a] <= source[b]))
		{
			dest[c] = source[a];
			a++;
		}
		else
		{
			dest[c] = source[b];
			b++;
		}
	}
	printf("[Done]: ");
	print_array(dest + start, end - start);
}

/**
 * TDSplitMerge - recursivelys
 * @start: starting index
 * @end: end index
 * @array: the array
 * @copy: a copy 
 *
 * Return: void
 */
void TDSplitMerge(size_t start, size_t end, int *array, int *copy)
{
	size_t middle;

	if (end - start < 2)
		return;
	middle = (start + end) / 2;
	TDSplitMerge(start, middle, array, copy);
	TDSplitMerge(middle, end, array, copy);
	TDMerge(start, middle, end, array, copy);
	for (middle = start; middle < end; middle++)
		copy[middle] = array[middle];
}

/**
 * merge_sort - sorts an arra
 * Merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	size_t a;
	int *copy;

	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	for (a = 0; a < size; a++)
		copy[a] = array[a];
	TDSplitMerge(0, size, array, copy);
	free(copy);
}
