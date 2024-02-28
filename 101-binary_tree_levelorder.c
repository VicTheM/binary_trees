#include "binary_trees.h"
/**
 * pre_order - transverses a Btree in pre-order
 * @tree: root of tree/subtree
 * @i: index of root in array
 * @arr: array containing linearized tree values
 *
 * Description: The pre-order transversal first visits
 * the root node and performs its operation, the it
 * visits all nodes in the left subtree then all nodes
 * in the right subtree
 */
void pre_order(const binary_tree_t *tree, int i, int *arr)
{
	if (tree != NULL)
	{
		/* ACTION ON NODE */
		arr[i] = tree->n;

		/* TRANSVERSE */
		pre_order(tree->left, 2 * i + 1, arr);
		pre_order(tree->right, 2 * i + 2, arr);
	}
}

/* TRANSVERSES A TREE IN LEVEL - ORDER */

/**
 * binary_tree_levelorder - a transversal method
 * @tree: root/sub root
 * @func: action to perform on each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int *val, cize, i = 0;

	if (!tree || func == NULL)
		return;

	cize = binary_tree_size(tree);
	val = malloc(sizeof(int) * cize);
	pre_order(tree, 0, val);

	for ( ; i < cize; i++)
		func(val[i]);

	free(val);
}


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
