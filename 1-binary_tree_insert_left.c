/* inserts a node as a left child to parent */
#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a left child
 * @parent: parent node
 * @value: value to be stored in left child
 *
 * NOTE: It also creates the node implicitly
 *
 * Return: pointer to created node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);
	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);
	new->n = value;
	new->parent = parent;
	new->right = NULL;

	if (parent->left == NULL)
	{
		parent->left = new;
		new->left = NULL;
	}
	else
	{
		new->left = parent->left;
		parent->left = new;
	}

	return (new);
}
