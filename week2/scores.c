#include <cs50.h>
#include <stdio.h>

const int N = 3;

int main(void)
{

    int score[N];

    for (int i = 0; i < N; i++)
    {
        score[i] = get_int("Score: ");
    }

    printf("Average: %f\n", (score[0] + score[1] + score[2]) / (float) N);
}
