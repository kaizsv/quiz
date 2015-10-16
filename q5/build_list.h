#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct linklist_node {
    int value;
    struct linklist_node *pNext;
} node;

node *build(node *pHead, int n, int tail);
void release(node *pHead, node *cycle);
double diff_in_msecond(struct timespec t1, struct timespec t2);
 