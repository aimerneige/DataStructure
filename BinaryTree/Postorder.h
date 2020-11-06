#ifndef __POSTORDER_H__
#define __POSTORDER_H__

#include "BinaryTree.h"

BinaryTreeNode *postorderCreateBinaryTree(char *array, int size);
void postorderTraversals(BinaryTreeNode *root);
void postorderTraversalsWithoutRecursion(BinaryTreeNode *root);
void postorderThreading(ThreadedBinaryTreeNode *root);
void postorderThreadTraversals(ThreadedBinaryTreeNode *root);

#endif // __POSTORDER_H__