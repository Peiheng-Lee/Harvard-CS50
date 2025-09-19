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
    return quarters;
}

int calculate_dimes(int cents)
{
    int dimes = 0;
    while (cents >= 10)
    {
        dimes++;
        cents -= 10;
    }
    return dimes;
}

int calculate_nickles(int cents)
{
    int nickles = o;
    while (cents >= 5)
    {
        nickles++;
        cents-=5;
    }
    return nickles;
}

int calculate_pennies(int cents)
{
    int pennies = 0;
    while(cents > 0)
    {
        pennies++;
        cents -= 1;
    }
    return cents;
}
