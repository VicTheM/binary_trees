#include "binary_trees.h"
/* FINDS THE UNCLE OF A NODE */


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


/**
 * binary_tree_uncle - retrieves the uncle of a node
 * @node: the node in question
 *
 * Description: An uncle is a parent sibling
 * Return: Uncle pointer or NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	return (binary_tree_sibling(node->parent));
}
