#include "binary_trees.h"

/**
 * preorder - transverses a Btree in pre-order
 * @tree: root of tree/subtree
 * @func: function to apply to every node
 *
 * Description: The pre-order transversal first visits
 * the root node and performs its operation, the it
 * visits all nodes in the left subtree then all nodes
 * in the right subtree
 */
void preorder(const binary_tree_t *tree, size_t *func)
{
	if (tree != NULL)
	{
		/* ACTION ON NODE */
		*func += 1;

		/* TRANSVERSE */
		preorder(tree->left, func);
		preorder(tree->right, func);
	}
}


/**
 * binary_tree_size - gets the size of a Bt
 * @tree: root of tree/subtree
 *
 * NOTE: the size of a Bt is the number of
 * nodes the tree contains, including the root
 *
 * Return: the size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t cize = 0;

	if (!tree)
		return (0);

	preorder(tree, &cize);

	return (cize);
}
