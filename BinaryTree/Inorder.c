#include <stdio.h>
#include <stdlib.h>

#include "Inorder.h"
#include "Stack.h"

BinaryTreeNode *inorderCreateBinaryTree(char *array, int size)
{
    BinaryTreeNode *root;
    root = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode) * 1);
}

void inorderTraversals(BinaryTreeNode *root)
{
    if (root != NULL)
    {
        inorderTraversals(root->lchild);
        printf("%c ", root->data);
        inorderTraversals(root->rchild);
    }
}

void inorderTraversalsWithoutRecursion(BinaryTreeNode *root)
{
    BinaryTreeNodeStack *stack = createBinaryTreeNodeStack();
    while (root != NULL || !BinaryTreeNodeStack_isEmpty(stack))
    {
        while (root != NULL)
        {
            BinaryTreeNodeStack_push_back(stack, root);
            root = root->lchild;
        }
        if (!BinaryTreeNodeStack_isEmpty(stack))
        {
            root = BinaryTreeNodeStack_pop_back(stack);
            printf("%c ", root->data);
            root = root->rchild;
        }
    }
}

void inorderThreading(ThreadedBinaryTreeNode *root)
{
    static ThreadedBinaryTreeNode *preNode = NULL;
    if (root != NULL)
    {
        inorderThreading(root->lchild);
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
        inorderThreading(root->rchild);
    }
}

void inorderThreadTraversals(ThreadedBinaryTreeNode *root)
{
    while (root != NULL && !root->isLeftThread)
    {
        root = root->lchild;
    }
    while (root != NULL)
    {
        printf("%c ", root->data);
        if (root->isRightThread)
        {
            root = root->rchild;
        }
        else
        {
            root = root->rchild;
            while (root != NULL && !root->isLeftThread)
            {
                root = root->lchild;
            }
        }
    }
}
