#include <stdio.h>
#include <stdlib.h>

#include "Postorder.h"
#include "Stack.h"

BinaryTreeNode *postorderCreateBinaryTree(char *array, int size)
{
    BinaryTreeNode *root;
    root = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode) * 1);
}

void postorderTraversals(BinaryTreeNode *root)
{
    if (root != NULL)
    {
        postorderTraversals(root->lchild);
        postorderTraversals(root->rchild);
        printf("%c ", root->data);
    }
}

void postorderTraversalsWithoutRecursion(BinaryTreeNode *root)
{
    BinaryTreeNodeStack *stack = createBinaryTreeNodeStack();
    BinaryTreeNode *cur = root;
    BinaryTreeNode *last = NULL;
    while (cur != NULL || !BinaryTreeNodeStack_isEmpty(stack))
    {
        while (cur != NULL)
        {
            BinaryTreeNodeStack_push_back(stack, cur);
            cur = cur->lchild;
        }
        cur = BinaryTreeNodeStack_peek(stack);
        if (cur->rchild == NULL || cur->rchild == last)
        {
            printf("%c ", cur->data);
            BinaryTreeNodeStack_pop_back(stack);
            last = cur;
            cur = NULL;
        }
        else
        {
            cur = cur->rchild;
        }
    }
}

void postorderThreading(ThreadedBinaryTreeNode *root)
{
    static ThreadedBinaryTreeNode *preNode = NULL;
    if (root != NULL)
    {
        postorderThreading(root->lchild);
        postorderThreading(root->rchild);
        if (root->lchild == NULL)
        {
            root->lchild = preNode;
            root->isLeftThread = 1;
        }
        if (preNode != NULL && preNode->rchild == NULL)
        {
            preNode->rchild = root;
            preNode->isRightThread = 1;
        }
        preNode = root;
    }
}