#include "binary_trees.h"
/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Check if the tree is complete using a level-order traversal */
	int current_level = 0;
	int prev_level = -1;

	return (is_complete_recursive(tree, 0, &current_level, &prev_level));
}

/**
 * is_complete_recursive - Recursive helper function checks if tree is complete
 *
 * @tree: Pointer to the current node in the traversal
 * @index: The index of the current node in the complete binary tree
 * @current_level: Pointer to the current level in the traversal
 * @prev_level: Pointer to the previous level in the traversal
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete_recursive(const binary_tree_t *tree, int index, int
			  *current_level, int *prev_level)
{
	if (tree == NULL)
		return (1);

	/* Check if tree violates the conditions of a complete binary tree */
	if (index >= (1 << (*current_level)))
		return (0);

	/* Update the current and previous levels */
	if (*current_level > *prev_level)
	{
		*prev_level = *current_level;
		(*current_level)++;
	}

	/* Recur for the left and right subtrees */
	return (is_complete_recursive(tree->left, 2 * index + 1, current_level,
				      prev_level) && is_complete_recursive
		(tree->right, 2 * index + 2, current_level, prev_level));
}
