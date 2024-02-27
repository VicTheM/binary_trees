/* deletes an entire tree/subtree when given the root */
#include "binary_trees.h"

/**
 * postorder - transverses a Btree in post order
 * @root: root of tree
 *
 * Description: The postorder transversal means
 * All nodes in the left subtree will be visited
 * Then all nodes in the right subtree
 * Then the root node of current subtree
 */
void postorder(binary_tree_t *root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);

		/* Action on the current node */
		free(root);
	}
}

/**
 * binary_tree_delete - deletes a Bt from @tree
 * @tree: a node supposed to be root node
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	/* using post_order_transversal */
	postorder(tree);
}
