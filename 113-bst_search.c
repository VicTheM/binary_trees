#include "binary_trees.h"


/**
 * find_node - Helper function to find a node
 * @tree: Tree (current node) to be checked.
 * @node: Pointer to point to found node.
 * @value: Value to be searched for
 *
 */

void find_node(const bst_t *tree, bst_t **node, int value)
{
	if (!tree)
		return;

	if (tree->n > value)
		find_node(tree->left, node, value);
	else if (tree->n < value)
		find_node(tree->right, node, value);
	else if (tree->n == value)
	{
		*node = (bst_t *)tree;
		return;
	}
}

/**
 * bst_search - Function to search for node in a BST.
 * @tree: Pointer to root node of tree to be searched.
 * @value: Value to be searched for in tree
 * Return: Pointer to new node containing desired value
 *
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node = NULL;

	find_node(tree, &node, value);
	return (node);
}
