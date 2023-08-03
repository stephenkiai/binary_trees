#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, otherwise 0. If tree is NULL, return 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

/* If both left & right children = NULL,it's a leaf node (full node) */
if (tree->left == NULL && tree->right == NULL)
return (1);

/* If both left and right children != NULL,recursively-check-subtrees */
if (tree->left != NULL && tree->right != NULL)
return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

/* If 1 child is NULL & the other is not, tree is not full */
return (0);
}
