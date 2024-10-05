#include "search_algos.h"
/**
 * print_values_searched - print values currently searched in the array.
 * @array:a pointer to the first element of the array to search in
 * @left:left boundary
 * @right:right boundary
 */
void print_values_searched(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}
/**
 * rec_advanced_binary - searches for the first occurence
 * of a value recursively.
 * @array:a pointer to the first element of the array to search in
 * @left:left boundary
 * @right: right boundary
 * @value:the value to search for
 * Return: the index where value is located, or -1 if it is not found
 */
int rec_advanced_binary(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (left > right)
		return (-1);
	print_values_searched(array, left, right);
	mid = (right + left) / 2;
	if (array[mid] == value)
	{
		if (mid == left || array[mid - 1] != value)
			return (mid);
		else
			return (rec_advanced_binary(array, left, mid, value));
	}
	else if (array[mid] > value)
		return (rec_advanced_binary(array, left, mid - 1, value));
	else
		return (rec_advanced_binary(array, mid + 1, right, value));
}
/**
 * advanced_binary - searches for a value in a sorted array of integers.
 * @array:a pointer to the first element of the array to search in
 * @size:the number of elements in array
 * @value:the value to search for
 * Return: the index where value is located
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);
	return (rec_advanced_binary(array, 0, size - 1, value));
}
