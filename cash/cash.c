#include <cs50.h> // greedy algorihtm贪心算法（找零问题）;while loop其实很麻烦，直接用operators: /%
#include <stdio.h>

int main(void)
{
    int cents;
    do
    {
        cents = get_int("Change owed:");
    }
    while (cents < 0);

    int quarters = cents / 25;
    cents = cents % 25;

    int dimes = cents / 10;
    cents = cents % 10;

    int nickels = cents / 5;
    cents = cents % 5;

    int pennies = cents;
    
    int total = quarters + dimes + nickels + pennies;
    printf("%i\n", total);
}
