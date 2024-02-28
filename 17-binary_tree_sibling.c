#include "binary_trees.h"
/* FINDS THE SIBLING OF A NODE */


/**
 * binary_tree_sibling - returns the sibling (mirror) of a node
 * @node: node to return its mirror
 *
 * Return: pointer to the sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !(node->parent) ||
			!(node->parent->left) || !(node->parent->right))
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);

	return (node->parent->left);
}
