#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree.h"

BinaryTreeNode *createBinaryTree(
    const char *array,
    int len,
    int index)
{
    BinaryTreeNode *node = NULL;
    if ((index < len) && (array[index] != '#'))
    {
        node = (BinaryTreeNode *)malloc(
            sizeof(BinaryTreeNode) * 1);
        node->data = array[index];
        node->lchild = createBinaryTree(
            array, len, index * 2 + 1);
        node->rchild = createBinaryTree(
            array, len, index * 2 + 2);
    }
    return node;
}

ThreadedBinaryTreeNode *createThreadBinaryTree(
    const char *array,
    int len,
    int index)
{
    ThreadedBinaryTreeNode *node = NULL;
    if ((index < len) && (array[index] != '#'))
    {
        node = (ThreadedBinaryTreeNode *)malloc(
            sizeof(ThreadedBinaryTreeNode) * 1);
        node->data = array[index];
        node->lchild = createThreadBinaryTree(
            array, len, index * 2 + 1);
        node->rchild = createThreadBinaryTree(
            array, len, index * 2 + 2);
    }
    return node;
}
