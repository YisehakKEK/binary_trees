#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_delete - Deletes an entire binary tree.
 * @tree: Pointer to the root node of the tree to delete.
 */
void binary_tree_delete(binary_tree_t *tree)
{
    if (!tree)
        return;

    binary_tree_delete(tree->left);  // Recursively delete left subtree
    binary_tree_delete(tree->right); // Recursively delete right subtree
    free(tree);                      // Free the root node
}
