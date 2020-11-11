OBJECTS = main.o BinaryTree.o Preorder.o\
	Inorder.o Postorder.o Stack.o
TARGET = bintree

$(TARGET): $(OBJECTS)
	cc -o $(TARGET) $(OBJECTS)

BinaryTree.o: BinaryTree.h
Preorder.o: Preorder.h BinaryTree.h
Inorder.o: Inorder.h BinaryTree.h
Postorder.o: Postorder.h BinaryTree.h
Stack.o: Stack.h BinaryTree.h

.PHONY: clean run
clean:
	-rm -f $(TARGET) $(OBJECTS)
run:$(TARGET)
	-@echo
	-@echo ========================================
	-@./bintree
	-@echo ========================================
	-@echo
	-@echo run end.
	-@echo start clean files
	-rm -f $(TARGET) $(OBJECTS)
	-@echo clean end.
