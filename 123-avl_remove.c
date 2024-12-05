#include "binary_trees.h"

/**
 * find_minimum - Finds the smallest node in a subtree.
 * @node: Pointer to the root of the subtree.
 * Return: Pointer to the node with the smallest value.
 */
avl_t *find_minimum(avl_t *node)
{
    while (node && node->left)
        node = node->left;
    return node;
}

/**
 * avl_remove - Removes a node with a specific value from an AVL tree.
 * @root: Pointer to the root node of the AVL tree.
 * @value: Value to remove from the tree.
 * Return: Pointer to the new root of the tree after deletion and rebalancing.
 */
avl_t *avl_remove(avl_t *root, int value)
{
    avl_t *temp;

    if (!root)
        return NULL;

    if (value < root->n) /* Go left */
        root->left = avl_remove(root->left, value);
    else if (value > root->n) /* Go right */
        root->right = avl_remove(root->right, value);
    else /* Found the node to remove */
    {
        if (!root->left || !root->right) /* One child or no child */
        {
            temp = root->left ? root->left : root->right;
            if (temp)
                temp->parent = root->parent;
            free(root);
            return temp;
        }
        else /* Two children */
        {
            temp = find_minimum(root->right);
            root->n = temp->n;
            root->right = avl_remove(root->right, temp->n);
        }
    }

    /* Rebalance the tree */
    root = balance_avl(root);

    return root;
}

/**
 * balance_avl - Balances an AVL tree after insertion or deletion.
 * @tree: Pointer to the root node of the AVL tree.
 * Return: Pointer to the balanced tree.
 */
avl_t *balance_avl(avl_t *tree)
{
    int balance;

    if (!tree)
        return NULL;

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
