#include "binary_trees.h"
/**
 * is_bin_search_tree - check if it is a valid binary search tree
 * @tree:a pointer to the root node of the tree to check.
 * @min: min value
 * @max:max value
 * Return: 1 if the tree is valid bst or 0 otherwise
 */
int is_bin_search_tree(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (is_bin_search_tree(tree->left, min, tree->n)
	&& is_bin_search_tree(tree->right, tree->n, max));
}
/**
 * is_valid - check if the binary tree is a valid binary search tree
 * @tree:a pointer to the root node of the tree to check.
 * @height: pointer to the height of the tree
 * Return: 1 if the tree is a valid binary search tree or 0 otherwise
 */
int is_valid(const binary_tree_t *tree, int *height)
{
	int left_h, right_h = 0;

	if (!tree)
	{
		*height = 0;
		return (1);
	}
	if (!is_bin_search_tree(tree, INT_MIN, INT_MAX))
		return (0);
	if (!is_valid(tree->left, &left_h) || !is_valid(tree->right, &right_h))
		return (0);
	*height = 1 + ((left_h > right_h) ? left_h : right_h);

	return (abs(left_h - right_h) <= 1);
}
/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree:a pointer to the root node of the tree to check.
 * Return: 0 if tree is NULL or 1 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int h = 0;

	if (!tree)
		return (0);
	return (is_valid(tree, &h));
}
