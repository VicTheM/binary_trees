#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_insert_left(root->left, 14);
    binary_tree_insert_left(root->left->left, 18);
    binary_tree_insert_right(root->left->left, 28);
    binary_tree_insert_right(root->left->right, 888);
    binary_tree_insert_left(root->left->right, 83);
    binary_tree_insert_left(root->right, 99);
    binary_tree_insert_right(root->right->right, 1000);

    binary_tree_print(root);
    binary_tree_delete(root);
    return (0);
}
