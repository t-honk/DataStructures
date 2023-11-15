#ifndef BST_H
#define BST_H
#include <stdint.h>
#include <stdbool.h>

typedef struct TreeNode
{
    void *data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode_t;

/**
 * @struct BST
 * @brief Represents a Binary Search Tree (BST) structure.
 *
 * The BST structure contains a pointer to the root node and a function pointer for
 * comparing data elements in the tree.
 */
typedef struct BST
{
    TreeNode_t *root;

    /**
     * @brief Pointer to a data comparison function.
     *
     * The function should compare data of the type stored in the BST.
     * It returns an integer:
     * - -1 if data1 < data2,
     * - 0 if data1 == data2,
     * - 1 if data1 > data2.
     *
     * @param data1 The first data element to compare.
     * @param data2 The second data element to compare.
     * @return An integer indicating the comparison result.
     */
    int8_t (*dataComparator)(void *, void *);

} BST_t;

/**
 * @brief Initialize the BST struct
 *
 * Initializes BST struct with a root node value of NULL (will be replaced with first insertion)
 *
 * @param dataComparator Function pointer to users data comparison function
 *
 * @return BST_t
 */
BST_t BST_Init(int8_t (*dataComparator)(void *, void *));
void BST_insert(BST_t *bst, void *data);
bool BST_contains(BST_t *bst, void *data);
/**
 * @brief Prints the BST in nondecreasing order
 *
 * @param bst BST to print
 * @param printFn Function pointer to a function that handles / prints the users data type
 *
 */
void BST_print(BST_t *bst, void (*printFn)(void *data));
void BST_free(BST_t *bst);

#endif // BST_H