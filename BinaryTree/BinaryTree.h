#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include "stdbool.h"

typedef struct BinaryTreeNode
{
    char data;
    struct BinaryTreeNode *lchild;
    struct BinaryTreeNode *rchild;
} BinaryTreeNode;

typedef struct ThreadedBinaryTreeNode
{
    char data;
    struct ThreadedBinaryTreeNode *lchild;
    struct ThreadedBinaryTreeNode *rchild;
    bool isLeftThread;
    bool isRightThread;
} ThreadedBinaryTreeNode;

BinaryTreeNode *createBinaryTree(
    const char *array,
    int len,
    int index);
ThreadedBinaryTreeNode *createThreadBinaryTree(
    const char *array,
    int len,
    int index);

#endif // __BINARY_TREE_H__