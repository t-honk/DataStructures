#include "BST.h"
#include <stdlib.h>
#include <stdint.h>

TreeNode_t *newNode(void *data)
{
    TreeNode_t *node = malloc(sizeof(TreeNode_t));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
