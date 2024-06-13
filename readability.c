#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_sentences(string text);
int count_words(string text);

int main(void)
{
    // prompt user for text
    string text = get_string("Enter Text: ");

    // count number of letters
    int letters = count_letters(text);

    // count number of words
    int words = count_words(text);

    // count number of sentences
    int sentences = count_sentences(text);

    // calculate readability
    float float_letters = (float) letters;
    float float_words = (float) words;
    float float_sentences = (float) sentences;

    float average_letters = (float_letters / float_words) * 100.0;
    float average_sentences = (float_sentences / float_words) * 100.0;
    int index = round((0.0588 * average_letters) - (0.296 * average_sentences) - 15.8);

    // print readability level
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    // start counter for letters at 0
    int letters = 0;

    // count letters
    for (int i = 0, n = strlen(text); i < n; i++)
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
    // start counter for words at 1
    int words = 1;

    // count words
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isblank(text[i]))
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    // start counter for sentences at 0
    int sentences = 0;

    // count sentences
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.')
        {
            sentences++;
        }
        if (text[i] == '?')
        {
            sentences++;
        }
        if (text[i] == '!')
        {
            sentences++;
        }
    }
    return sentences;
}
