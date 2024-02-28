#include "binary_trees.h"

/**
 * array_to_bst - Function that builds a Binary Search Tree from an array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: Number of elements in the array.
 * Return: Pointer to root node of created BST or NULL on failure.
 */

bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 0;
	bst_t *root = NULL;

	if (!array)
		return (NULL);

	root = bst_insert(&root, array[i++]);
	while (i < size)
		bst_insert(&root, array[i++]);
	return (root);
}
