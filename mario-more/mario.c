#include <cs50.h>
#include <stdio.h>

void print_symmetry_rows(int n);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height:");
    }
    while (height < 1);
    print_symmetry_rows(height);
}

void print_symmetry_rows(int n)
{
    for (int i = 1; i <= n; i++) // 注意要有=，不然会多出一个空格
    {
        for (int j = 0; j < n - i; j++) // 对于每一行，遍历一次空格
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int l = 0; l < i; l++) // 可以有更多优化：把打印#的过程写成一个函数，避免重复
        {
            printf("#");
        }
        printf("\n");
    }
}
