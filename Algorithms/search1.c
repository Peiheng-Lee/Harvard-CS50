#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string strings[] = {'battleship', 'boot', 'canon', 'iron', 'thimble', 'top hat'};

    string s = get_string("String:");
    for (int i = 0; i < 6; i++)
    {
        if (string[i] == s)
        {
            printf("Found\n");
            return 0;
        }
    }
}
