#include <stdio.h>
#include <cs50.h>

void swap(int *x, int *y);

int main(void)
{
    int x = 1;
    int y = 2;
    printf("x is %i and y is %i\n", x, y);
    swap(&x, &y);
    printf("x is %i and y is %i\n", x, y);
}

void swap(int *x, int *y)
{
    // tmp是普通整数变量，*x, *y是整数指针变量
    // 调用接收指针参数的函数时，需传递变量的地址（&变量名），而非变量值或错误的解引用（*变量名）
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
