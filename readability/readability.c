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
    // Prompt the user for some text
    string text = get_string("Text:");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index
    float L = ((float)letters / (float)words) * 100; // 注意转换的格式submit50 cs50/problems/2025/x/readability
    float S = ((float)sentences / (float)words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Print the grade level
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
    int letter_count = 0;
    // 在同一条Declaration Statement中对多个变量进行初始化，只需在最前面声明一次类型
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i])) // ctype.h
        {
            letter_count++;
        }
    }
    return letter_count;
}

int count_words(string text)
{
    int word_count = 1;
    for (int j = 0, len = strlen(text); j < len; j++)
    {
        if (isblank(text[j])) // 有空格，就加1
        {
            word_count++;
        }
    }
    return word_count;
}

int count_sentences(string text)
{
    int sentence_count = 0;
    for (int k = 0, len = strlen(text); k < len; k++)
    {
        if (text[k] == '.' || text[k] == '?' || text[k] == '!')
        {
            sentence_count++;
        }
    }
    return sentence_count;
}
