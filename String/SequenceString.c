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
    String a = str_init("ABC");
    String b = str_init("FFF");
    str_insert(&a, &b, 1);
    str_show(&a);
    printf("\n");
    str_delete(&a, 1, 3);
    str_show(&a);
    printf("\n");
    str_concat(&a, &b);
    str_show(&a);
    printf("\n");
    String *sub = str_substring(&a, 1, 3);
    str_show(sub);
    printf("\n");
    String x = str_init("AAA");
    String y = str_init("AAA");
    if (str_compare(&x, &y) == 0)
    {
        printf("Same!\n");
    }
    else
    {
        printf("Don't same!\n");
    }
    str_delete(&y, 0, 1);
    if (str_compare(&x, &y) == 0)
    {
        printf("Same!\n");
    }
    else
    {
        printf("Don't same!\n");
    }
    String hello = str_init("Hello I am AimerNeige!\n");
    String name = str_init("AimerNeige");
    String new_name = str_init("NeigeAimer");
    str_replace(&hello, &name, &new_name);
    str_show(&hello);

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
        printf("The string \"src\" is null!\n");
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
    int src_len = src->length;
    int sub_len = sub->length;
    int after_len = src_len - i;
    for (int j = 0; j < after_len; j++)
    {
        src->str[src_len + sub_len - j - 1] = src->str[src_len - j - 1];
    }
    for (int j = 0; j < sub_len; j++)
    {
        src->str[i + j] = sub->str[j];
    }
    src->length = src->length + sub->length;
}

// delete substring with length `len`
// start with position `i` at string `src`
void str_delete(String *src, int i, int len)
{
    if (src == NULL)
    {
        printf("The string \"src\" is null!\n");
        return;
    }
    if (i >= src->length || len > MAXSIZE)
    {
        printf("Illegal argument!\n");
        return;
    }
    int src_len = src->length;
    int after_len = src_len - i - len;
    for (int j = 0; j < after_len; j++)
    {
        src->str[i + j] = src->str[i + len + j];
    }
    src->length = src_len - len;
}

// concat string `new` to string `src`
void str_concat(String *src, String *new)
{
    if (src == NULL)
    {
        printf("The string \"src\" is null!\n");
        return;
    }
    if (new == NULL)
    {
        printf("The string \"new\" is null!\n");
        return;
    }
    if ((src->length + new->length) > MAXSIZE)
    {
        printf("New string is too long!\n");
        return;
    }
    int src_len = src->length;
    int new_len = new->length;

    for (int i = 0; i < new_len; i++)
    {
        src->str[src_len + i] = new->str[i];
    }
    src->length = src_len + new_len;
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
    if (src == NULL)
    {
        printf("The string \"src\" is null!\n");
        return -1;
    }
    if (sub == NULL)
    {
        printf("The string \"sub\" is null!\n");
        return -1;
    }
    int src_len = src->length;
    int sub_len = sub->length;
    if (sub_len > src_len)
    {
        return -1;
    }
    int end_len = src_len - sub_len;
    int flag = 0;
    for (int i = 0; i <= end_len; i++)
    {
        for (int j = 0; j < sub_len; j++)
        {
            if (src->str[i + j] != sub->str[j])
            {
                break;
            }
            if (j == sub_len - 1)
            {
                flag = 1;
            }
        }
        if (flag == 1)
        {
            return i;
        }
    }
    return -1;
}
