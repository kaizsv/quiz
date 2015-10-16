#include "build_list.h"

#include <time.h>

static double diff_in_msecond(struct timespec t1, struct timespec t2)
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

node *detectCycle(node *pHead)
{
    node *slow = pHead;
    node *fast = pHead;
    while (slow != NULL && fast != NULL && fast->pNext != NULL) {
        slow = slow->pNext;
        fast = fast->pNext->pNext;
        if (slow == fast) {
            return slow;
        }
    }
    return NULL;
}

int main()
{
    node *pHead = NULL;
    node *cycleNode;
    struct timespec start, end;

    pHead = build(pHead, 6, 2);

    clock_gettime(CLOCK_REALTIME, &start);
    cycleNode = detectCycle(pHead);
    clock_gettime(CLOCK_REALTIME, &end);

    release(pHead, cycleNode);

    if (cycleNode)
        printf("There is a cycle at %d. Run time: %lf msec\n",
               cycleNode->value, diff_in_msecond(start, end));
    else
        printf("There is no cycle. Run time: %lf msec\n",
               diff_in_msecond(start, end));
    return 0;
}
