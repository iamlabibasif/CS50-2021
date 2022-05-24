#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    //prompt user for the input (range between 1 and 8 inclusive)
    do
    {
        height = get_int("Type the height of your pyramid: ");
    }
    while (height < 1 || height > 8);


     //for the left side of space
    for (int j = height; j > 0; j--)
    {
        for (int i = 1; i <= height; i++)
        {
            if (i < j)
            {
                printf(" ");

            }
            else
            {
                printf("#");
            }

        }

        //for the spaces in between
        printf("  ");

        //for the right side of space
        for (int k = height; k > 0 ; k--)
        {
            if (k >= j)
            {
                printf("#");
            }

        }

        //for line change
        printf("\n");
    }
}
