#include <stdio.h>
#include <string.h>
#include "tutorial.c"
#include "tictactoe.c"

int end = 1;
char option;
int main(int argc, char *argv[])
{
    printf("WELCOME TO TICTACTOE TERMINAL GAME!\n");
    while (end)
    {
        printf("\n");
        printf("Please, select an option: \n1. Play\n2. Rules\n3. Exit\n");

        scanf("%1c", &option);
        printf("\n");
        cleanStdin();

        switch (option)
        {
        case 49:
            tictactoe();
            break;
        case 50:
            tutorial();
            break;
        case 51:
            end = 0;
            printf("See you soon.\n");
            break;
        default:
            printf("Character not valid. Please, select an option.\n");
        }
    }

    return 0;
}