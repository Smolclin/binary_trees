#include "binary_trees.h"

/**
 * binary_tree_balance - function that measures
 * the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: measurement of the balance factor otherwise
 * If tree is NULL, return 0
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	return (0);
}

/**
 * binary_tree_height - measures the height of the binary tree
 * @tree: pointer to the root node to measure tree
 * Return: height else return 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t i = 0, j = 0;

		i = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		j = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((i > j) ? i : j);
	}
	return (0);
}
