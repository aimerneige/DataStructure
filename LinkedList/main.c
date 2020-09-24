#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct link_node {
    datatype info;
    struct link_node *next;
} node;

node* init();
node* initWithValue(datatype value);
node* initWithArray(datatype* array, int size);
void  display(node* head);
node* find(node* head, int index);
node* insert(node* head, int index, datatype value);
node* insert_before(node* head, int index, datatype value);
node* delete(node* head, datatype value);
node* append(node* head, datatype value);
int   sizeOfList(node* head);
int   isSorted(node* head);
node* reverse(node* head);
node* a();
node* cut(node* head, int x, int y);


int main(int argc, char const *argv[])
{
    node* list = init();

    return 0;
}

// just get an empty list
node* init()
{
    return NULL;
}

// init a new node list with value
node* initWithValue(datatype value)
{
    node* head = (node*) malloc(sizeof(node) * 1);
    head->info = value;
    head->next = NULL;
    return head;
}

// init a new node list with array
node* initWithArray(datatype* array, int size)
{
    if (size == 0) {
        return NULL;
    }
    node* head = (node*) malloc(sizeof(node) * 1);
    node* p = head;
    for (int i = 0; i < size; i++) {
        p->info = array[i];
        p->next = (node*) malloc(sizeof(node) * 1);
    }
    free(p->next);
    return head;
}

// print out all value in node list
void display(node* head)
{
    if (head == NULL) {
        return;
    }
    node* p = head;
    while (p != NULL)
    {
        printf("%d ", p->info);
        p = p->next;
    }
    printf("\n");
}

// find the node in index
node* find(node* head, int index)
{
    if (head == NULL || index < 0) {
        return;
    }
    node* p = head;
    for (int i = 0; i < index; i++) {
        if (p == NULL) {
            return NULL;
        }
        p = p->next;
    }
    return p;
}

// insert the value after the index
node* insert(node* head, int index, datatype value)
{
    if (head == NULL || index < 0) {
        return;
    }
    node* p = head;
    for (int i = 0; i < index; i++) {
        if (p == NULL) {
            return NULL;
        }
        p = p->next;
    }
    node* next = p->next;
    p->next = (node*) malloc (sizeof(node) * 1);
    p->next->info = value;
    p->next->next = next;
    return head;
}

// insert the value before index
node* insert_before(node* head, int index, datatype value)
{
    if (head == NULL || index < 0) {
        return;
    }
    if (index == 0) {
        node* _node = (node*) malloc(sizeof(node) * 1);
        _node->info = value;
        _node->next = head;
        return _node;
    }
    node* p = head;
    for (int i = 0; i < index - 1; i++) {
        if (p == NULL) {
            return NULL;
        }
        p = p->next;
    }
    node* next = p->next;
    p->next = (node*) malloc (sizeof(node) * 1);
    p->next->info = value;
    p->next->next = next;
    return head;
}

// delete the first node with value
node* delete(node* head, int value)
{
    if (head == NULL) {
        return;
    }
    node* p = head;
    while (p != NULL) {
        if (p->info == value) {
            if (p->next) {
                if (p->next->next) {
                    node* next = p->next->next;
                    free(p->next);
                    p->next = next;
                }
                else {
                    free(p->next);
                }
            }
            return head;
        }
    }
    return head;
}

// append value on the end of list
node* append(node* head, datatype value)
{
    if (head == NULL) {
        head = (node*) malloc(sizeof(node) * 1);
        head->info = value;
        head->next = NULL;
        return head;
    }
    node* p = head;
    while (p != NULL) {
        if (p->next == NULL) {
            p = (node*) malloc(sizeof(node) * 1);
            p->info = value;
            p->next = NULL;
            return head;
        }
        p = p->next;
    }
    return;
}

// get the size of the list
int sizeOfList(node* head)
{
    int cnt = 0;
    node* p = head;
    while (p != NULL) {
        p = p->next;
        cnt++;
    }
    return cnt;
}

// weather the list is sorted
int isSorted(node* head)
{
    if (head == NULL) {
        return 0;
    }
    int ret = 1;
    node* p = head;
    while (p->next != NULL) {
        if (p->info > p->next->info) {
            ret = 0;
            break;
        }
        else {
            p = p->next;
        }
    }
    return ret;
}

// reverse a list
node* reverse(node* head)
{
    if (head == NULL) {
        return;
    }
    node* before = NULL;
    node* current = NULL;
    node* next = NULL;
    before = head;
    current = before->next;
    before->next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = before;
        before = current;
        current = next;
    }
    head = before;
    return head;
}




// delete all of the value between x and y on a sorted list
node* cut(node* head, int x, int y)
{
    if (head == NULL || x > y) {
        return;
    }
    // node* p = head;
    node* first = find(head, x);
    node* last  = find(head, y);
    if (first == NULL || last == NULL) {
        return head;
    }
    node* p = first->next;
    first->next = last;
    while(p != last) {
        node* tmp = p;
        p = p->next;
        free(tmp);
    }
    return head;
}

