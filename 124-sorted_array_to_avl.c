#include "binary_trees.h"

/* CREATES A BALANCED BST (AVL) FROM A SORTED ARRAY */


/**
 * sorted_array_to_avl_rec - creates AVL without rotation from arr
 * @array: A sorted array
 * @start: start index
 * @stop: stop index
 * @parent: parent of new node
 *
 * Return: Pointer to root
 */
avl_t *sorted_array_to_avl_rec(int *array, size_t start, size_t stop, avl_t *parent)
{
	int mid;
	avl_t *root = malloc(sizeof(avl_t));

	if (!root)
		return (NULL);
	if (start > stop)
		return (NULL);

	root->parent = parent;

	mid = (start + stop) / 2;
	root->n = array[mid];
	printf("%d\n", root->n);

	root->left = sorted_array_to_avl_rec(array, start, mid - 1, root);
	root->right = sorted_array_to_avl_rec(array, mid + 1, stop, root);

	return (root);
}



/**
 * sorted_array_to_avl - creates AVL without rotation from arr
 * @array: A sorted array
 * @size: size of array
 *
 * Return: Pointer to root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	size_t start, stop;

	if (size < 1)
		return (NULL);

	start = 0;
	stop = size - 1;

	return (sorted_array_to_avl_rec(array, start, stop, NULL));
}
