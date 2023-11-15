#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

Node_t *LL_newNode(void *data)
{
    Node_t *newNode = malloc(sizeof(Node_t));
    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

LinkedList_t LL_Init()
{
    LinkedList_t newList;
    newList.head = LL_newNode(NULL);
    return newList;
}

void LL_append(LinkedList_t *list, void *data)
{
    Node_t *newNode = LL_newNode(data);
    if (list->head->data == NULL)
    {
        list->head = newNode;
    }
    else
    {
        Node_t *temp = list->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void LL_pop(LinkedList_t *list)
{
    if (list->head == NULL)
    {
        return;
    }
    Node_t *current = list->head;
    Node_t *penultimate = NULL;
    while (current->next != NULL)
    {
        penultimate = current;
        current = current->next;
    }
    if (penultimate == NULL)
    {
        free(list->head->data);
        free(list->head);
        list->head = NULL;
    }
    else
    {
        free(current);
        penultimate->next = NULL;
    }
}

void LL_print(LinkedList_t *list, void (*printFn)(void *))
{
    Node_t *current = list->head;
    while (current != NULL)
    {
        printFn(current->data);
        current = current->next;
    }
}

void LL_free(LinkedList_t *list)
{
    Node_t *current = list->head;
    while (current != NULL)
    {
        Node_t *temp = current;
        current = current->next;
        free(temp);
    }
}