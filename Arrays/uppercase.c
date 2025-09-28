#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string name = get_string("Before:");
    printf("After: ");
    for (int i = 0, n = strlen(name); i < n; i++)
    {
        if (name[i] >= 'a' && name[i] <= 'z')
        {
            printf("%c", name[i] - 32); // ASCII
        }
        else
        {
            printf("%c", name[i]);
        }
    }
    printf("\n");
}
