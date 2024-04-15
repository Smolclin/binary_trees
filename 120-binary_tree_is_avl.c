#include "binary_trees.h"
#include "limits.h"

size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: if the tree is NULL, the function must return 0 else return height
 */

size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t i = 0, j = 0;

		i = tree->left ? 1 + height(tree->left) : 1;
		j = tree->right ? 1 + height(tree->right) : 1;
		return ((i > j) ? i : j);
	}
	return (0);
}

/**
 * is_avl_helper - checks is binary tree is a valid AVL tree
 * @tree: pointer to the root node of the tree to check
 * @lo: the value of the smallest node visited
 * @hi: the value of the largest node visited
 * Return: if the tree is valid AVL tree 1, otherwise return 0
 */

int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t ihgt, jhgt, diff;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		ihgt = height(tree->left);
		jhgt = height(tree->right);
		diff = ihgt > jhgt ? ihgt - jhgt : jhgt - ihgt;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
				is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - function that checks if
 * a binary tree is a valid AVL Tree
 * @tree: the pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
