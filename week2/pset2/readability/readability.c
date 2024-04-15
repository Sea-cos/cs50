#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int letters = 0;
int words = 0;
int spaces = 0;
int sentences = 0;
int grade = 0;

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float calculate_grade(int letters, int words, int sentences);

int main(void)
{
    /*index = 0.0588 * L - 0.296 * S - 15.8
    L = average number of letters per 100 words.
    S = average number of sentences per 100 words.
    */
    string text = get_string("Text: ");

    letters = count_letters(text);
    words = count_words(text);
    sentences = count_sentences(text);
    grade = calculate_grade(letters, words, sentences);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int) calculate_grade(letters, words, sentences));
    }
}

int count_letters(string text)
{
    for (int i = 0, count = strlen(text); i < count; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    spaces = 0;
    words = 0;
    for (int i = 0, count = strlen(text); i < count; i++)
    {
        if (text[i] == ' ')
        {
            spaces++;
            words = spaces + 1;
        }
    }
    return words;
}

int count_sentences(string text)
{
    for (int i = 0, count = strlen(text); i < count; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}

float calculate_grade(int let, int wo, int se)
{
    /*less 1 = Before Grade 1
      16 or higher = Grade 16+
    */
    float L = ((float) let / wo) * 100;
    float S = ((float) se / wo) * 100;

    float result = round(0.0588 * L - 0.296 * S - 15.8);

    return result;
}
