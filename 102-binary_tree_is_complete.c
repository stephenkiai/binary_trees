#include "binary_trees.h"
/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, otherwise 0. If tree is NULL, return 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 10000);

	if (queue == NULL)
		return (0);

	int front = 0, rear = 0;
	int is_last_level = 0;

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		binary_tree_t *current_node = queue[front++];

		if (current_node == NULL)
			is_last_level = 1;
		else
		{
			if (is_last_level)
			{
				free(queue);
				return (0);
			}

			queue[rear++] = current_node->left;
			queue[rear++] = current_node->right;
		}
	}

	free(queue);
	return (1);
}
