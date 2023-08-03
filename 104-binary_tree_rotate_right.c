#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 *
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *new_root_rightchild, *parent;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	parent = tree;
	new_root = tree->left;
	new_root_rightchild = new_root->right;

	parent->left = new_root_rightchild;
	if (new_root_rightchild != NULL)
		new_root_rightchild->parent = parent;

	new_root->right = parent;
	new_root->parent = parent->parent;
	parent->parent = new_root;

	return (new_root);
}
