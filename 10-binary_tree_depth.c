#include "binary_trees.h"

/**
 * binary_tree_depth - gets the depth of a node
 * @tree: node to evaluate its depth
 *
 * NOTE: The depth is how far the node is from root
 *
 * Return: The number of generations of grandparents
 * the node has
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	const binary_tree_t *tmp;

	if (!tree)
		return (0);

	tmp = tree;
	while (tmp->parent != NULL)
	{
		depth += 1;
		tmp = tmp->parent;
	}

	return (depth);
}
