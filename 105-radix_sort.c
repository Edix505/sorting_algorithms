#include "sort.h"
#include <stdlib.h>

/**
 * pow_10 - calculates 
 * @power: power of 10
 *
 * Return: the corresponding power of 10
 */
unsigned int pow_10(unsigned int power)
{
	unsigned int x, result;

	result = 1;
	for (x = 0; i < power; x++)
		result *= 10;
	return (result);
}

/**
 * count_sort - sorts an array of
 * digit location using the 
 * @array: array to sort
 * @size: size of the array to sort
 * @digit: digit to sort by
 *
 * Return: 1 if there is a need to keep sorting, 0 if not
 */
unsigned int count_sort(int *array, size_t size, unsigned int digit)
{
	int x, count[10] = {0};
	int *copy = NULL;
	size_t y, temp, total = 0;
	unsigned int p1, p2, sort = 0;

	p2 = pow_10(digit - 1);
	p1 = p2 * 10;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		exit(1);
	for (y = 0; y < size; y++)
	{
		copy[y] = array[y];
		if (array[y] / p1 != 0)
			sort = 1;
	}
	for (x = 0; x < 10 ; x++)
		count[x] = 0;
	for (y = 0; y < size; y++)
		count[(array[y] % p1) / p2] += 1;
	for (x = 0; x < 10; x++)
	{
		temp = count[x];
		count[x] = total;
		total += temp;
	}
	for (y = 0; y < size; y++)
	{
		array[count[(copy[y] % p1) / p2]] = copy[y];
		count[(copy[y] % p1) / p2] += 1;
	}
	free(copy);
	return (sort);
}

/**
 * radix_sort - sorts an array of integers in ascending order using
 * the Radix sort algorithm
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	unsigned int x, sort = 1;

	if (array == NULL || size < 2)
		return;
	for (x = 1; sort == 1; x++)
	{
		sort = count_sort(array, size, x);
		print_array(array, size);
	}
}
