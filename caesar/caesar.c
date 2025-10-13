#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string word);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument;i.e argc = 2
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // 这里不能加else语句，会使整个程序退出

    // Make sure every character in argv[1] is a digit
    bool result = only_digits(argv[1]);
    if (!result)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv[1](Pointer) from a `string` to an `int`;
    // atoi()用于读取指针对应的字符串并转换为整数
    int k = atoi(argv[1]);

    // Prompt user for plaintext
    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");

    // For each character in the plaintext:
    for (int j = 0, len = strlen(plaintext); j < len; j++)

    // Rotate the character if it's a letter
    {
        char c_rotate = rotate(plaintext[j], k);
        printf("%c", c_rotate);
    }
    printf("\n");
    return 0;
}

bool only_digits(string word)
{
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (!isdigit(word[i]))
        {
            return false; // 若触发return，其余部分函数不会执行
        }
    }
    return true;
}

char rotate(char c, int n)
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
            // 将字母转换为 0-25 的索引；加上密钥 n；对 26
            // 取模，以确保结果能“环绕”回字母表的开头；将 0-25 的索引转换回原来的 ASCII 字母
            char c_upper_rotate = ((c - 'A' + n) % 26) + 'A';
            return c_upper_rotate;
        }
        else
        {
            char c_lower_rotate = ((c - 'a' + n) % 26) + 'a';
            return c_lower_rotate;
        }
    }
    else
    {
        return c;
    }
}
