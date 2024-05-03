#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");

    char *t = malloc(strlen(s) + 1); //malloc - memory allocation, salva em outro lugar da memoria

    //copiar string em outra com outro endereço de memória
    strcpy(t, s);

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("%s\n", s);
    printf("%s\n", t);

    free(t); //contrario de malloc, libera o espaço da memoria.
    return 0;

}
