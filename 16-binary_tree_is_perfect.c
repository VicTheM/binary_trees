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
		/*  used to check for full tree */
		if ((tree->left == NULL && tree->right != NULL) ||
				(tree->left != NULL && tree->right == NULL))
			*func += 1;

		/* TRANSVERSE */
		preorder(tree->left, func);
		preorder(tree->right, func);
	}
}


/**
 * binary_tree_is_full - checks if tree is full
 * @tree: the root node
 *
 * Description: A full tree is one whose nodes are either 0 or 2
 *
 * Return: 0 False 1 it is complete
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	size_t boolean = 0;

	preorder(tree, &boolean);

	if (boolean > 0)
		return (0);
	return (1);
}

/**
 * pre_order - transverses a Btree in pre-order
 * @tree: root of tree/subtree
 *
 * Description: The pre-order transversal first visits
 * the root node and performs its operation, the it
 * visits all nodes in the left subtree then all nodes
 * in the right subtree
 *
 * Return: the height of a sub stree
 */
int pre_order(const binary_tree_t *tree)
{
	int l = 0;
	int r = 0;

	if (tree)
	{
		l++;
		r++;
		l += tree->left ? pre_order(tree->left) : 0;
		r += tree->right ? pre_order(tree->right) : 0;
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

	l_height = pre_order(tree->left);
	r_height = pre_order(tree->right);

	bf = l_height - r_height;

	return (bf);
}

/**
 * binary_tree_is_perfect - checks if a tree is perfect
 * @tree: root of tree
 *
 * Description: A perfect tree must be both balanced and complete
 * Return: 1 True; 0 False
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (binary_tree_balance(tree) != 0 || binary_tree_is_full(tree) == 0)
		return (0);

	return (1);
}
