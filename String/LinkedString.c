#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct _string
{
    char data;
    struct _string *next;
} String;

// insert 插入
// delete 删除
// concat 连接
// substring 子串
// compare 比较
// replase 替换
// search 查找

String *str_init(char *src);

int main(int argc, char const *argv[])
{

    return 0;
}

String *str_init(char *src)
{
    if (src == NULL)
    {
        return NULL;
    }
    int len = strlen(src);
    if (len > MAXSIZE)
    {
        printf("The string is too long!\n");
    }
    String *link = (String *)malloc(sizeof(String) * 1);
    String *head = link;
    link->next = NULL;
    for (int i = 0; i < len; i++)
    {
        link->data = src[i];
        link->next = (String *)malloc(sizeof(String) * 1);
        link = link->next;
    }
    link->next = NULL;
    return head;
}