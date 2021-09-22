#include <stdio.h>
#include <string.h>

char name[2][30];              //double dimensional array to store names of the player
static int TURN, turns, state; //variables to track the state of the game

char board[3][3]; //3x3 matrix as the board of the game

void getNames()
{
    printf("\nPlayer 1, enter your name:");
    scanf("%s", name[0]);

    printf("\nPlayer 2, enter your name:");
    scanf("%s", name[1]);

    printf("\n%s, you take 0\n", name[0]);
    printf("%s, you take X\n\n", name[1]);
}

void draw()
{
    printf("-----------\n");
    printf(" %c | %c | %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
}

void initialiteBoard()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = '-';

    TURN = 0;
    turns = 0;
    state = 1;
}

void enterMove(int n1, int n2) //puts the player character on board
{
    char box = board[n1][n2];

    if (box == '-')
    {
        if (TURN == 0)
            box = '0';
        else
            box = 'X';

        board[n1][n2] = box;

        printf("Accepted\n");
    }

    else
        printf("Box not permited. Turn is over\n");
}

void cleanStdin() //protects the input dumping the unnecessary data
{
    char dump[200];
    int i = 0;
    do
    {
        scanf("%c", dump);
    } while (dump[i] != '\n');
}

void selectMove()
{
    char option[1];

    printf("Choose box (follow the numbers of the numpad):\n");
    printf("7 8 9\n");
    printf("4 5 6\n");
    printf("1 2 3\n");

    int end = 1;
    while (end)
    {
        scanf("%1s", option);

        cleanStdin();

        if ((49 > *option || *option > 57))
        {
            printf("Character not admited. Please, insert a correct number of the numpad.\n");
            end = 1;
        }
        else
        {
            end = 0;
        }
    }

    switch (*option)
    {
    case 49:
        enterMove(0, 0);
        break;
    case 50:
        enterMove(0, 1);
        break;
    case 51:
        enterMove(0, 2);
        break;
    case 52:
        enterMove(1, 0);
        break;
    case 53:
        enterMove(1, 1);
        break;
    case 54:
        enterMove(1, 2);
        break;
    case 55:
        enterMove(2, 0);
        break;
    case 56:
        enterMove(2, 1);
        break;
    case 57:
        enterMove(2, 2);
        break;
    }
}

void startTurn()
{
    printf("-----------------------------\n");
    printf("TURN: %s\nMOVES: %i\n\n", name[TURN], turns);
    turns++;

    selectMove();
}

int checkFinal()
{
    char symbol;
    int i, j, solution;

    if (!TURN)
        symbol = '0';
    else
        symbol = 'X';

    //Check rows
    i = 0;
    for (i; i < 3 && solution != 3; i++)
    {
        solution = 0;
        j = 0;
        for (j; j < 3 && solution != 3; j++)
        {
            if (board[i][j] == symbol)
                solution++;
        }
    }

    //Check columns
    j = 0;
    for (j; j < 3 && solution != 3; j++)
    {
        solution = 0;
        i = 0;
        for (i; i < 3 && solution != 3; i++)
        {
            if (board[i][j] == symbol)
                solution++;
        }
    }

    if (solution == 3)
        return 0;
    solution = 0;

    //Check diagonals
    i = 0;
    j = 0;
    while (i < 3 && j < 3 && solution != 3)
    {
        if (board[i][j] == symbol)
            solution++;
        i++;
        j++;
    }

    if (solution == 3)
        return 0;
    solution = 0;

    i = 0;
    j = 2;
    while (i < 3 && j < 3 && solution != 3)
    {
        if (board[i][j] == symbol)
            solution++;
        i++;
        j--;
    }

    if (solution == 3)
        return 0;
    return 1;
}

int tictactoe()
{
    initialiteBoard();
    getNames();
    while (state && turns != 9)
    {

        startTurn();
        draw();

        state = checkFinal();
        // Changes turn (if there is not a winner)
        if (state)
        {
            TURN++;
            TURN %= 2;
        }
    }

    if (turns == 9)
        printf("DRAW\n");
    else
        printf("WINNER IS %s\n", name[TURN]);

    return 0;
}