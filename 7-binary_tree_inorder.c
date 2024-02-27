#include "binary_trees.h"

/**
 * binary_tree_inorder - transverses a Btree in-order
 * @tree: root of tree/subtree
 * @func: function to apply to every node
 *
 * Description: The in-order goes like this
 * Visit all node in the left subtree
 * visit root node
 * visit all node in the right subtree
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		binary_tree_inorder(tree->left, func);

		/* ACTION */
		func(tree->n);

		binary_tree_inorder(tree->right, func);
	}
}

