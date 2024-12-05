#include "binary_trees.h"

/**
 * Helper function to measure the height of a tree for balance calculation.
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
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the balance factor.
 * Return: Balance factor of the tree. If tree is NULL, return 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    int left_height = tree_height(tree->left);
    int right_height = tree_height(tree->right);

    return left_height - right_height;
}
