//*****************************************************************************
//<assessment name example : Workshop - #7 (Part - 1)>
//Full Name :prince
//Student ID# :145685228
//Email : pprince5@myseneca.ca
//Section : ZCC
//Authenticity Declaration :
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider.This submitted
//piece of work is entirely of my own creation.
//*****************************************************************************

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_PATH_LENGTH 70
#define MIN_PATH_LENGTH 10
#define MIN_NUM_LIVES 1
#define MAX_NUM_LIVES 10

//player information data structure
struct PlayerInfo
{
	int num_lives;
	char character_symbol;
	int num_teasures;
	int positions[MAX_PATH_LENGTH];
};

//game information data structure
struct GameInfo
{
	int max_num_moves;
	int path_length;
	int location_bombs[MAX_PATH_LENGTH];
	int location_treasure[MAX_PATH_LENGTH];
};


int main(Void)
{
	struct PlayerInfo player;
	struct GameInfo game;

	printf("================================\n");
	printf("         Treasure Hunt!\n");
	printf("================================\n");
	printf("\n");

	printf("PLAYER Configuration\n");
	printf("--------------------\n");

	printf("Enter a single character to represent the player: ");
	scanf(" %c", &player.character_symbol);

	do {
		printf("Set the number of lives: ");
		scanf("%d", &player.num_lives);
		if (player.num_lives< MIN_NUM_LIVES || player.num_lives>MAX_NUM_LIVES)
		{
			printf("     Must be between %d and %d!\n", MIN_NUM_LIVES, MAX_NUM_LIVES);
		}
	} while (player.num_lives< MIN_NUM_LIVES || player.num_lives>MAX_NUM_LIVES);
	printf("Player configuration set-up is complete\n\n");

	//game configuration
	printf("GAME Configuration\n");
	printf("------------------\n");

	do {
		printf("Set the path length (a multiple of 5 between 10-70): ");
		scanf(" %d", &game.path_length);
		if (game.path_length < MIN_PATH_LENGTH || game.path_length > MAX_PATH_LENGTH || game.path_length % 5 != 0)
		{
			printf("     Must be a multiple of 5 and between %d-%d!!!\n", MIN_PATH_LENGTH, MAX_PATH_LENGTH);
		}
	} while (game.path_length < MIN_PATH_LENGTH || game.path_length > MAX_PATH_LENGTH || game.path_length % 5 != 0);
	do {
		printf("Set the limit for number of moves allowed: ");
		scanf(" %d", &game.max_num_moves);
		if (game.max_num_moves < player.num_lives || game.max_num_moves > .75 * game.path_length)
		{
			printf("    Value must be between %d and %d\n", player.num_lives, (int)(.75 * game.path_length));
		}
	} while (game.max_num_moves < player.num_lives || game.max_num_moves > .75 * game.path_length);

	printf("\n");
	printf("BOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of 5 where a value\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");

	int i;
	for (i = 0; i < game.path_length; i += 5)
	{
		printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
		int j;
		for (j = i; j < i + 5; j++) {
			scanf(" %d", &game.location_bombs[j]);
		}
	}
	printf("BOMB placement set\n");

	printf("\n");
	printf("TREASURE Placement\n------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");
	for (i = 0; i < game.path_length; i += 5)
	{
		printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
		int j;
		for (j = i; j < i + 5; j++) {
			scanf(" %d", &game.location_treasure[j]);
		}
	}
	printf("TREASURE placement set\n");

	printf("\n");
	printf("GAME configuration set-up is complete...\n");
	printf("\n");
	printf("------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");
	printf("Player:\n");
	printf("   Symbol     : %c\n", player.character_symbol);
	printf("   Lives      : %d\n", player.num_lives);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n");
	printf("\n");
	printf("Game:\n");
	printf("   Path Length: %d\n", game.path_length);
	printf("   Bombs      : ");
	for (i = 0; i < game.path_length; i++) 
	{
		printf("%d", game.location_bombs[i]);
	}
	printf("\n   Treasure   : ");
	for (i = 0; i < game.path_length; i++) 
	{
		printf("%d", game.location_treasure[i]);
	}
	printf("\n");
	printf("\n");
	printf("====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n");
	return 0;
}
