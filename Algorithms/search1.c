#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string strings[] = {"battleship", "boot", "canon", "iron", "thimble", "top hat"};

    string s = get_string("String:");
    for (int i = 0; i < 6; i++)
    {
        // if (string[i] == s)  '==' is not suitable for strings
        if (strcmp(strings[i], s) == 0) // 3 return values
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
