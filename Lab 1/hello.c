#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //getting input from user
    string answer = get_string("What is your name? ");
    
    //printing hello
    printf("hello, %s\n", answer);
}