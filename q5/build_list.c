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
 