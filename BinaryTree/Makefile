objects = main.o BinaryTree.o Preorder.o\
	Inorder.o Postorder.o Stack.o
target = bintree

$(target): $(objects)
	cc -o $(target) $(objects)

BinaryTree.o: BinaryTree.h
Preorder.o: Preorder.h BinaryTree.h
Inorder.o: Inorder.h BinaryTree.h
Postorder.o: Postorder.h BinaryTree.h
Stack.o: Stack.h BinaryTree.h

.PHONY: clean run
clean:
	-rm -f $(target) $(objects)
run:$(target)
	-./bintree
	-rm -f $(target) $(objects)
