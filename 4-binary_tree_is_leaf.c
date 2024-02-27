/* checks if a node does not have any child */
#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is leaf
 * @node: the node in question
 *
 * NOTE: A leaf node is a node that has no child
 *
 * Return: 1 True, 0 False
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	int ret;

	if (node == NULL)
	{
		ret = 0;
		return (ret);
	}

	if (node->left == NULL && node->right == NULL)
		ret = 1;
	else
		ret = 0;

	return (ret);
}
