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
void sort(sequence_list* slt);
sequence_list* merge(sequence_list* a, sequence_list* b);

int main()
{
    sequence_list a;
    sequence_list b;
    sequence_list* p_a = &a;
    sequence_list* p_b = &b;
    init(p_a);
    init(p_b);

    datatype array_a[10] = {7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    for (int i = 0; i < 10; i++) {
        append(p_a, array_a[i]);
    }
    datatype array_b[5] = {0, 1, 2, 3, 4};
    for (int i = 0; i < 5; i++) {
        append(p_b, array_b[i]);
    }

    sequence_list* c = merge(p_a, p_b);
    display(*c);
    free(c);

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
    printf("\n");
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
    for (int i = slt->size; i > position; i--) {
        slt->a[i] = slt->a[i - 1];
    }
    slt->a[position] = x;
    slt->size++;
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
    slt->size--;
}

void sort(sequence_list* slt)
{
    for (int i = 0; i < slt->size - 1; i++) {
        for (int j = 0; j < slt->size - i - 1; j++) {
            if (slt->a[j] > slt->a[j + 1]) {
                datatype tmp = slt->a[j];
                slt->a[j] = slt->a[j + 1];
                slt->a[j + 1] = tmp;
            }
        }
    }
}

sequence_list* merge(sequence_list* a, sequence_list* b)
{
    sequence_list* p = (sequence_list*) malloc(sizeof(sequence_list));
    init(p);
    for (int i = 0; i < a->size; i++) {
        append(p, a->a[i]);
    }
    for (int i = 0; i < b->size; i++) {
        append(p, b->a[i]);
    }
    sort(p);
    return p;
}
