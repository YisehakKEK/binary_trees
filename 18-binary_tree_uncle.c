#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node.
 * @node: Pointer to the node to find the uncle.
 * Return: Pointer to the uncle node, or NULL if node or uncle does not exist.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
        return NULL;

    binary_tree_t *parent = node->parent;
    binary_tree_t *grandparent = parent->parent;

    // Check which child the parent is and return the opposite child
    if (grandparent->left == parent)
        return grandparent->right;
    else
        return grandparent->left;
}
