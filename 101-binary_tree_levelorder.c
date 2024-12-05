#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 * Return: Height of the tree or 0 if tree is NULL.
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
 * process_level - Processes nodes at a specific level.
 * @tree: Pointer to the root node.
 * @func: Pointer to the function to call for each node.
 * @level: Level to process.
 */
void process_level(const binary_tree_t *tree, void (*func)(int), size_t level)
{
    if (tree == NULL)
        return;

    if (level == 0)
        func(tree->n);
    else
    {
        process_level(tree->left, func, level - 1);
        process_level(tree->right, func, level - 1);
    }
}

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to the function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    size_t height = tree_height(tree);
    for (size_t level = 0; level < height; level++)
        process_level(tree, func, level);
}
