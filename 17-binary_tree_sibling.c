#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node.
 * @node: Pointer to the node to find the sibling.
 * Return: Pointer to the sibling node. If node or parent is NULL, or no sibling, return NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL)
        return NULL;

    binary_tree_t *parent = node->parent;

    // Check which child is the current node and return the other child
    if (parent->left == node)
        return parent->right;
    else
        return parent->left;
}
