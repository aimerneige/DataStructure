#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree.h"
#include "Preorder.h"
#include "Inorder.h"
#include "Postorder.h"

char array[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};

int main(int argc, char const *argv[])
{
    const int arr_size = sizeof(array) / sizeof(array[0]);

    BinaryTreeNode *bt = createBinaryTree(array, arr_size, 0);

    printf("Preorder traversals with recursion:\n");
    preorderTraversals(bt);
    printf("\n");

    printf("Inorder traversals with recursion:\n");
    inorderTraversals(bt);
    printf("\n");

    printf("Postorder traversals with recursion:\n");
    postorderTraversals(bt);
    printf("\n");

    printf("Preorder traversals without recursion:\n");
    preorderTraversalsWithoutRecursion(bt);
    printf("\n");

    printf("Inorder traversals without recursion:\n");
    inorderTraversalsWithoutRecursion(bt);
    printf("\n");

    printf("Postorder traversals without recursion:\n");
    postorderTraversalsWithoutRecursion(bt);
    printf("\n");

    ThreadedBinaryTreeNode *tbt1 = createThreadBinaryTree(array, arr_size, 0);
    preorderThreading(tbt1);
    printf("Preorder traversals of Threaded Binary Tree:\n");
    preorderThreadTraversals(tbt1);
    printf("\n");

    ThreadedBinaryTreeNode *tbt2 = createThreadBinaryTree(array, arr_size, 0);
    inorderThreading(tbt2);
    printf("Inorder traversals of Threaded Binary Tree:\n");
    inorderThreadTraversals(tbt2);
    printf("\n");

    // printf("Postorder traversals of Threaded Binary Tree:\n");
    // postorderThreadTraversals(tbt);
    // printf("\n");

    return 0;
}
