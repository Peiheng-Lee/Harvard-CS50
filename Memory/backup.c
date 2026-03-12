#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p); // not *p;

    printf("%i\n", *p); // * means going to what location p stores, which is n
}
