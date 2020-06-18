#include "sort.h"
/**
 * swap_vals - index array
 * @ai: var1
 * @aj: var2
 */
void swap_vals(int *ai, int *aj)
{
	int aux;

	aux = *ai;
	*ai = *aj;
	*aj = aux;
}
/**
 * partition - function that sorts
 * @array: array sorting
 * @lo: lowest limit
 * @hi: upper limit
 * @size: length array
 * Return: int
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int j, i;
	int pivot = array[hi];

	i = lo;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_vals(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > pivot)
	{
		swap_vals(&array[i], &array[hi]);
		print_array(array, size);
	}

	return (i);
}
/**
 * q_sort - Aux function that sorts
 * @array: list sorted
 * @lo: lowest
 * @hi: highest
 * @size: lenght array
 */
void q_sort(int *array, int lo, int hi, size_t size)
{
	int p = 0;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		q_sort(array, lo, p - 1, size);
		q_sort(array, p + 1, hi, size);
	}
}
/**
 * quick_sort - data to sort
 * @array: array sorted
 * @size: length array
 */
void quick_sort(int *array, size_t size)
{
	int lo = 0, hi = size - 1;

	q_sort(array, lo, hi, size);
}
