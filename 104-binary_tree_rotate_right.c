#include "binary_trees.h"



/**
 * binary_tree_rotate_right - Function to perform right-rotate on a tree
 * @tree: Tree to be rotated.
 * Return: Pointer to new root node of rotated tree.
 * Description: When a tree(node) is right-rotated, it becomes the
 * right child of its left child and then bears the right child
 * of that left child as its left child.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp = tree ? tree->left : NULL;

	if (tree == NULL || !tmp)
		return (tree);

	tree->left = tmp->right;
	if (tmp->right)
		tmp->right->parent = tree;

	tmp->right = tree;

	tmp->parent = tree->parent;
	tree->parent = tmp;
	return (tmp);
}
