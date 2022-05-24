#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

   FILE *input = fopen(argv[1], "r");

    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = NULL;
    char NameOfFile[8];
    typedef uint8_t abc;
    abc Head[512];
    int count = 0;
    bool isJPEG = false;

   while(fread(&Head, sizeof(Head), 1, input))
   {
       if(Head[0] == 0xff && Head[1] == 0xd8 && Head[2] == 0xff && (Head[3] & 0xf0) == 0xe0)
       {
           isJPEG = true;
       }

       if( isJPEG == true)
       {
           if (output != NULL)
           {
               fclose(output);
           }

           sprintf(NameOfFile, "%03i.jpg", count);
           count++;
           output = fopen(NameOfFile, "w"); 
           isJPEG = false;
       }

       if (output != NULL)
        {
            fwrite(&Head, sizeof(Head), 1, output);
        }
   }

    fclose(input);
    fclose(output);
}