#include <cs50.h>
#include <stdio.h>

void meow(int n);

int main(void)
{
    int n = get_int("Number: ");
    
    for (int i = 0; i < n; i++)
    {
        meow();
    }
}

void meow(int n)
{
    printf("meow\n");
}
