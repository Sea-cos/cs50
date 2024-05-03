#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    uint8_t buffer[512];
    int cont = 0;
    FILE *img = NULL; // Initialize img pointer

    while (fread(buffer, 1, 512, card) == 512)
    {
        // Check if it's a JPEG
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) &&
            ((buffer[3] & 0xf0) == 0xe0))
        {
            // If a JPEG is already open, close it
            if (img != NULL)
            {
                fclose(img);
            }

            // Prepare the new file name
            char filename[8];
            sprintf(filename, "%03i.jpg", cont++);

            // Open a new JPEG file
            img = fopen(filename, "w");
        }

        // If a JPEG is open, write to it
        if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    // Close the last JPEG file
    if (img != NULL)
    {
        fclose(img);
    }

    fclose(card);
}
