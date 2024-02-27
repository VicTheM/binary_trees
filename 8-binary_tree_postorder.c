#include "binary_trees.h"

/**
 * binary_tree_postorder - transverses a Btree in post order
 * @tree: root of tree
 *
 * Description: The postorder transversal means
 * All nodes in the left subtree will be visited
 * Then all nodes in the right subtree
 * Then the root node of current subtree
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);

		/* Action on the current node */
		func(tree->n);
	}
}

