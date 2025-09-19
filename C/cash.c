#include <cs50.h> // greedy algorihtm贪心算法（找零问题）
#include <stdio.h>

int main(void)
{
    int cents
    do
    {
        cents = get_int("Change owed:");
    }
    while (cents < 0);

}

int calculate_quarters(int cents)
{
    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents -=25;
    }
    return quarters
}

int calculate_dimes(int quarters)
{
    int dimes = 0;
    while (cents >= 10)
    {
        dimes++;
        cents -= 10;
    }
    return dimes
}

int calcu
