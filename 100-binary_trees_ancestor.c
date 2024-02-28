#include "binary_trees.h"


/**
 * binary_trees_ancestor - gets the closest single grandparent
 * of two nodes
 *
 * @first: The first node
 * @second: The second node
 *
 * Return: The single parent the parents both nodes, otherwise NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	int found, c = 0;
	const binary_tree_t *tmp = second;
	const binary_tree_t *ptm = first;
	const binary_tree_t *parent;

	if (!first || !second)
		return (NULL);

	for ( ; c < 2; c++)
	{
		if (c == 1)
		{
			first = second;
			second = ptm;
		}
		while (first)
		{
			while (second->parent)
			{
				if (second->parent == first)
				{
					parent = first;
					found = 1;
					break;
				}
				second = second->parent;
			}
			if (found == 1)
				break;
			first = first->parent;
			second = tmp;
		}

		if (found == 1)
			return ((binary_tree_t *)parent);
	}

	return (NULL);
}
