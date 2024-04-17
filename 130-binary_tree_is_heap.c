#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"

/**
 * check_max - checks ropt as max value
 * @tree: pointer to the root
 * Return: 0 else return 1 if all nodes are max
 */

int check_max(const binary_tree_t *tree)
{
	int temp1 = 1, temp2 = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		temp1 = check_max(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		temp2 = check_max(tree->right);
	}
	return (temp1 && temp2);
}

/**
 * binary_tree_is_heap - checks if binary tree is heap
 * @tree: pointer to the node
 * Return: 0 , 1 incase BST
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{
	int tmp;

	if (!tree)
		return (0);

	tmp = binary_tree_is_complete(tree);
	if (!tmp)
		return (0);
	return (check_max(tree));
}
