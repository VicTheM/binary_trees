#include "binary_trees.h"

/**
 * inorder_bst_check - Function to check if a tree is a BST using
 * the property that binary trees are sorted when travered in-order.
 * @tree: Tree(current node) to be checked.
 * @prev: Prev node in an in-order traversal.
 * @isValid: Pointer to int flag that indicates if tree is valid BST.
 *
 * Description: Once a node is visited, it becomes stored as the prev.
 * prev will only be NULL for first node in in-order traversal
 */

void inorder_bst_check(const binary_tree_t *tree,
		binary_tree_t **prev, int *isValid)
{
	if (!tree)
		return;

	inorder_bst_check(tree->left, prev, isValid);
	if (*prev && (*prev)->n >= tree->n)
	{
		*isValid = 0;
		return;
	}

	*prev = (binary_tree_t *)tree;
	inorder_bst_check(tree->right, prev, isValid);
}

/**
 * binary_tree_is_bst - Function to check if tree is valid BST.
 * @tree: Tree to be traversed.
 * Return: 1 if tree is valid BST else 0.
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int isValidFlag = 1;
	binary_tree_t *prev[] = {NULL};

	if (!tree)
		return (0);

	inorder_bst_check(tree, prev, &isValidFlag);
	return (isValidFlag);
}
