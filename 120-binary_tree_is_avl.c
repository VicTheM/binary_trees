#include "binary_trees.h"

/**
 * height - Measure the height of a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: The height of a binary tree.
 */
size_t height(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);
	left = tree->left ? 1 + height(tree->left) : 1;
	right = tree->right ? 1 + height(tree->right) : 1;

	return (left > right ? left : right);
}

/**
 * is_balance - Measures the balance factor of a binary tree.
 *
 * @tree: Pointer to the root node of the tree
 * to measure the balance factor.
 *
 * Return: 1 if balanced and 0 else.
 */
int is_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (height(tree->left) - height(tree->right));
}

/**
 * is_avl - Recursive function to check if a binary trree
 * is a valid AVL Tree.
 *
 * @tree: Pointer to the root node of the tree
 * to measure the balance factor.
 * @min: Min integer.
 * @max: Max integer.
 *
 * Return: 1 if balanced and 0 else.
 */
int is_avl(const binary_tree_t *tree, int min, int max)
{
	int bf;

	if (!tree)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);

	bf = is_balance(tree);
	if (bf > 1 || bf < -1)
		return (0);
	return (is_avl(tree->left, min, tree->n) &&
			is_avl(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree
 * is a valid AVL Tree.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_avl(tree, INT_MIN, INT_MAX));
}
