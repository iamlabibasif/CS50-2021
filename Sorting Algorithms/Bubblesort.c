#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int temp = 0;
    int counter = 0;

    int sort[] = {3, 5, 2, 13, 11, 9, 1, 98};

    //int length = sizeof(sort) - 1

    while(true)
    {
        counter = 0;

        for (int i = 0; i < 7; i++)
        {
            temp = 0;

            if (sort [i] > sort[i+1])
            {
            temp = sort[i + 1];
            sort [i + 1] = sort [i];
            sort [i] = temp;
            counter++;
            }
        }

        if (counter == 0)
        {
             for (int j = 0; j < 8 ; j++)
             {
                 printf("%i\n", sort[j]);
             }

             break;
        }
    }
}
