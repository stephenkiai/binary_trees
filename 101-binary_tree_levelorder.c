#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes throug binary tree using level-order traversal
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_t *current;
	int has_more_nodes = 1;

	while (has_more_nodes)
	{
		has_more_nodes = 0;
		current = (binary_tree_t *)tree;

		while (current)
		{
			func(current->n);

			if (current->left)
				has_more_nodes = 1;
			if (current->right)
				has_more_nodes = 1;

			current = current->left;
		}

		current = (binary_tree_t *)tree;

		while (current)
		{
			func(current->n);
			current = current->right;
		}
	}
}
