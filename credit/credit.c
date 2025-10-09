#include <cs50.h>
#include <math.h>
#include <stdio.h>

int get_length(long n);
bool luhn_isvalid(long n);
void print_card_type(long n);

int main(void)
{
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number < 1);

    if (luhn_isvalid(number))
    {
        print_card_type(number);
    }
    else
    {
        printf("INVALID\n");
    }
}

int get_length(long n)
{
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        count++;
    }
    return count;
}

bool luhn_isvalid(long n)
{
    int sum = 0;
    bool is_second_digit = false;
    while (n > 0)
    {
        int digit = n % 10; // 取出最后一位数字
        if (is_second_digit)
        {
            int digit2 = digit * 2;
            sum += (digit2 / 10) + (digit2 % 10);
        }
        else
        {
            sum += digit;
        }
        is_second_digit = !is_second_digit;
        n = n / 10;
    }
    return (sum % 10 == 0);
}

void print_card_type(long n)
{
    int length = get_length(n);
    long prefix = n;
    while (prefix > 100)
    {
        prefix = prefix / 10;
    }
    if (length == 15 && (prefix == 34 || prefix == 37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && (prefix >= 51 && prefix <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && (prefix / 10 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
