#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // 2 parrelel arrays
    typedef struct
    {
        string names[] = {"Yuliia", "David", "John"};
        int numbers[] = {"+1-617-495-1000", "+1-617-495-1000", "+1-949-468-2750"};
    }
    person;


    string name = get_string("Name:");

    for (int i = 0; i < 3; i++)
    {
        if (strcmp(names[i], name == 0))
        {
            printf("Found %i\n", number[i]);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
