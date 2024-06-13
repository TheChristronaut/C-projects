#include <cs50.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Accept single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open memory card
    FILE *card = fopen(argv[1], "r");

    if (argv[1] == NULL)
    {
        printf("Unable to open: %s\n", argv[1]);
        return 1;
    }

    // Create buffer
    BYTE buffer[BLOCK_SIZE];

    // Create bufer for file name
    char filename[8];
    FILE *img;

    // Create file counter
    int img_counter = 0;

    // Create variable for already found JPEG
    bool jpeg_found = false;

    // While data from memory card still left to read
    while (fread(buffer, BLOCK_SIZE, 1, card) == 1)
        // Look for JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // Close JPEG if one open
            if (jpeg_found == true)
            {
                fclose(img);
            }

            // Create JPEG from data
            sprintf(filename, "%03i.jpg", img_counter);
            img = fopen(filename, "w");
            fwrite(buffer, BLOCK_SIZE, 1, img);

            // Increment image counter
            img_counter++;

            // Set JPEG found to true
            jpeg_found = true;
        }
        else if (img_counter > 0)
        {
            fwrite(buffer, BLOCK_SIZE, 1, img);
        }
    // Free memory before exiting program
    fclose(img);
    fclose(card);
}
