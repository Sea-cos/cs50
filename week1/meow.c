#include <cs50.h>
#include <stdio.h>

void meow(int n){

     for (int i = 0; i < n; i++){
        printf("meown\n");
    }
}


int main(void){
    meow(3);
}
