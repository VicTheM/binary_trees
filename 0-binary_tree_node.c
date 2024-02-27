/* Creates a binary tree node */
#include "binary_trees.h"

/**
 * binary_tree_node - creates a node of a Bt
 * @parent: pointer to the parent node
 * @value: value to be stored in the node
 *
 * Return: pointer to the newly created node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return NULL;

	new->left = NULL;
	new->right = NULL;
	new->parent = parent;
	new->n = value;

	return (new);
}
