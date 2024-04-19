#include "binary_trees.h"

/**
 * tree_size - measures the sum of height of binary tree
 * @tree: pointer to the root node of the tree to measure
 * Return: height else 0 if tree is NULL
 */

size_t tree_size(const binary_tree_t *tree)
{
	size_t height_i = 0;
	size_t height_j = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_i = 1 + tree_size(tree->left);

	if (tree->right)
		height_j = 1 + tree_size(tree->right);

	return (height_i + height_j);
}

/**
 * heap_to_sorted_array - converts a binary max heap to
 * a sorted array of integers
 * @heap: pointer to the root node of the heap
 * @size: address to store the size of the array
 * Return: pointer to array sorted in decending order
 */

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int j, *a = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	a = malloc(sizeof(int) * (*size));
	if (!a)
		return (NULL);

	for (j = 0; heap; j++)
		a[j] = heap_extract(&heap);
	return (a);
}
