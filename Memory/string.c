#include<cs50.h>
#include<stdio.h>

int main (void)
{
    char *s = get_string("Please enter a string: "); // 字符串本质上是一个指针(C中没有单独的字符串类型)
    printf("%s\n", s);
}
