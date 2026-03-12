#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // 数据类型FILE, 指针文件file, w: write, a: append
    FILE *file = fopen("phonebook.csv", "a");

    // check: 只要有指针，一定要检查
    if (file == NULL)
    {
        return 1;
    }

    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    fprintf(file, "%s, %s\n", name, number);
    fclose(file);
}
