#include "binary_trees.h"

/**
 * Helper function to measure the height of a tree.
 */
size_t tree_height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    size_t left_height = tree_height(tree->left);
    size_t right_height = tree_height(tree->right);

    return (left_height > right_height ? left_height + 1 : right_height + 1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if the tree is perfect, 0 otherwise or if tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    size_t left_height = tree_height(tree->left);
    size_t right_height = tree_height(tree->right);

    // Check if heights are the same and recursively check if subtrees are perfect.
    if (left_height == right_height) {
        return binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right);
    }

    return 0;
}
