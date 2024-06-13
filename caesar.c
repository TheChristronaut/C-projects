#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string key);
char rotate(int key_number, char plain_char);

int main(int argc, string argv[])
{
    // check command line argument
    if (argc != 2)
    {
        printf("Usage: caesar key\n");
        return 1;
    }

    // set command line argument to a string called "key"
    string key = argv[1];

    // check that key is only numerical digits
    if (!only_digits(key))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // convert key to int
    int key_number = atoi(key);

    // prompt user for plain text
    string plain_text = get_string("plaintext:  ");

    // rotate plain characters into cipher characters
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plain_text); i < n; i++)
        if (isalpha(plain_text[i]))
        {
            if (isupper(plain_text[i]))
            {
                char plain_char = plain_text[i] - 'A';
                char rotate_char = rotate(key_number, plain_char);
                char new_char = rotate_char + 'A';
                printf("%c", new_char);
            }
            if (islower(plain_text[i]))
            {
                char plain_char = plain_text[i] - 'a';
                char rotate_char = rotate(key_number, plain_char);
                char new_char = rotate_char + 'a';
                printf("%c", new_char);
            }
        }
        else
        {
            printf("%c", plain_text[i]);
        }
    printf("\n");
}

bool only_digits(string key)
{
    // set variable to track status of truth
    int non_digits = 0;

    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isdigit(key[i]))
        {
            non_digits++;
        }
    }
    if (non_digits > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

char rotate(int key_number, char plain_char)
{
    char rotate_char = plain_char + key_number;
    char wrap_char = rotate_char % 26;
    return wrap_char;
}
