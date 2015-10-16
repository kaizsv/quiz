#include "build_tree.h"

void flatten(node *root)
{
    node *temp;
    if (root->pLeft) {
        temp = root->pLeft;
        while (temp->pRight)
            temp = temp->pRight;
        temp->pRight = root->pRight;
        root->pRight = root->pLeft;
        root->pLeft = NULL;
    }
    if (root->pRight) {
        root = root->pRight;
        flatten(root);
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
