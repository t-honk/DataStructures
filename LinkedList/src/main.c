#include "linkedlist.h"
#include <stdio.h>

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
    int x = 5;
    int y = 7;
    int z = 9;
    LL_append(&list, &x);
    LL_append(&list, &y);
    LL_append(&list, &z);

    LL_print(&list, printInt);
    LL_free(&list);

    return 0;
}