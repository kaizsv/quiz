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
 