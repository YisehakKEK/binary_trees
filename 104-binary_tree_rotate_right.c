#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree.
 * @tree: Pointer to the root node of the tree to rotate.
 * Return: Pointer to the new root node of the tree after rotation, or NULL.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
    binary_tree_t *new_root;

    if (tree == NULL || tree->left == NULL)
        return NULL;

    new_root = tree->left;  // The new root is the left child.
    tree->left = new_root->right;  // Update the old root's left child.

    if (new_root->right != NULL)
        new_root->right->parent = tree;

    new_root->right = tree;  // The old root becomes the right child of the new root.
    new_root->parent = tree->parent;
    tree->parent = new_root;

    return new_root;
}
