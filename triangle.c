#include <stdio.h>
#include <cs50.h>

bool if_triangle(float a, float b, float c);

int main(void)
{
    float a = get_int("Number1:");
    float b = get_int("Number2:");
    float c = get_int("Number3:");
    bool answer = if_triangle(a, b, c);
    if (answer)
    {
        printf("Can be a triangle!\n");
    }
    else
    {
        printf("Can't be a triangle!\n");
    }
}

bool if_triangle(float a, float b, float c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return false;
    }
    else if (a + b <= c || a + c <= b || b + c <= a)
    {
        return false;
    }
    return true;
}
