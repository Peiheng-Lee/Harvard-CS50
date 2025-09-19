#include <cs50.h>
#include <stdio.h>

void print_rows(int n);

int main(void)
{
    int rows;
    do
    {
        rows = get_int("Give me a row number:");
    }
    while (rows <1);
    print_rows(rows);
}

void print_rows(int n)
{
    for (int i = 1; i<= n; i++)
    {
        printf("#");
    }
}
