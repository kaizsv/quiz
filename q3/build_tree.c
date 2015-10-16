#include "build_tree.h"

node *new_tree_node(node *entry, int value)
{
    entry = malloc(sizeof(node));
    entry->value = value;
    entry->pLeft = NULL;
    entry->pRight = NULL;
    return entry;
}

node *build_tree(node *pHead)
{
    pHead = new_tree_node(pHead, 1);
    pHead->pRight = new_tree_node(pHead->pRight, 5);
    pHead->pRight->pRight = new_tree_node(pHead->pRight->pRight, 6);
    pHead->pLeft = new_tree_node(pHead->pLeft, 2);
    pHead->pLeft->pRight = new_tree_node(pHead->pLeft->pRight, 4);
    pHead->pLeft->pLeft = new_tree_node(pHead->pLeft->pLeft, 3);
    return pHead;
}

double diff_in_msecond(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000.0);
}

void release(node *pHead)
{
    node *curr = pHead;
    while (curr) {
        pHead = pHead->pRight;
        free(curr);
        curr = pHead;
    }
}
 