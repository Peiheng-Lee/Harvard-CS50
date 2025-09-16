#include <stdio.h>

void print_rows(int n);

int main(void)
{
    const int n = 3;

    // Print in rows
    for (int i = 0; i < n; i++)
    {
        print_rows(n);
    }
}

void print_rows(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
