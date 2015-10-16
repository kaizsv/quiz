#include "build_list.h"

node *detectCycle(node *slow, node *fast)
{
    if (slow != NULL && fast != NULL && fast->pNext != NULL) {
        slow = slow->pNext;
        fast = fast->pNext->pNext;
        if (slow == fast)
            return slow;
    } else
        return NULL;
    return detectCycle(slow, fast);
}

int main()
{
    node *pHead = NULL;
    node *cycleNode;
    struct timespec start, end;

    pHead = build(pHead, 6, 2);

    clock_gettime(CLOCK_REALTIME, &start);
    cycleNode = detectCycle(pHead, pHead);
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

