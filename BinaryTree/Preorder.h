#ifndef __PREORDER_H__
#define __PREORDER_H__

#include "BinaryTree.h"

BinaryTreeNode *preorderCreateBinaryTree(char *array, int size);
void preorderTraversals(BinaryTreeNode *root);
void preorderTraversalsWithoutRecursion(BinaryTreeNode *root);
void preorderThreading(ThreadedBinaryTreeNode *root);
void preorderThreadTraversals(ThreadedBinaryTreeNode *root);

#endif // __PREORDER_H__