#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

int8_t dataComparator(void *a, void *b)
{
    int iA = *(int *)a;
    int iB = *(int *)b;
    if (iA < iB)
    {
        return -1;
    }
    else if (iA > iB)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void printInt(void *data)
{
    printf("%d\n", *(int *)data);
}

int main()
{
    int *ints = malloc(4 * sizeof(int));
    ints[0] = 10;
    ints[1] = 2;
    ints[2] = 5;
    ints[3] = 12;
    BST_t bst = BST_Init(dataComparator);
    for (int b = 0; b < 4; b++)
    {
        BST_insert(&bst, &ints[b]);
    }
    BST_print(&bst, printInt);
    BST_free(&bst);
    free(ints);
    return 0;
}
