#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s = get_string("S: ");
    char *t = get_string("T: ");

    // if (strcmp(s, t) == 0)
    // {
    //     printf("Same\n");
    // }
    // else
    // {
    //     printf("Different\n");
    // }

    //%P printa o endereço da memória onde esta armazenado a string.
    printf("%p\n", s);
    printf("%p\n", t);
}
