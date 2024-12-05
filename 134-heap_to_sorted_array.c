#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array.
 * @heap: Pointer to the root of the heap.
 * @size: Pointer to store the size of the array.
 * Return: Pointer to the sorted array, or NULL on failure.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *array;
    size_t i = 0;

    if (!heap || !size)
        return (NULL);

    /* Count the size of the heap */
    *size = 0;
    for (heap_t *temp = heap; temp; (*size)++)
        temp = temp->left ? temp->left : temp->right;

    array = malloc(sizeof(int) * (*size));
    if (!array)
        return (NULL);

    /* Extract elements from heap to build the array */
    while (heap)
        array[i++] = heap_extract(&heap);

    return (array);
}
