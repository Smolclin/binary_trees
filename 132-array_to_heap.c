#include "binary_trees.h"

/**
 * array_to_heap - function that builds a Max Binary Heap tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: pointer to the root node of the created Binary Heap,
 * or NULL on failure
 */

heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int j;
	heap_t *root = NULL;

	for (j = 0; j < size; j++)
		heap_insert(&root, array[j]);

	return (root);
}
