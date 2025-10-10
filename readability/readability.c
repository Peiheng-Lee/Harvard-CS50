#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text:");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = (letters / words) * 100;
    float S = (sentences / words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    int index = round(index);
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
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
    {
        if (!isalpha(text[i])) // !对逻辑表达式取反
        {
            count += 1;
        }
    }
    return count;
}

int count_sentences(string text)
{
    count = 0;
    for (i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] = '.' || text[i] = '?' || text[i] = '!')
        {
            count += 1;
        }
    }
    return count;
}
