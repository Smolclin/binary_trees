#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - measures the height of binary tree
 * @tree: pointer to the root node of a bianry tree
 * Return: 0 if tree is NULL otherwise height
 */

size_t tree_height(const heap_t *tree)
{
	size_t height_i = 0;
	size_t height_j = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_i = 1 + tree_height(tree->left);

	if (tree->right)
		height_j = 1 + tree_height(tree->right);

	if (height_i > height_j)
		return (height_i);
	return (height_j);
}

/**
 * tree_size_h - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure
 * Return: height or 0 if NULL
 */

size_t tree_size_h(const binary_tree_t *tree)
{
	size_t height_i = 0;
	size_t height_j = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_i = 1 + tree_size_h(tree->left);

	if (tree->right)
		height_j = 1 + tree_size_h(tree->right);

	return (height_i + height_j);
}

/**
 * _preorder - goes through binary tree using pre-order treversal
 * @tree: pointer to the root node of the tree to traverse
 * @node: will be last note in traversal
 * @height: height of tree
 * Return: nothing
 */

void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	_preorder(tree->left, node, height);
	_preorder(tree->right, node, height);
}

/**
 * heapify - heapifies max binary heap
 * @root: pointer to binary heap
 */

void heapify(heap_t *root)
{
	int value;
	heap_t *temp1, *temp2;

	if (!root)
		return;

	temp1 = root;

	while (1)
	{
		if (!temp1->left)
			break;
		if (!temp1->right)
			temp2 = temp1->left;
		else
		{
			if (temp1->left->n > temp1->right->n)
				temp2 = temp1->left;
			else
				temp2 = temp1->right;
		}
		if (temp1->n > temp2->n)
			break;
		value = temp1->n;
		temp1->n = temp2->n;
		temp2->n = value;
		temp1 = temp2;
	}
}

/**
 * heap_extract - extracts the root node from max binary heap
 * @root: pointers to the heap root
 * Return: value of extracted node
 */

int heap_extract(heap_t **root)
{
	int value;
	heap_t *heap_r, *node;

	if (!root || !*root)
		return (0);
	heap_r = *root;
	value = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*root = NULL;
		free(heap_r);
		return (value);
	}
	_preorder(heap_r, &node, tree_height(heap_r));

	heap_r->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(heap_r);
	*root = heap_r;
	return (value);
}
