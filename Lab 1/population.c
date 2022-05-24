#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int startSize;
    int endSize;
    int years = 0;

    do
    {
        startSize = get_int("Type the starting population of Llamas: ");
    }
    while (startSize < 9);


    // TODO: Prompt for end size
    do
    {
        endSize = get_int("Type the ending population of Llamas: ");
    }
    while (endSize < startSize);


    // TODO: Calculate number of years until we reach threshold
    while (startSize < endSize)
    {
        years++;
        startSize = startSize + (startSize / 3) - (startSize / 4);
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);

}