#include "binary_trees.h"

/**
 * binary_tree_height - function that measures
 * the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: the height of the binary tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t j = 0, i = 0;

		j = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		i = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((j > i) ? j : i);
	}
	return (0);
}
