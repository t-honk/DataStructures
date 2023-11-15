#include "BST.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

TreeNode_t *BST_newNode(void *data)
{
    TreeNode_t *node = malloc(sizeof(TreeNode_t));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

BST_t BST_Init(int8_t (*dataComparator)(void *, void *))
{
    BST_t newBST;
    newBST.root = BST_newNode(NULL);
    newBST.dataComparator = dataComparator;
    return newBST;
}

TreeNode_t *BST_insertHelper(TreeNode_t *root, TreeNode_t *node, int8_t (*dataComparator)(void *, void *));
void BST_insert(BST_t *bst, void *data)
{
    // is first element
    if (bst->root->data == NULL && bst->root->left == NULL && bst->root->right == NULL)
    {
        bst->root->data = data;
        return;
    }
    TreeNode_t *newNode = BST_newNode(data);
    bst->root = BST_insertHelper(bst->root, newNode, bst->dataComparator);
}
TreeNode_t *BST_insertHelper(TreeNode_t *root, TreeNode_t *node, int8_t (*dataComparator)(void *, void *))
{
    if (root == NULL)
    {
        return node;
    }
    int8_t result = dataComparator(root->data, node->data);
    switch (result)
    {
    case -1:
        root->right = BST_insertHelper(root->right, node, dataComparator);
        break;
    case 1:
        root->left = BST_insertHelper(root->left, node, dataComparator);
        break;
    }
    return root;
}

void BST_printHelper(TreeNode_t *root, void (*printFn)(void *data));
void BST_print(BST_t *bst, void (*printFn)(void *data))
{
    BST_printHelper(bst->root, printFn);
}
void BST_printHelper(TreeNode_t *root, void (*printFn)(void *data))
{
    if (root != NULL)
    {
        BST_printHelper(root->left, printFn);
        printFn(root->data);
        BST_printHelper(root->right, printFn);
    }
}

bool BST_containsHelper(TreeNode_t *root, void *data, int8_t (*dataComparator)(void *, void *));
bool BST_contains(BST_t *bst, void *data)
{
    return BST_containsHelper(bst->root, data, bst->dataComparator);
}
bool BST_containsHelper(TreeNode_t *root, void *data, int8_t (*dataComparator)(void *, void *))
{
    if (root == NULL)
    {
        return false;
    }

    int8_t result = dataComparator(root->data, data);

    if (result == 0)
    {
        return true;
    }
    else if (result < 0)
    {
        return BST_containsHelper(root->right, data, dataComparator);
    }
    else
    {
        return BST_containsHelper(root->left, data, dataComparator);
    }
}

void BST_freeHelper(TreeNode_t *root);
void BST_free(BST_t *bst)
{
    BST_freeHelper(bst->root);
}
void BST_freeHelper(TreeNode_t *root)
{
    if (root != NULL)
    {
        BST_freeHelper(root->left);
        BST_freeHelper(root->right);
        free(root);
    }
}