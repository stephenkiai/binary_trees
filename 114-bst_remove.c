#include "binary_trees.h"

bst_t *bst_find_min(bst_t *root);
bst_t *bst_remove_node(bst_t *root, int value);

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST)
 *
 * @root: Pointer to the root node of the tree where you will remove a node
 * @value: The value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree after removing the
 *                                     desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	return (bst_remove_node(root, value));
}

/**
 * bst_find_min - Finds the minimum value node in a BST
 *
 * @root: Pointer to the root node of the BST
 *
 * Return: Pointer to the node with the minimum value
 */
bst_t *bst_find_min(bst_t *root)
{
	if (root == NULL)
		return (NULL);

	while (root->left)
		root = root->left;

	return (root);
}

/**
 * bst_remove_node - Removes a node from a Binary Search Tree (BST)
 *
 * @root: Pointer to the root node of the tree where you will remove a node
 * @value: The value to remove in the tree
 *
 * Return: Pointer to new root node of the tree after removing the
 *                                   desired value
 */
bst_t *bst_remove_node(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
	{
		root->left = bst_remove_node(root->left, value);
	}
	else if (value > root->n)
	{
		root->right = bst_remove_node(root->right, value);
	}
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			return (NULL);
		}
		else if (root->left == NULL || root->right == NULL)
		{
			bst_t *temp = root->left ? root->left : root->right;

			free(root);
			return (temp);
		}
		else
		{
			bst_t *in_order_successor = bst_find_min(root->right);

			root->n = in_order_successor->n;
			root->right = bst_remove_node(root->right,
						      in_order_successor->n);
		}
	}

	return (root);
}
