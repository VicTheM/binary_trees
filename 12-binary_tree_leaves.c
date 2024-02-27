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
		if (tree->left == NULL && tree->right == NULL)
			*func += 1;

		/* TRANSVERSE */
		preorder(tree->left, func);
		preorder(tree->right, func);
	}
}


/**
 * binary_tree_leaves - gets the number of leaves in a Bt
 * @tree: root of tree/subtree
 *
 * NOTE: a leaf is a node that has no child
 *
 * Return: the total number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t n_leaf = 0;

	if (!tree)
		return (0);

	preorder(tree, &n_leaf);

	return (n_leaf);
}
