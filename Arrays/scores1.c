#include <cs50.h>
#include <stdio.h>

const int N = 3;

float average(int length, int array[]);

int main(void)
{
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score:");
    }
    printf("%f\n", average(N, scores)); // don't need [] after scores
}

float average(int length, int arrays[]) //定义在函数里的变量名随意，好理解即可
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += arrays[i];
    }
    return sum / (float) length; //ensure the return value is float
}
