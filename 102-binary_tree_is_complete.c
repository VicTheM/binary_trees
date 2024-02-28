#include "binary_trees.h"

/**
 * count_nodes - Counts the number of nodes in a binary tree.
 *
 * @tree: Pointer to the root node of the tree to count.
 *
 * Return: The number of number of nodes.
 */
size_t count_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_complete - recursive function to check if a binary tree is complete.
 *
 * @tree: Pointer to the root node of the tree to check.
 * @index: Index of the node.
 * @node_count: Number of nodes in a binary tree.
 *
 * Return: 1 if tree is complete and 0 otherwise.
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t node_count)
{
	if (!tree)
		return (1);
	if (index >= node_count)
		return (0);
	return (is_complete(tree->left, 2 * index + 1, node_count) &&
			is_complete(tree->right, 2 * index + 2, node_count));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is complete, otherwise 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_complete(tree, 0, count_nodes(tree)));
}
