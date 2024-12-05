#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if the tree is complete, 0 otherwise or if tree is NULL.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    size_t index = 0, node_count = count_nodes(tree);

    return check_complete(tree, index, node_count);
}

/**
 * count_nodes - Counts the total number of nodes in a binary tree.
 * @tree: Pointer to the root node of the tree.
 * Return: Total number of nodes.
 */
size_t count_nodes(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    return 1 + count_nodes(tree->left) + count_nodes(tree->right);
}

/**
 * check_complete - Recursively checks if a binary tree is complete.
 * @tree: Pointer to the current node.
 * @index: Current node index.
 * @node_count: Total number of nodes in the tree.
 * Return: 1 if complete, 0 otherwise.
 */
int check_complete(const binary_tree_t *tree, size_t index, size_t node_count)
{
    if (tree == NULL)
        return 1;

    if (index >= node_count)
        return 0;

    return check_complete(tree->left, 2 * index + 1, node_count) &&
           check_complete(tree->right, 2 * index + 2, node_count);
}
