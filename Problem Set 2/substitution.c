#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//argc represents the size of the array
//argv is used for a specific index
int main(int argc, string argv[])
{
    //initializing the variables
    string text = "";
    bool status = true;
    char temp = ' ';

    //if no arguments is provided after "./substitution"
    //note that "./substituion" will be considered as the first argument
    if (argc < 2)
    {
        printf("Usage: ./substitution key.\n");
        //returning 1 to stop the program. 1 represents something is wrong
        return 1;
    }

    //if the argument is not equal to 26 (either greater than 26 or smaller than 26)
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    //this whole loop will work if the argument is 26 in length
    else
    {
        //this loop is to check if there are any repeated characters
        for (int k = 0; k < 25; k++)
        {
            for (int l = k + 1; l < 26; l++)
            {
                if (argv[1][k] == argv[1][l])
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }
        }

        for (int i = 0; i < 26; i++)
        {
            //*to check if the argument is a letter or not
            if (isalpha(argv[1][i]) != 0)
            {
                if (i == 25 && status == true)
                {
                    //if the key is all letters then this loop will be executed
                    text = get_string("Plain text: ");
                    //asking the user to provide the text
                    printf("ciphertext: ");

                    for (int j = 0; j < strlen(text); j++)
                    {
                        //**to check if the text provided is alphabet or not
                        if (isalpha(text[j]) != 0)
                        {
                            //to check if the text provided is upper case
                            if (isupper(text[j]) != 0)
                            {
                                //to check if the key provided on that particular index is in upper case or not
                                //subtracting 65 for the ASCII vhart
                                if (isupper(argv[1][text[j] - 65]) != 0)
                                {
                                    printf("%c", argv[1][text[j] - 65]);
                                }

                                else
                                {
                                    //to convert the key in upper case and then printing
                                    temp = toupper(argv[1][text[j] - 65]);
                                    printf("%c", temp);
                                }
                            }

                            //to check if the text provided is lower case
                            else if (islower(text[j]) != 0)
                            {
                                //to check if the key provided on that particular index is in lower case or not
                                //subtracting 97 for the ASCII vhart
                                if (islower(argv[1][text[j] - 97]) != 0)
                                {
                                    printf("%c", argv[1][text[j] - 97]);
                                }

                                else
                                {
                                    //to convert the key in lower case and then printing
                                    temp = tolower(argv[1][text[j] - 97]);
                                    printf("%c", temp);
                                }
                            }

                        }

                        //**if the text provided is not alphabet then it will be printed as it is
                        else
                        {
                            printf("%c", text[j]);
                        }
                    }
                }

                else
                {
                    continue;
                }
            }

            //*if there are any non alphabetical characters
            else
            {
                status = false;
                printf("Key must contain alphabetical characters.\n");
                return 1;
            }
        }
    }
    printf("\n");
}
