#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int blocks;
    do
    {
        blocks = get_int("How many blocks tall?\n");
    }
    while (blocks < 1 || blocks > 8);

    int displayBlocks = blocks + 1;

    do
    {
        for (int i = 1; i < blocks; i++)
        {
            printf(" ");
        }

        for (int j = displayBlocks; j > blocks; j--)
        {
            printf("#");
        }

        printf("  ");

        for (int h = displayBlocks; h > blocks; h--)
        {
            printf("#");
        }

        printf("\n");

        blocks--;
    }
    while (blocks > 0);
}
