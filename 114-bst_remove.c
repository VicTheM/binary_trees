#include "binary_trees.h"


/**
 * find_node_et_successor - Function to find a node and its in-order successor
 * @tree: Tree (current node) to be checked.
 * @prev: Prev node in an in-order traversal.
 * @value: Value to be removed from tree
 * @arr: Array to hold node and its in-order successor respectively.
 *
 * Description: Here node is stored as 1st elem of arr
 * while its in-order successor is stored as second element.
 * As function is recursively called, the `prev` variable is updated to
 * hold the current node.
 */

void find_node_et_successor(bst_t *tree, bst_t **prev, bst_t **arr, int value)
{
	if (!tree)
		return;

	find_node_et_successor(tree->left, prev, arr, value);

	if (!arr[0] && tree->n == value)
		arr[0] = (bst_t *)tree;
	else if (!arr[1] && *prev && (*prev)->n == value)
	{
		arr[1] = tree;
		return;
	}

	*prev = (bst_t *)tree;
	find_node_et_successor(tree->right, prev, arr, value);
}

/**
 * align_nodes - This function simply aligns the nodes before deletion.
 * @node_del: Pointer to node that will be removed from tree
 * @node_add: Pointer to node that will substitute for deleted node.
 * This may be a NULL pointer.
 */

void align_nodes(bst_t *node_del, bst_t *node_add)
{
	bst_t *node_add_p = NULL, *node_del_p = NULL;

	node_del_p = node_del->parent;
	if (node_add)
	{
		node_add_p = node_add->parent;
		if (node_add_p)
		{
			if (node_add_p->right == node_add)
				node_add_p->right = NULL;
			else
				node_add_p->left = NULL;
		}
		node_add->parent = node_del_p;
		if (!node_add->left)
			node_add->left = node_del->left;
		if (!node_add->right)
			node_add->right = node_del->right;

		if (node_del->left)
			node_del->left->parent = node_add;
		if (node_del->right)
			node_del->right->parent = node_add;
	}

	if (node_del_p)
	{
		if (node_del_p->right == node_del)
			node_del_p->right = node_add;
		else
			node_del_p->left = node_add;
	}
}

/**
 * bst_remove - Function to remove node from a BST.
 * @root: Pointer to root node of tree for where node will be removedd.
 * @value: Value to be removed from tree
 * Return: Pointer to new node after removing desired value
 *
 * Description: Replace node with in-order successor if it has two children
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node_del = NULL, *node_add = NULL,
	      *arr[2] = {NULL, NULL}, *prev[1] = {NULL};

	if (!root)
		return (NULL);

	find_node_et_successor(root, prev, arr, value);
	node_del = arr[0];

	if (!node_del)
		return (root);

	if ((node_del->left && !node_del->right) ||
			(node_del->right && !node_del->left))
		node_add = node_del->right ? node_del->right : node_del->left;
	else if (node_del->left && node_del->right)
		node_add = arr[1];

	align_nodes(node_del, node_add);
	free(node_del);

	if (node_del == root && !node_add)
		root = NULL;
	else
		root = node_add && node_add->parent == NULL ? node_add : root;
	return (root);
}
