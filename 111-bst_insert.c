#include "binary_trees.h"

/**
 * bst_insert_h - Helper Function to insert node into a BST.
 * @tree: Pointer to root node of tree for insertion.
 * @node: Double pointer to node to be inserted in tree.
 * @inserted: Flag to check if node is inserted
 */
void bst_insert_h(bst_t *tree, bst_t **node, int *inserted)
{
	if (!tree)
		return;

	if ((*node)->n > tree->n && !*inserted)
	{
		bst_insert_h(tree->right, node, inserted);
		if (*inserted)
			return;
		tree->right = *node;
		(*node)->parent = tree;
		*inserted = 1;
	}

	else if ((*node)->n < tree->n && !*inserted)
	{
		bst_insert_h(tree->left, node, inserted);
		if (*inserted)
			return;
		tree->left = *node;
		(*node)->parent = tree;
		*inserted = 1;
	}
	else
	{
		*inserted = 1;
		free(*node);
		*node = NULL;
	}
}

/**
 * bst_insert - Function to insert node into a BST.
 * @tree: Double pointer to root node of tree for insertion.
 * @value: Value to be inserted in tree
 * Return: Pointer to created node or NULL on failure.
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node = NULL;
	int inserted = 0;

	if (!tree)
		return (NULL);

	node = binary_tree_node(NULL, value);
	if (!node)
		return (NULL);

	if (!(*tree))
		*tree = node;
	else
		bst_insert_h(*tree, &node, &inserted);

	return (node);
}
