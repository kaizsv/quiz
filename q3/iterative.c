#include <time.h>

#include "build_tree.h"

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

void flatten(node *root)
{
    node *temp;
    while (root) {
        if (root->pLeft) {
            temp = root->pLeft;
            while (temp->pRight)
                temp = temp->pRight;
            temp->pRight = root->pRight;
            root->pRight = root->pLeft;
            root->pLeft = NULL;
        }
        root = root->pRight;
    }
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

int main()
{
    node *pHead = NULL;
    struct timespec start, end;

    pHead = build_tree(pHead);

    clock_gettime(CLOCK_REALTIME, &start);
    flatten(pHead);
    clock_gettime(CLOCK_REALTIME, &end);

    release(pHead);

    printf("run time: %lf msec\n", diff_in_msecond(start, end));

    return 0;
}


