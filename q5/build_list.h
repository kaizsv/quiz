#include <stdio.h>
#include <stdlib.h>

typedef struct linklist_node {
    int value;
    struct linklist_node *pNext;
} node;

node *build(node *pHead, int n, int tail);
void release(node *pHead, node *cycle);
 