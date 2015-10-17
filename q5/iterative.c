#include "build_list.h"

node *detectCycle(node *pHead)
{
    node *slow = pHead;
    node *fast = pHead;
    node *cross = NULL;
    while (slow != NULL && fast != NULL && fast->pNext != NULL) {
        slow = slow->pNext;
        fast = fast->pNext->pNext;
        if (slow == fast) {
            cross = slow;
            break;
        }
    }
    if (cross) {
        slow = pHead;
        while (1) {
            if (slow == fast)
                return slow;
            slow = slow->pNext;
            fast = fast->pNext;
        }
    } else {
        return NULL;
    }
}

int main()
{
    node *pHead = NULL;
    node *cycleNode;
    struct timespec start, end;

    pHead = build(pHead, 100, 1);

    clock_gettime(CLOCK_REALTIME, &start);
    cycleNode = detectCycle(pHead);
    clock_gettime(CLOCK_REALTIME, &end);

    if (cycleNode)
        printf("There is a cycle at %d. Run time: %lf msec\n",
               cycleNode->value, diff_in_msecond(start, end));
    else
        printf("There is no cycle. Run time: %lf msec\n",
               diff_in_msecond(start, end));

    release(pHead, cycleNode);

    return 0;
}
