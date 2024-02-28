#include "binary_trees.h"

/**
 * avl_recursive_insert - Recursive function to nserts
 * a value in an AVL Tree.
 *
 * @tree: Double pointer to the root node of the AVL
 *		tree for inserting the value.
 * @value: Value to store in the node to be inserted.
 * @parent: Pointer to the parent node.
 * @new: Double pointer to the new node.
 * Return: AVL tree, or NULL on failure.
 */
avl_t *avl_recursive_insert(avl_t **tree, avl_t *parent, avl_t **new,
		int value)
{
	int balance;

	if (!*tree)
	{
		*new = binary_tree_node(parent, value);
		return (*new);
	}

	if (value < (*tree)->n)
	{
		(*tree)->left = avl_recursive_insert(&((*tree)->left), *tree, new, value);
		if (!(*tree)->left)
			return (NULL);
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = avl_recursive_insert(&((*tree)->right), *tree, new, value);
		if (!(*tree)->right)
			return (NULL);
	}
	else
		return (*tree);

	balance = binary_tree_balance((*tree));
	if (balance > 1 && value < (*tree)->left->n)
		*tree = binary_tree_rotate_right(*tree);
	if (balance < -1 && value > (*tree)->right->n)
		*tree = binary_tree_rotate_left(*tree);

	if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree =  binary_tree_rotate_right(*tree);
	}
	if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}

/**
 * avl_insert - Inserts a value in an AVL Tree.
 *
 * @tree:double pointer to the root node of the AVL
 *		tree for inserting the value.
 * @value: Value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (!tree)
		return (NULL);

	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_recursive_insert(tree, *tree, &new, value);
	return (new);
}
