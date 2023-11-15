#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node
{
    void *data;
    struct Node *next;
} Node_t;

typedef struct
{
    Node_t *head;
} LinkedList_t;

/**
 * @brief Initializes a new linked list.
 *
 * This function creates and returns a new linked list with a head node.
 * The data of the head node is NULL and will be used to store the data from the first append.
 *
 * @return A pointer to the head of the initialized linked list.
 */
LinkedList_t LL_Init();

/**
 * @brief Appends data to the end of the linked list.
 *
 * @param list The LinkedList_t to append to
 * @param data The data to be added to the list.
 *
 * @return void
 *
 */
void LL_append(LinkedList_t *list, void *data);

/**
 * @brief Removes the last node from the list
 *
 * Removes the last node and frees the memory it was using, does NOT free the memory for the data.
 *
 * The library expects user to keep track of their memory.
 *
 * @param list LinkedList_t to remove from
 *
 * @return void
 */
void LL_pop(LinkedList_t *list);

/**
 * @brief Prints every node in the list, starting at the head.
 *
 * @param list The LinkedList_t to print
 * @param printFn User provided function to print their data, takes node->data as parameter
 *
 * @return void
 */
void LL_print(LinkedList_t *list, void (*printFn)(void *));

/**
 * @brief Free every node in the LinkedList_t
 *
 * Users are responsible for the data they store in the list and must free it themselves to prevent leaks
 *
 * @param list The list to be freed
 *
 * @return void
 */
void LL_free(LinkedList_t *list);

#endif