///*
//*****************************************************************************
//						  Workshop - #4 (P2)
//Full Name  :prince prince
//Student ID#: 145685228
//Email      : pprince5@myseneca.ca
//Section    : ZCC
//
//Authenticity Declaration:
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider. This submitted
//piece of work is entirely of my own creation.
//*****************************************************************************
//*/
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//int main(void)
//{
//	int need_apples, need_oranges, need_pears, need_tomatoes, need_cabbages, number_apples, number_tomatoes, number_pears, number_oranges, number_cabbages, do_again;
//
//
//	do {
//		printf("Grocery Shopping\n");
//		printf("================\n");
//
//		do {
//			printf("How many APPLES do you need? : ");
//			scanf("%d", &need_apples);
//			if (need_apples < 0)
//				printf("ERROR: Value must be 0 or more.\n");
//		} while (need_apples < 0);
//		printf("\n");
//
//		do {
//			printf("How many ORANGES do you need? : ");
//			scanf("%d", &need_oranges);
//			if (need_oranges < 0)
//				printf("ERROR: Value must be 0 or more.\n");
//		} while (need_oranges < 0);
//		printf("\n");
//
//		do {
//			printf("How many PEARS do you need? : ");
//			scanf("%d", &need_pears);
//			if (need_pears < 0)
//				printf("ERROR: Value must be 0 or more.\n");
//		} while (need_pears < 0);
//		printf("\n");
//
//		do {
//			printf("How many TOMATOES do you need? : ");
//			scanf("%d", &need_tomatoes);
//			if (need_tomatoes < 0)
//				printf("ERROR: Value must be 0 or more.\n");
//		} while (need_tomatoes < 0);
//		printf("\n");
//
//		do {
//			printf("How many CABBAGES do you need? : ");
//			scanf("%d", &need_cabbages);
//			if (need_cabbages < 0)
//				printf("ERROR: Value must be 0 or more.\n");
//		} while (need_cabbages < 0);
//		printf("\n");
//
//		printf("--------------------------\n");
//		printf("Time to pick the products!\n");
//		printf("--------------------------\n");
//
//		printf("\n");
//		if (need_apples > 0) {
//			do {
//				printf("Pick some APPLES... how many did you pick? : ");
//				scanf(" %d", &number_apples);
//				if (number_apples <= 0) {
//					printf("ERROR: You must pick at least 1!\n");
//				}
//
//				else if (0 < number_apples && number_apples <= need_apples)
//				{
//					need_apples = need_apples - number_apples;
//					if (need_apples != 0) {
//						printf("Looks like we still need some APPLES...\n");
//					}
//
//				}
//
//				else if (number_apples > need_apples) {
//					printf("You picked too many... only %d more APPLE(S) are needed.\n", need_apples);
//				}
//			} while (need_apples != 0);
//			printf("Great, that's the apples done!\n");
//
//
//
//			printf("\n");
//
//		}
//		if (need_oranges > 0) {
//			do {
//				printf("Pick some ORANGES... how many did you pick? : ");
//				scanf(" %d", &number_oranges);
//				if (number_oranges <= 0) {
//					printf("ERROR: You must pick at least 1!\n");
//				}
//
//				else if (0 < number_oranges && number_oranges <= need_oranges)
//				{
//					need_oranges = need_oranges - number_oranges;
//					if (need_oranges != 0) {
//						printf("Looks like we still need some ORANGES...\n");
//					}
//
//				}
//
//				else if (number_oranges > need_oranges) {
//					printf("You picked too many... only %d more ORANGE(S) are needed.\n", need_oranges);
//				}
//			} while (need_oranges != 0);
//			printf("Great, that's the oranges done!\n");
//
//			printf("\n");
//		}
//		if (need_pears > 0) {
//			do {
//				printf("Pick some PEARS... how many did you pick? : ");
//				scanf(" %d", &number_pears);
//				if (number_pears <= 0) {
//					printf("ERROR: You must pick at least 1!\n");
//				}
//
//				else if (0 < number_pears && number_pears <= need_pears)
//				{
//					need_pears = need_pears - number_pears;
//					if (need_pears != 0) {
//						printf("Looks like we still need some PEARS...\n");
//					}
//
//				}
//
//				else if (number_pears > need_pears) {
//					printf("You picked too many... only %d more PEAR(S) are needed.\n", need_pears);
//				}
//			} while (need_pears != 0);
//			printf("Great, that's the pears done!\n");
//
//
//
//			printf("\n");
//		}
//		if (need_tomatoes > 0) {
//			do {
//				printf("Pick some TOMATOES... how many did you pick? : ");
//				scanf(" %d", &number_tomatoes);
//				if (number_tomatoes <= 0) {
//					printf("ERROR: You must pick at least 1!\n");
//				}
//
//				else if (0 < number_tomatoes && number_tomatoes <= need_tomatoes)
//				{
//					need_tomatoes = need_tomatoes - number_tomatoes;
//					if (need_tomatoes != 0) {
//						printf("Looks like we still need some TOMATOES...\n");
//					}
//
//				}
//
//				else if (number_tomatoes > need_tomatoes) {
//					printf("You picked too many... only %d more TOMATO(ES) are needed.\n", need_tomatoes);
//				}
//			} while (need_tomatoes != 0);
//			printf("Great, that's the tomatoes done!\n");
//		}
//
//		if (need_cabbages > 0) {
//			do {
//				printf("Pick some CABBAGES... how many did you pick? : ");
//				scanf(" %d", &number_cabbages);
//				if (number_cabbages <= 0) {
//					printf("ERROR: You must pick at least 1!\n");
//				}
//
//				else if (0 < number_cabbages && number_cabbages <= need_cabbages)
//				{
//					need_cabbages = need_cabbages - number_cabbages;
//					if (need_cabbages != 0) {
//						printf("Looks like we still need some CABBAGES...\n");
//					}
//
//				}
//
//				else if (number_cabbages > need_cabbages) {
//					printf("You picked too many... only %d more CABBAGE(S) are needed.\n", need_cabbages);
//				}
//			} while (need_cabbages != 0);
//			printf("Great, that's the cabbages done!\n");
//		}
//		printf("\n");
//		printf("All the items are picked!\n");
//		printf("\n");
//		printf("Do another shopping? (0=NO): ");
//		scanf(" %d", &do_again);
//		printf("\n");
//	} while (do_again != 0);
//
//	printf("Your tasks are done for today - enjoy your free time!\n");
//	return 0;
//
//}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(){

	int need_apples;
do {
				printf("How many APPLES do you need? : ");
				scanf("%d", &need_apples);
				if (need_apples < 0)
					printf("ERROR: Value must be 0 or more.\n");
			} while (need_apples < 0);
			printf("\n");

			return 0;
}

