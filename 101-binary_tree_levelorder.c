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

	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 10000);

	if (queue == NULL)
		return;

	int front = 0, rear = 0;

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		binary_tree_t *current_node = queue[front++];

		func(current_node->n);

		if (current_node->left)
			queue[rear++] = current_node->left;

		if (current_node->right)
			queue[rear++] = current_node->right;
	}

	free(queue);
}
