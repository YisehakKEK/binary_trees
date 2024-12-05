#include "binary_trees.h"

/**
 * find_minimum - Finds the smallest node in a subtree.
 * @node: Pointer to the root of the subtree.
 * Return: Pointer to the node with the smallest value.
 */
bst_t *find_minimum(bst_t *node)
{
    while (node && node->left != NULL)
        node = node->left;
    return node;
}

/**
 * bst_remove - Removes a node with a specific value from a BST.
 * @root: Pointer to the root node of the tree.
 * @value: Value to remove from the tree.
 * Return: Pointer to the new root of the tree after deletion.
 */
bst_t *bst_remove(bst_t *root, int value)
{
    bst_t *temp;

    if (root == NULL)
        return NULL;

    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            if (temp)
                temp->parent = root->parent;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            if (temp)
                temp->parent = root->parent;
            free(root);
            return temp;
        }

        temp = find_minimum(root->right);
        root->n = temp->n;
        root->right = bst_remove(root->right, temp->n);
    }

    return root;
}
