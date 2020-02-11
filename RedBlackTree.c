#include <stdio.h>

struct red_black_tree;

typedef struct red_black_tree
{
    void *data;
    int color;
    struct red_black_tree *left;
    struct red_black_tree *right;
    struct red_black_tree *parent;
} red_black_tree_t;

void left_rotate(red_black_tree_t *root, red_black_tree_t *pNode)
{
    // 1、x结点右孩子y的左孩子变为x结点的右孩子
    red_black_tree_t *right = pNode->right;
    pNode->right = right->left;
    right->left->parent = pNode;
    right->parent = pNode->parent;
    // 2、x结点的双亲对应的孩子位置指向y结点的
    if (pNode->parent == NULL)
    {
        root = right;
    }
    else if (pNode == pNode->parent->left)
    {
        pNode->parent->left = right;
    }
    else
    {
        pNode->parent->right = right;
    }
    // 3、x结点变为y结点的左孩子
    right->left = pNode;
    // 4、x结点的双亲指向y结点
    pNode->parent = right;
}

void right_rotate(red_black_tree_t *root, red_black_tree_t *pNode)
{
    red_black_tree_t *left = pNode->left;
    pNode->left = left->right;
    left->right->parent = pNode;
    left->parent = pNode->parent;
    if (pNode->parent == NULL)
    {
        root = left;
    }
    else if (pNode == pNode->parent->left)
    {
        pNode->parent->left = left;
    }
    else
    {
        pNode->parent->right = left;
    }
    left->right = pNode;
    pNode->parent = left;
}

int main()
{
}