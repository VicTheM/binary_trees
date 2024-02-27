/* checks if a node is the start of a tree */
#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a node is root
 * @node: the node in question
 *
 * Return: 1 True, 0 False
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	int ret;

	if (node == NULL)
	{
		ret = 0;
		return (ret);
	}

	if (node->parent == NULL)
		ret = 1;
	else
		ret = 0;

	return (ret);
}
