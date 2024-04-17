#include "binary_trees.h"

/**
 * create_tree - creates an AVL tree with recursion
 * @node: pointer node
 * @array: input array of integers
 * @size: size of array
 * @mode: adding on the left 1, adding on the right 2
 * Return: 0
 */

void create_tree(avl_t **node, int *array, size_t size, int mode)
{
	size_t middle;

	if (size == 0)
		return;

	middle = (size / 2);
	middle = (size % 2 == 0) ? middle - 1 : middle;

	if (mode == 1)
	{
		(*node)->left = binary_tree_node(*node, array[middle]);
		create_tree(&((*node)->left), array, middle, 1);
		create_tree(&((*node)->left), array + middle + 1, (size - 1 - middle), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[middle]);
		create_tree(&((*node)->right), array, middle, 1);
		create_tree(&((*node)->right), array + middle + 1, (size - 1 - middle), 2);
	}
}

/**
 * sorted_array_to_avl - create root node and calls to create_tree
 * @array: input array of integers
 * @size: size of array
 * Return: pointer to the root
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t midd;

	root = NULL;

	if (size == 0)
		return (NULL);

	midd = (size / 2);

	midd = (size % 2 == 0) ? midd - 1 : midd;
	root = binary_tree_node(root, array[midd]);

	create_tree(&root, array, midd, 1);
	create_tree(&root, array + midd + 1, (size - 1 - midd), 2);

	return (root);
}
