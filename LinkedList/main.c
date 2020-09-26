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
node* cut(node* head, int x, int y);
node* getOdd(node* head);


int main(int argc, char const *argv[])
{
    // init
    node* list = init();
    if (list == NULL) {
        printf("The list is NULL\n");
    }

    // init with value
    node* list_value = initWithValue(123);
    display(list_value);

    // init with array
    datatype a[5] = {1, 2, 3, 4, 5};
    node* list_array = initWithArray(a, 5);
    display(list_array);

    // find
    node* ret = find(list_array, 3);
    if (ret == NULL) {
        printf("Find failed!\n");
    }
    else {
        printf("%d\n", ret->info);
    }
    ret = find(list_array, 7);
    if (ret == NULL) {
        printf("Find failed!\n");
    }
    else {
        printf("%d\n", ret->info);
    }

    // insert
    display(list_array);
    list_array = insert(list_array, 2, 9);
    display(list_array);
    list_array = insert(list_array, 6, 9);
    display(list_array);
    list_array = insert(list_array, -1, 23);
    display(list_array);
    list_array = insert(list_array, 0, 12);
    display(list_array);

    // insert before
    list_array = insert_before(list_array, 0, 99);
    display(list_array);
    list_array = insert_before(list_array, 8, 32);
    display(list_array);

    // delete
    list_array = delete(list_array, 99);
    display(list_array);
    list_array = delete(list_array, 12);
    display(list_array);
    list_array = delete(list_array, 32);
    display(list_array);
    list_array = delete(list_array, 99);
    display(list_array);

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
    if (size <= 0) {
        return NULL;
    }
    node* head = (node*) malloc(sizeof(node) * 1);
    node* p = head;
    for (int i = 0; i < size - 1; i++) {
        p->info = array[i];
        p->next = (node*) malloc(sizeof(node) * 1);
        p = p->next;
    }
    p->info = array[size - 1];
    p->next = NULL;
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
        return NULL;
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
        return head;
    }
    node* p = head;
    for (int i = 0; i < index; i++) {
        if (p == NULL) {
            return NULL;
        }
        p = p->next;
    }
    if (p == NULL) {
        return head;
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
        return head;
    }
    if (index == 0) {
        node* _node = (node*) malloc(sizeof(node) * 1);
        _node->info = value;
        _node->next = head;
        return _node;
    }
    return insert(head, index - 1, value);
}

// delete the first node with value
node* delete(node* head, int value)
{
    if (head == NULL) {
        return head;
    }
    node* p = head;
    if (head->info == value) {
        p = head->next;
        free(head);
        return p;
    }
    while (p != NULL) {
        if (p->next == NULL) {
            return head;
        }
        if (p->next->info == value) {
            node* del = p->next;
            node* before = p;
            if (del->next == NULL) {
                before->next = NULL;
                free(del);
                return head;
            }
            else {
                node* next = del->next;
                before->next = next;
                free(del);
                return head;
            }
        }
        p = p->next;
    }
    return head;
}

// append value on the end of list
node* append(node* head, datatype value)
{
    if (head == NULL) {
        
    }
    node* p = head;
    do {

        p = p->next;
    } while (p != NULL);
    return head;
    // if (head == NULL) {
    //     head = (node*) malloc(sizeof(node) * 1);
    //     head->info = value;
    //     head->next = NULL;
    //     return head;
    // }
    // node* p = head;
    // while (p != NULL) {
    //     if (p->next == NULL) {
    //         p->next = (node*) malloc(sizeof(node) * 1);
    //         p->next->info = value;
    //         p->next->next = NULL;
    //         return head;
    //     }
    //     p = p->next;
    // }
    // return NULL;
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
        return NULL;
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
        return NULL;
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

// delete all of the odd number and make them a new list
node* getOdd(node* head)
{
    if (head == NULL) {
        return NULL;
    }
    node* p = head;
    node* newList = init();
    while (p != NULL) {
        if (p->info % 2 != 0) {
            datatype value = p->info;
            delete(p, value);
            append(newList, value);
        }
        p = p->next;
    }
    return newList;
}
