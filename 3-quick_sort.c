#include "sort.h"

/**
 * swap - Swaps two integers
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Partitions the array using the Lomuto scheme
 *
 * @array: The array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: The index of the partition pivot
 */

int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;
	
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, high + 1);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, high + 1);
	return (i + 1);
}
/**
 * quicksort - Recursive function to perform quicksort
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 */
void quicksort(int *array, int low, int high)
{
    int pivot;

    if (low < high)
    {
        pivot = partition(array, low, high);
        quicksort(array, low, pivot - 1);
        quicksort(array, pivot + 1, high);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1);
}
