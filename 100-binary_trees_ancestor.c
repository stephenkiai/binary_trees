#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 *
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
if (first == NULL || second == NULL)
return (NULL);

/*If either of the nodes == the root, then root is lowest common ancestor*/
if (first == second || first->parent == second || second->parent == first)
return ((binary_tree_t *)first);

/*If first node=parent of second node, first node=lowest common ancestor*/
if (first == second->parent)
return ((binary_tree_t *)first);

/*If second node=parent of first node,second node=lowest common ancestor*/
if (second == first->parent)
return ((binary_tree_t *)second);

/*Recursively check for common ancestors in the parents of both nodes*/
return (binary_trees_ancestor(first->parent, second->parent));
}
