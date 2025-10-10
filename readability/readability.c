#include <cs50.h>
#include <ctype.h>
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

    int findex = round(index);
    if (findex >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (findex < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", findex);
    }
}

int count_letters(string text)
{
    int count = 0;
    // 在同一条Declaration Statement中对多个变量进行初始化，只需在最前面声明一次类型
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i])) // ctype.h
        {
            count ++;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 1;
    for (int j = 0, len = strlen(text); j < len; j++)
    {
        if (isblank(text[j])) // 有空格，就加1
        {
            count ++;
        }
    }
    return count;
}

int count_sentences(string text)
{
    int count = 0;
    for (int k = 0, len = strlen(text); k < len; k++)
    {
        if (text[k] == '.' || text[k] == '?' || text[k] == '!')
        {
            count ++;
        }
    }
    return count;
}
