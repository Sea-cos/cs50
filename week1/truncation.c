#include <cs50.h>
#include <stdio.h>

int main(void){

    // Get number from user
    int x = get_int("X: ");
    int y = get_int("Y: ");

    float z = (float) x / y;
    printf("%f\n", z);
}
