#include "binary_trees.h"

/**
 * binary_tree_t *binary_tree_insert_left - function that
 * inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 * Return: pointer to the created node, or NULL
 * on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *nw;

	if (parent == NULL)
		return (NULL);

	nw = binary_tree_node(parent, value);
	if (nw == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		nw->left = parent->left;
		parent->left->parent = nw;
	}
	parent->left = nw;

	return (nw);
}
