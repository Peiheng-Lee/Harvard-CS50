#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);

int main(void)
{
    string text = get_string("Text:");
    int letters = count_letters(text);
    count_words()
}

int count_letters(string text)
{
    count = 0;
    for (i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i])) // ctype.h
        {
            count += 1;
        }
    }
    return count;
}

int count_words(string text)
{
    count = 0;
    for (i = 0, len = strlen(text); i < len; i++)
    if not(isalpha(text[i]))
}
