#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int change_owed;
    do
    {
        change_owed = get_int("How much change is owed, in cents? ");
    }
    while (change_owed < 0);

    // calculate how many qaurters to give customer
    int quarters = change_owed / 25;
    // subtract total value of quarters from change owed
    int quarters_value = quarters * 25;
    change_owed = change_owed - quarters_value;

    // calculate how many dimes to give customer
    int dimes = change_owed / 10;
    // subtract total value of dimes from change owed
    int dimes_value = dimes * 10;
    change_owed = change_owed - dimes_value;

    // calculate how many nickels to give customer
    int nickels = change_owed / 5;
    // subtract total value of nickels from change owed
    int nickels_value = nickels * 5;
    change_owed = change_owed - nickels_value;

    // calculate how many pennies to give customer
    int pennies = change_owed;

    // sum the total number of quarters, dimes, nickels, and pennies
    int total_coins = quarters + dimes + nickels + pennies;

    // print the sum
    printf("%i\n", total_coins);
}
