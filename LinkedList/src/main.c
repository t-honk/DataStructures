#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

void printInt(void *data)
{
    if (data != NULL)
    {
        printf("%d \n", *(int *)(data));
    }
    else
    {
        printf("DATA NULL\n");
    }
}

int main()
{
    LinkedList_t list = LL_Init();
    int *ints = malloc(8 * sizeof(int));
    for (int i = 0; i < 8; i++)
    {
        ints[i] = i;
        LL_append(&list, &ints[i]);
    }
    int x = 5;
    int y = 7;
    int z = 9;
    LL_append(&list, &x);
    LL_append(&list, &y);
    LL_append(&list, &z);
    LL_pop(&list);

    LL_print(&list, printInt);
    LL_free(&list);
    free(ints);

    return 0;
}