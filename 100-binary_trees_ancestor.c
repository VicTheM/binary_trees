#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 *
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: The common ancestor and NULL if not found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *parent1, *parent2;

	parent1 = (binary_tree_t *)first;
	while (parent1)
	{
		parent2 = (binary_tree_t *)second;
		while (parent2)
		{
			if (parent1 == parent2)
				return (parent1);
			parent2 = parent2->parent;
		}
		parent1 = parent1->parent;
	}
	return (NULL);
}
