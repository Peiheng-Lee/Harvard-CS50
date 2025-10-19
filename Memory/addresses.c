#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p); // not *p; or:

    printf("%i\n", *p);
}
