#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree.
 * @tree: Pointer to the root node of the tree to rotate.
 * Return: Pointer to the new root node of the tree after rotation, or NULL.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
    binary_tree_t *new_root;

    if (tree == NULL || tree->right == NULL)
        return NULL;

    new_root = tree->right;  // The new root is the right child.
    tree->right = new_root->left;  // Update the old root's right child.

    if (new_root->left != NULL)
        new_root->left->parent = tree;

    new_root->left = tree;  // The old root becomes the left child of the new root.
    new_root->parent = tree->parent;
    tree->parent = new_root;

    return new_root;
}
