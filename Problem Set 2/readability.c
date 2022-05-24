#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int sentenceCount = 0;
    int letterCount = 0;
    int wordCount = 1;
    int index;

    //Asking input from the user
    string sample = get_string("Text: ");

    //loop for the reading of words as per the condition
    for (int i = 0, n = strlen(sample); i < n; i++)
    {
        //for counting words
        if (sample[i] ==  ' ')
        {
            wordCount++;
        }

        //for counting sentences as per the condition
        if (sample[i] == '?' || sample[i] == '.' || sample[i] == '!')
        {
            sentenceCount++;
        }

        //for counting sentences as per the condition. A Library is being used to check if the particular index contains letter or not. Returns true or false.
        if (isalpha(sample[i]))
        {
            letterCount++;
        }
    }

    //Computing the Coleman-Liau index
    index = round(0.0588 * ((letterCount * 100) / (float) wordCount) - 0.296 * ((sentenceCount * 100) / (float) wordCount) - 15.8);

    //Assigning levels and printing the result
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", index);
    }
}