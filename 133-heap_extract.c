#include "binary_trees.h"
#include <stdlib.h>

/**
 * swap_nodes - Swaps the values of two nodes.
 * @a: First node.
 * @b: Second node.
 */
void swap_nodes(heap_t *a, heap_t *b)
{
    int temp = a->n;
    a->n = b->n;
    b->n = temp;
}

/**
 * heapify_down - Ensures the Max Heap property after extraction.
 * @node: Pointer to the node to start heapifying from.
 */
void heapify_down(heap_t *node)
{
    heap_t *largest = node;

    if (node->left && node->left->n > largest->n)
        largest = node->left;

    if (node->right && node->right->n > largest->n)
        largest = node->right;

    if (largest != node)
    {
        swap_nodes(node, largest);
        heapify_down(largest);
    }
}

/**
 * get_last_node - Finds the last node in level-order traversal.
 * @root: Pointer to the root of the tree.
 * Return: Pointer to the last node.
 */
heap_t *get_last_node(heap_t *root)
{
    size_t level = 0, i;
    heap_t **queue;
    heap_t *node = NULL;

    for (node = root; node; node = node->left)
        level++;

    queue = malloc(sizeof(heap_t *) * (1 << level));
    if (!queue)
        return (NULL);

    queue[0] = root;
    for (i = 0; i < (1 << level); i++)
    {
        if (queue[i])
        {
            if (queue[i]->left)
                queue[2 * i + 1] = queue[i]->left;
            if (queue[i]->right)
                queue[2 * i + 2] = queue[i]->right;
        }
    }

    node = queue[i - 1];
    free(queue);
    return (node);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * Return: Value of the root node, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
    heap_t *last;
    int value;

    if (!root || !*root)
        return (0);

    value = (*root)->n;
    last = get_last_node(*root);

    if (last == *root)
    {
        free(*root);
        *root = NULL;
        return (value);
    }

    (*root)->n = last->n;
    if (last->parent->left == last)
        last->parent->left = NULL;
    else
        last->parent->right = NULL;

    free(last);
    heapify_down(*root);

    return (value);
}
