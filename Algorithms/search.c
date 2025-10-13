#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number[] = {, , , , , , , };

    int n = get_int("Number:");
    for (int i = 0; i < 7; i++)
    {
        if (number[i] == n)
        {
            printf("Found!\n");
        }
    }
}
