#include <stdlib.h>
#include <stdio.h>

typedef struct TREE_NODE {
    int value;
    struct TREE_NODE *pLeft;
    struct TREE_NODE *pRight;
} node;

node *new_tree_node(node *entry, int value);
node *build_tree(node *pHead);
