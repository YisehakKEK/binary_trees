#include "binary_trees.h"

/**
 * balance_avl - Balances an AVL tree after insertion.
 * @tree: Pointer to the root node of the AVL tree.
 * Return: Pointer to the balanced tree.
 */
avl_t *balance_avl(avl_t *tree)
{
    int balance;

    balance = binary_tree_balance(tree);

    if (balance > 1) /* Left-heavy */
    {
        if (binary_tree_balance(tree->left) < 0)
            tree->left = binary_tree_rotate_left(tree->left);
        return binary_tree_rotate_right(tree);
    }
    if (balance < -1) /* Right-heavy */
    {
        if (binary_tree_balance(tree->right) > 0)
            tree->right = binary_tree_rotate_right(tree->right);
        return binary_tree_rotate_left(tree);
    }
    return tree;
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: Double pointer to the root node of the AVL tree.
 * @value: Value to insert.
 * Return: Pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *new_node;

    if (tree == NULL)
        return NULL;

    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return *tree;
    }

    if (value < (*tree)->n)
    {
        new_node = avl_insert(&((*tree)->left), value);
        if (new_node != NULL)
            (*tree)->left->parent = *tree;
    }
    else if (value > (*tree)->n)
    {
        new_node = avl_insert(&((*tree)->right), value);
        if (new_node != NULL)
            (*tree)->right->parent = *tree;
    }
    else
        return NULL;

    *tree = balance_avl(*tree);
    return new_node;
}
