#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "BinaryTree.h"
#include "Stack.h"

BinaryTreeNodeStack *createBinaryTreeNodeStack(
    void
)
{
    BinaryTreeNodeStack *s = (BinaryTreeNodeStack *)malloc(
        sizeof(BinaryTreeNodeStack) * 1);
    s->size = 0;
    return s;
}

bool BinaryTreeNodeStack_isEmpty(
    BinaryTreeNodeStack *stack
)
{
    return stack->size == 0 ? true : false;
}

bool BinaryTreeNodeStack_isFull(
    BinaryTreeNodeStack *stack
)
{
    return stack->size >= STACK_MAX_SIZE ? true : false;
}

BinaryTreeNode *BinaryTreeNodeStack_peek(
    BinaryTreeNodeStack *stack
)
{
    if (!BinaryTreeNodeStack_isEmpty(stack))
    {
        return stack->data[stack->size - 1];
    }
}

BinaryTreeNode *BinaryTreeNodeStack_pop_back(
    BinaryTreeNodeStack *stack)
{
    if (BinaryTreeNodeStack_isEmpty(stack))
    {
        return NULL;
    }
    else {
        return stack->data[--(stack->size)];
    }
}

bool BinaryTreeNodeStack_push_back(
    BinaryTreeNodeStack *stack,
    BinaryTreeNode *node)
{
    if (BinaryTreeNodeStack_isFull(stack))
    {
        return false;
    }
    else
    {
        stack->data[stack->size++] = node;
        return true;
    }
}
