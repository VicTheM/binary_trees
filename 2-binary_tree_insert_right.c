/* inserts a node as a right child to parent */
#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a right child
 * @parent: parent node
 * @value: value to be stored in right child
 *
 * NOTE: It also creates the node implicitly
 * and the shifted node retains its children
 *
 * Return: pointer to created node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);
	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);
	new->n = value;
	new->parent = parent;
	new->left = NULL;

	if (parent->right == NULL)
	{
		parent->right = new;
		new->right = NULL;
	}
	else
	{
		new->right = parent->right;
		parent->right = new;
	}

	return (new);
}
