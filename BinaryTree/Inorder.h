#ifndef __INORDER_H__
#define __INORDER_H__

#include "BinaryTree.h"

BinaryTreeNode *inorderCreateBinaryTree(char *array, int size);
void inorderTraversals(BinaryTreeNode *root);
void inorderTraversalsWithoutRecursion(BinaryTreeNode *root);
void inorderThreading(ThreadedBinaryTreeNode *root);
void inorderThreadTraversals(ThreadedBinaryTreeNode *root);

#endif // __INORDER_H__