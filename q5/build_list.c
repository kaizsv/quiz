#include "build_list.h"

node *build(node *pHead, int n, int tail)
{
    node *curr = NULL;
    node *pTail = NULL;
    for (int i = 1; i <= n; i++) {
        if (pHead == NULL) {
            pHead = malloc(sizeof(node));
            pHead->value = i;
            pHead->pNext = NULL;
            curr = pHead;
        } else {
            curr->pNext = malloc(sizeof(node));
            curr->pNext->value = i;
            curr->pNext->pNext = NULL;
            curr = curr->pNext;
            if (i == tail)
                pTail = curr;
        }
    }
    curr->pNext = pTail;
    return pHead;
}


void release(node *pHead, node *cycle)
{
    node *curr = pHead;
    while (pHead != cycle) {
        pHead = pHead->pNext;
        free(curr);
        curr = pHead;
    }
    free(pHead);
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
 