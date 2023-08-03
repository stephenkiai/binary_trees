#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 *
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *new_root_leftchild, *parent;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	parent = tree;
	new_root = tree->right;
	new_root_leftchild = new_root->left;

	parent->right = new_root_leftchild;
	if (new_root_leftchild != NULL)
		new_root_leftchild->parent = parent;

	new_root->left = parent;
	new_root->parent = parent->parent;
	parent->parent = new_root;

	return (new_root);
}
