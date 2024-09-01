/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
Full Name  : Manav Alpeshbhai Zadafiya
Student ID#: 144095221
Email      : mazadafiya@myseneca.ca
Section    : ZEE
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MIN_LIVES 1
#define MAX_LIVES 10
#define MULTIPLES 5
#define MIN_MOVES 1
#define MIN_PATH_LENGTH 10
#define MAX_PATH_LENGTH 70

struct PlayerInfo {
    int numOfLives;
    char charSymbol;
    int numOfTreasure;
    int posHistory[MAX_PATH_LENGTH];
};

struct GameInfo {
    int movesAllowed;
    int pathLength;
    int bombLoc[MAX_PATH_LENGTH];
    int treasureLoc[MAX_PATH_LENGTH];
};

int main()
{
    int i, nextMove = 0, setLives = 0, flag = 0;
    struct PlayerInfo player;
    struct GameInfo game;
    player.numOfTreasure = 0;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.charSymbol);

    //Set Number of lives
    do {
        printf("Set the number of lives: ");
        scanf("%d", &player.numOfLives);
        if (player.numOfLives < MIN_LIVES || player.numOfLives > MAX_LIVES)
        {
            printf("     Must be between %d and %d!\n", MIN_LIVES, MAX_LIVES);
        }
        else
        {
            printf("Player configuration set-up is complete\n\n");
            setLives = 1;
        }
    } while (setLives != 1);

    //configure path length and moves
    printf("GAME Configuration\n");
    printf("------------------\n");
    printf("Set the path length (a multiple of %d between %d-%d): ", MULTIPLES, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
    scanf("%d", &game.pathLength);
    while ((game.pathLength < MIN_PATH_LENGTH || game.pathLength > MAX_PATH_LENGTH) || (game.pathLength % MULTIPLES != 0))
    {
        printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLES, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        printf("Set the path length (a multiple of %d between %d-%d): ", MULTIPLES, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        scanf("%d", &game.pathLength);
    }

    printf("Set the limit for number of moves allowed: ");
    scanf("%d", &game.movesAllowed);
    while (game.movesAllowed < player.numOfLives || game.movesAllowed >(int) (0.75 * game.pathLength))
    {
        printf("    Value must be between %d and %d\n", player.numOfLives, (int)(0.75 * game.pathLength));
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.movesAllowed);
    }

    //bomb position placemnet
    printf("\nBOMB Placement\n");
    printf("--------------\n");

    printf("Enter the bomb positions in sets of %d where a value\n", MULTIPLES);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    for (i = 0; i < game.pathLength; i = i + MULTIPLES)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLES);
        scanf("%d %d %d %d %d", &game.bombLoc[i], &game.bombLoc[i + 1], &game.bombLoc[i + 2], &game.bombLoc[i + 3], &game.bombLoc[i + 4]);
    }
    printf("BOMB placement set\n\n");

    //treasure position placement
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n", MULTIPLES);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    for (i = 0; i < game.pathLength; i = i + MULTIPLES)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLES);
        scanf("%d %d %d %d %d", &game.treasureLoc[i], &game.treasureLoc[i + 1], &game.treasureLoc[i + 2], &game.treasureLoc[i + 3], &game.treasureLoc[i + 4]);
    }
    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");

    //display summary
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    printf("Player:\n");
    printf("   Symbol     : %c\n", player.charSymbol);
    printf("   Lives      : %d\n", player.numOfLives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);

    printf("   Bombs      : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.bombLoc[i]);
    }
    printf("\n");

    printf("   Treasure   : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.treasureLoc[i]);
    }

    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    //game begins
    while (player.numOfLives >= 0 && game.movesAllowed >= 0)
    {
        if (flag == 1) {
            printf("  ");
            //line 1
            for (i = 0; i < nextMove; i++)
            {
                if ((i + 1) == nextMove)
                {
                    printf("%c", player.charSymbol);
                }
                else
                {
                    printf(" ");
                }
            }
        }
        flag = 1;

        printf("\n  ");
        //line 2
        for (i = 0; i < game.pathLength; i++)
        {
            if (player.posHistory[i] == 1)
            {
                if (game.bombLoc[i] == 1 && game.treasureLoc[i] == 1)
                {
                    printf("&");
                }
                else if (game.bombLoc[i] == 1 && game.treasureLoc[i] == 0)
                {
                    printf("!");
                }
                else if (game.treasureLoc[i] == 1 && game.bombLoc[i] == 0)
                {
                    printf("$");
                }
                else if (game.bombLoc[i] == 0 && game.treasureLoc[i] == 0)
                {
                    printf(".");
                }
            }
            else
            {
                printf("-");
            }
        }

        printf("\n  ");
        //line 3
        for (i = 0; i < game.pathLength; i++)
        {
            if ((i + 1) % 10 != 0)
            {
                printf("|");
            }
            else
            {
                printf("%d", (i + 1) / 10);
            }
        }

        printf("\n  ");
        //line 4
        for (i = 0; i < game.pathLength; i++)
        {
            printf("%d", (i + 1) % 10);
        }

        printf("\n");

        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.numOfLives, player.numOfTreasure, game.movesAllowed);
        printf("+---------------------------------------------------+\n");
        if (player.numOfLives == 0 || game.movesAllowed == 0)
        {
            printf("\n##################\n"
                "#   Game over!   #\n"
                "##################\n\n"
                "You should play again and try to beat your score!\n");
            player.numOfLives--;
        }
        else
        {
            // player move
            printf("Next Move [%d-%d]: ", MIN_MOVES, game.pathLength);
            scanf("%d", &nextMove);
            while (nextMove < MIN_MOVES || nextMove > game.pathLength)
            {
                printf("  Out of Range!!!\n");
                printf("Next Move [%d-%d]: ", MIN_MOVES, game.pathLength);
                scanf("%d", &nextMove);
            }
            printf("\n");

            //previous location
            if (player.posHistory[nextMove - 1] == 1)
            {
                printf("===============> Dope! You've been here before!\n");
            }

            // both bomb and treasure found 
            else if (game.bombLoc[nextMove - 1] == 1 && game.treasureLoc[nextMove - 1] == 1)
            {
                printf("===============> [&] !!! BOOOOOM !!! [&]\n");
                printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
                player.numOfLives--;
                player.numOfTreasure++;
                game.movesAllowed--;
            }
            // bomb found 
            else if (game.bombLoc[nextMove - 1] == 1)
            {
                printf("===============> [!] !!! BOOOOOM !!! [!]\n");
                player.numOfLives--;
                game.movesAllowed--;
            }

            // treasure found
            else if (game.treasureLoc[nextMove - 1] == 1)
            {
                printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
                player.numOfTreasure++;
                game.movesAllowed--;
            }

            //no bomb or treasure 
            else
            {
                printf("===============> [.] ...Nothing found here... [.]\n");
                game.movesAllowed--;
            }
            player.posHistory[nextMove - 1] = 1;
        }

        if (player.numOfLives == 0)
        {
            printf("\nNo more LIVES remaining!\n");
        }
        else if (game.movesAllowed == 0)
        {
            printf("\nNO more MOVES remaining\n");
        }
        printf("\n");
    }
    return 0;
}