#include <stdio.h>
#include <stdlib.h>

#include "Preorder.h"
#include "Stack.h"

BinaryTreeNode *preorderCreateBinaryTree(char *array, int size)
{
    BinaryTreeNode *root;
    root = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode) * 1);
}

void preorderTraversals(BinaryTreeNode *root)
{
    if (root != NULL)
    {
        printf("%c ", root->data);
        preorderTraversals(root->lchild);
        preorderTraversals(root->rchild);
    }
}

void preorderTraversalsWithoutRecursion(BinaryTreeNode *root)
{
    BinaryTreeNodeStack *stack = createBinaryTreeNodeStack();
    while (root != NULL || !BinaryTreeNodeStack_isEmpty(stack))
    {
        while (root != NULL)
        {
            printf("%c ", root->data);
            BinaryTreeNodeStack_push_back(stack, root);
            root = root->lchild;
        }
        if (!BinaryTreeNodeStack_isEmpty(stack))
        {
            root = BinaryTreeNodeStack_pop_back(stack);
            root = root->rchild;
        }
    }
}

void preorderThreading(ThreadedBinaryTreeNode *root)
{
    static ThreadedBinaryTreeNode *preNode = NULL;
    if (root != NULL)
    {
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
        if (!root->isLeftThread)
        {
            preorderThreading(root->lchild);
        }
        if (!root->isRightThread)
        {
            preorderThreading(root->rchild);
        }
    }
}

void preorderThreadTraversals(ThreadedBinaryTreeNode *root)
{
    while (root)
    {
        while (!root->isLeftThread)
        {
            printf("%c ", root->data);
            root = root->lchild;
        }
        printf("%c ", root->data);
        root = root->rchild;
    }
}