#include "binary_trees.h"

/**
 * bst_insert - function that inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *cur, *new;

	if (tree != NULL)
	{
		cur = *tree;

		if (cur == NULL)
		{
			new = binary_tree_node(cur, value);
			if (new == NULL)
				return (NULL);
			return (*tree = new);
		}
		if (value < cur->n)
		{
			if (cur->left != NULL)
				return
					(bst_insert(&cur->left, value));
			new = binary_tree_node(cur, value);
			if (new == NULL)
				return (NULL);
			return (cur->left = new);
		}
		if (value > cur->n)
		{
			if (cur->right != NULL)
				return
					(bst_insert(&cur->right, value));
			new = binary_tree_node(cur, value);
			if (new == NULL)
				return (NULL);
			return (cur->right = new);
		}
	}
	return (NULL);
}
