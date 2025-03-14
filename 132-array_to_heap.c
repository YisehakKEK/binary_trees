#include "binary_trees.h"
#include <stddef.h>

/**
 * array_to_heap - Builds a Max Binary Heap from an array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: The number of elements in the array.
 * Return: Pointer to the root node of the created Binary Heap, or NULL on failure.
 */
heap_t *array_to_heap(int *array, size_t size)
{
    heap_t *root = NULL;
    size_t i;

    if (!array || size == 0)
        return (NULL);

    for (i = 0; i < size; i++)
    {
        if (!heap_insert(&root, array[i]))
        {
            /* Free the tree if insertion fails */
            binary_tree_delete(root);
            return (NULL);
        }
    }

    return (root);
}
