#include "binary_trees.h"

/**
 * balan - measures the balance factor for AVL
 * @tree: tree to go through
 * Return: balanced factor
 */

void balan(avl_t **tree)
{
	int bval;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	balan(&(*tree)->left);
	balan(&(*tree)->right);
	bval = binary_tree_balance((const binary_tree_t *)*tree);
	if (bval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * successor - gets the next successor the min node of the right subtree
 * @node: tree to check
 * Return: the main value of the tree
 */

int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}
}

/**
 * remove_type - function that removes a node depending on its  children
 * @root: node to remove
 * Return: 0 if it has no children
 */

int remove_type(bst_t *root)
{
	int new_val = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_val = successor(root->right);
		root->n = new_val;
		return (new_val);
	}
}

/**
 * bst_remove - remove a node from BST tree
 * @root: root of the tree
 * @value: node with value to remove
 * Return: the changed tree
 */

bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - function that removes a node from an AVL tree
 * @root: pointer to the root node of the tree for removing a node
 * @value: the value to remove in the tree
 * Return: pointer to the new root node of the tree after
 * removing the desired value, and after rebalancing
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	balan(&root_a);
	return (root_a);
}
