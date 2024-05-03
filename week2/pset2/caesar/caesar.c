#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        for (int i = 0; argv[1][i] != '\0'; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        int key = atoi(argv[1]);

        string plainText = get_string("plaintext: ");

        printf("ciphertext: ");
        for (int i = 0; plainText[i] != '\0'; i++)
        {
            char c = plainText[i];
            if (isalpha(c))
            {
                char m = isupper(c) ? 'A' : 'a';
                printf("%c", (c - m + key) % 26 + m);
            }
            else
            {
                printf("%c", c);
            }
        }
        printf("\n");
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    return 0;
}
