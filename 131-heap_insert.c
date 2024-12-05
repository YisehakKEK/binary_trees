#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 * Return: Height of the tree, 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (!tree)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the size.
 * Return: Size of the tree, 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);
    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * find_insertion - Finds the next insertion position for a node.
 * @tree: Pointer to the root of the tree.
 * @size: Current size of the tree.
 * Return: Pointer to the parent node for the new node.
 */
heap_t *find_insertion(heap_t *tree, size_t size)
{
    if (!tree || size == 1)
        return (tree);

    size_t left_size = (size - 1) / 2;

    if (size % 2 == 0)
        return (find_insertion(tree->left, left_size));
    else
        return (find_insertion(tree->right, left_size));
}

/**
 * bubble_up - Ensures Max-Heap property by swapping nodes upwards.
 * @node: Pointer to the node to bubble up.
 */
void bubble_up(heap_t *node)
{
    int temp;

    while (node->parent && node->n > node->parent->n)
    {
        temp = node->n;
        node->n = node->parent->n;
        node->parent->n = temp;
        node = node->parent;
    }
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the Heap.
 * @value: Value to store in the node to be inserted.
 * Return: Pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *node, *parent;
    size_t size;

    if (!root)
        return (NULL);

    if (!*root)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    size = binary_tree_size(*root) + 1;
    parent = find_insertion(*root, size);

    node = binary_tree_node(parent, value);
    if (!node)
        return (NULL);

    if (!parent->left)
        parent->left = node;
    else
        parent->right = node;

    bubble_up(node);

    return (node);
}
