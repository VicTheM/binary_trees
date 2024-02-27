#include "binary_trees.h"

/**
 * binary_tree_height - gets the heigt of a Bt
 * @tree: root of tree/subtree
 *
 * DESCRIPTION: the height is the number of
 * generations of children that node has
 *
 * Return: The height as size_t
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_height, r_height;

	if (!tree)
		return (0);

	l_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	r_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (l_height > r_height ? l_height : r_height);
}
