#include "binary_trees.h"

/**
 * preorder - transverses a Btree in pre-order
 * @tree: root of tree/subtree
 *
 * Description: The pre-order transversal first visits
 * the root node and performs its operation, the it
 * visits all nodes in the left subtree then all nodes
 * in the right subtree
 */
int preorder(const binary_tree_t *tree)
{
	int l = 0;
	int r = 0;

	if (tree)
	{
		l++;
		r++;
		l += tree->left ? preorder(tree->left) : 0;
		r += tree->right ? preorder(tree->right) : 0;
		return (l > r ? l : r);
	}
	return (0);
}


/**
 * binary_tree_balance - Measures the Balance Factor of a Bt
 * @tree: root of tree/subtree
 *
 * NOTE: Balance Factor is the difference in the height
 * of left subtree to the height of the right subtree
 *
 * Return: the balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int bf = 0;
	int l_height;
	int r_height;

	if (!tree)
		return (0);

	l_height = preorder(tree->left);
	r_height = preorder(tree->right);

	bf = l_height - r_height;

	return (bf);
}
