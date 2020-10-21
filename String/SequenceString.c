#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100
#define END_STR '\0'

typedef struct _string
{
    char str[MAXSIZE];
    int length;
} String;

String str_init(char *src);
void str_show(String *src);
void str_insert(String *src, String *sub, int i);
void str_delete(String *src, int i, int len);
void str_concat(String *src, String *new);
String *str_substring(String *src, int i, int len);
int str_compare(String *a, String *b);
int str_replace(String *src, String *old, String *new);
int str_search(String *src, String *sub);

int main(int argc, char const *argv[])
{
    String a;
    a.str[0] = 'H';
    a.str[1] = 'e';
    a.str[2] = 'l';
    a.str[3] = 'l';
    a.str[4] = 'o';
    a.length = 5;
    str_show(&a);

    String b = str_init("World!\n");
    str_show(&b);

    str_insert(&a, &b, 2);
    str_show(&a);

    return 0;
}

// get a string with char string
String str_init(char *src)
{
    String a;
    a.length = 0;
    if (strlen(src) > MAXSIZE)
    {
        printf("Warning! Source str too long! New Strign will be cut.\n");
        for (int i = 0; i < MAXSIZE; i++)
        {
            a.str[i] = src[i];
        }
        a.length = MAXSIZE;
    }
    else
    {
        for (int i = 0; src[i] != END_STR; i++)
        {
            a.str[i] = src[i];
            a.length++;
        }
    }
    return a;
}

// print the string to standard output
void str_show(String *src)
{
    if (src == NULL)
    {
        return;
    }
    for (int i = 0; i < src->length; i++)
    {
        printf("%c", src->str[i]);
    }
}

// insert string `sub` to string `src` at position `i`
void str_insert(String *src, String *sub, int i)
{
    if (i < 0 || i > MAXSIZE)
    {
        printf("Illegal argument with \"i\" !\n");
        return;
    }
    if (src == NULL)
    {
        printf("The string \"src\" is null!\n");
        return;
    }
    if (sub == NULL)
    {
        printf("The string \"sub\" is null!\n");
        return;
    }
    if ((src->length + sub->length) > MAXSIZE)
    {
        printf("The old string is going to full!\n");
        return;
    }
    if (sub->length == 0)
    {
        return;
    }
    // ??
    int src_len = src->length;
    int sub_len = sub->length;
    for (int j = 0; j < sub_len; j++)
    {
        src->str[src_len + sub_len + j] = src->str[i + j];
    }

    src->length = src->length + sub->length;
}

// delete substring with length `len`
// start with position `i` at string `src`
void str_delete(String *src, int i, int len)
{
    for (int j = 0; j < len; j++)
    {
        src->str[i + j] = src->str[i + j + len];
    }
    src->length = src->length - len;
}

// concat string `new` to string `src`
void str_concat(String *src, String *new)
{
    if ((src->length + new->length) > MAXSIZE)
    {
        printf("New string is too long!\n");
        return;
    }
}

// get substring with length `len`
// start at position `i` at string `src`
// return a new string
String *str_substring(String *src, int i, int len)
{
    String *p = (String *)malloc(sizeof(String));
    p->length = len;
    for (int j = 0; j < len; j++)
    {
        p->str[j] = src->str[i + j];
    }
    return p;
}

// compare string `a` and `b`
// return 0 if same
int str_compare(String *a, String *b)
{
    if (a->length != b->length)
    {
        return 1;
    }
    int len = a->length;
    for (int i = 0; i < len; i++)
    {
        if (a->str[i] != b->str[i])
        {
            return 1;
        }
    }
    return 0;
}

// replace all of the substring same with `old` with
// new substring `new` at string `src`
// return the times of replace
// return -1 if arguments error
int str_replace(String *src, String *old, String *new)
{
    if (src == NULL || old == NULL || new == NULL)
    {
        return -1;
    }
    int cnt = 0;
    int p = str_search(src, old);
    while (p != -1)
    {
        str_delete(src, p, old->length);
        str_insert(src, new, p);
        p = str_search(src, old);
    }
    return cnt;
}

// search the for the position of string `sub` in `src`
// return the position if success
// return -1 if search failed
int str_search(String *src, String *sub)
{
}
