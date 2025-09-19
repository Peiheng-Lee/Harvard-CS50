#include <cs50.h>
#include <stdio.h>

void print_symmetry_rows(int n);

int main(void)
{
    int rows;
    do
    {
        rows = get_int("Give me a row number:");
    }
    while (rows < 1);
    print_symmetry_rows(rows);
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
        for (int l = 0; l < i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}
