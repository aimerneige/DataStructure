#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef int datatype;
typedef struct {
    datatype a[MAX_SIZE];
    int size;
} sequence_list;

void init(sequence_list* slt);
void append(sequence_list* slt, datatype x);
void display(sequence_list slt);
int empty(sequence_list slt);
int find(sequence_list slt, datatype x);
datatype get(sequence_list slt, int i);
void insert(sequence_list* slt, datatype x, int position);
void delete(sequence_list* slt, int position);

int main()
{
    sequence_list list;
    sequence_list* p = &list;
    init(p);

    datatype array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    for (int i = 0; i < 10; i++) {
        append(p, array[i]);
    }

    display(list);

    if (empty(list)) {
        printf("Sequence list is empty.\n");
    }
    else {
        printf("Sequence list is not empty.\n");
    }

    int find_result;
    find_result = find(list, 4);
    if (find_result != -1) {
        printf("Find 4 success! Position is %d.\n", find_result);
    }
    else {
        printf("Can't find 4 in this list.\n");
    }

    find_result = find(list, 12);
    if (find_result != -1) {
        printf("Find 12 success! Position is %d.\n", find_result);
    }
    else {
        printf("Can't find 12 in this list.\n");
    }

    for (int i = 0; i < list.size; i++) {
        printf("%d:   %d", i, get(list, i));
    }

    display(list);
    insert(p, 14, 3);
    display(list);
    delete(p, 2);
    display(list);

    return 0;
}


void init(sequence_list* slt)
{
    slt->size = 0;
}

void append(sequence_list* slt, datatype x)
{
    if (slt->size == MAX_SIZE) {
        printf("The sequence list is full!\n");
        exit(1);
    }
    slt->a[slt->size] = x;
    slt->size++;
}

void display(sequence_list slt)
{
    for (int i = 0; i < slt.size; i++) {
        printf("%d ", slt.a[i]);
    }
}

int empty(sequence_list slt)
{
    return slt.size == 0 ? 1 : 0;
}

int find(sequence_list slt, datatype x)
{
    for (int i = 0; i < slt.size; i++) {
        if (slt.a[i] == x) {
            return i;
        }
    }
    return -1;
}

datatype get(sequence_list slt, int i)
{
    if (i >= slt.size || i < 0) {
        printf("Index wrong!\n");
        exit(1);
    }
    return slt.a[i];
}

void insert(sequence_list* slt, datatype x, int position)
{
    if (slt->size == MAX_SIZE) {
        printf("The sequence list is full.\n");
        exit(1);
    }
    if (position >= slt->size || position < 0) {
        printf("Position wrong!\n");
        exit(1);
    }
    for (int i = slt->size; i > position; i++) {
        slt->a[i] = slt->a[i - 1];
    }
    slt->a[position] = x;
}

void delete(sequence_list* slt, int position)
{
    if (position >= slt->size || position < 0) {
        printf("Position wrong!\n");
        exit(1);
    }
    for (int i = position; i < (slt->size - 1); i++) {
        slt->a[i] = slt->a[i + 1];
    }
}