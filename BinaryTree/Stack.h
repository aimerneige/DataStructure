#ifndef __STACK__H__
#define __STACK__H__

#include <stdbool.h>

#include "BinaryTree.h"

#define STACK_MAX_SIZE 100

typedef struct BinaryTreeNodeStack
{
    BinaryTreeNode *data[STACK_MAX_SIZE];
    int size;
} BinaryTreeNodeStack;

BinaryTreeNodeStack *
createBinaryTreeNodeStack(
    void);
bool BinaryTreeNodeStack_isEmpty(
    BinaryTreeNodeStack *stack);
bool BinaryTreeNodeStack_isFull(
    BinaryTreeNodeStack *stack);
BinaryTreeNode *
BinaryTreeNodeStack_peek(
    BinaryTreeNodeStack *stack);
BinaryTreeNode *
BinaryTreeNodeStack_pop_back(
    BinaryTreeNodeStack *stack);
bool BinaryTreeNodeStack_push_back(
    BinaryTreeNodeStack *stack,
    BinaryTreeNode *node);

#endif // __STACK__H__