/* Transverses a tree in pre order */

#include "binary_trees.h"

/**
 * binary_tree_preorder - transverses a Btree in pre-order
 * @tree: root of tree/subtree
 * @func: function to apply to every node
 *
 * Description: The pre-order transversal first visits
 * the root node and performs its operation, the it
 * visits all nodes in the left subtree then all nodes
 * in the right subtree
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		/* ACTION ON NODE */
		func(tree->n);

		/* TRANSVERSE */
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}

