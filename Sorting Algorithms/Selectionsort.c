#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int temp;
    int counter;
    int random;
    int k;
    bool Z;

    int sort[] = {3, 5, 2, 13, 11, 9, 1, 98}; //1, 2, 3, 5, 9, 11, 13, 98

    for (int i = 0; i < 8; i++)
    {
        temp = 0;
        counter = 0;
        random = 0;
        Z = false;

        for (int j = i; j < 8; j++)
        {
            if(temp < (sort[i] - sort[j]))
            {
                temp = sort[i] - sort[j];
                counter = sort[j];
                k = j;
                Z = true;
            }
        }

        if (Z == true)
        {

        random = sort[i];
        sort [i] = counter;
        sort [k] = random;
        }
    }

    for (int l = 0; l < 8 ; l++)
    {
        printf("%i\n", sort[l]);
    }

}
