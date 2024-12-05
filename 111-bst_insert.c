#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree (BST).
 * @tree: Double pointer to the root node of the BST to insert the value.
 * @value: Value to store in the node to be inserted.
 * Return: Pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *current, *new_node;

    if (tree == NULL)
        return NULL;

    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return *tree;
    }

    current = *tree;

    while (current)
    {
        if (value < current->n)
        {
            if (current->left == NULL)
            {
                new_node = binary_tree_node(current, value);
                current->left = new_node;
                return new_node;
            }
            current = current->left;
        }
        else if (value > current->n)
        {
            if (current->right == NULL)
            {
                new_node = binary_tree_node(current, value);
                current->right = new_node;
                return new_node;
            }
            current = current->right;
        }
        else
        {
            return NULL;  // Value already exists in the tree.
        }
    }

    return NULL;
}
