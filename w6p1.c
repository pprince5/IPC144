//*****************************************************************************
//<assessment name example : Workshop - #6 (Part - 1)>
//Full Name :
//Student ID# :
//	Email :
//	Section :
//	Authenticity Declaration :
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider.This submitted
//piece of work is entirely of my own creation.
//* ****************************************************************************
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_NUMBER_ITEMS  10
#define MIN_NUMBER_ITEMS  1
int main() {

	const double MAX_INC = 400000.00;
	const double MIN_INC = 500.00;
	const double MIN_COST = 100;
	const  int   MIN_PRIORITY = 1;
	const int    MAX_PRIORITY = 3;
	const char YES = 'y';
	const char NO = 'n';

	double income;
	int valid = 1;
	int number_items;
	double cost[MAX_NUMBER_ITEMS];
	int priority[MAX_NUMBER_ITEMS];
	char finance[MAX_NUMBER_ITEMS];
	int i;
	double total_cost = 0;
	printf("+--------------------------+\n+   Wish List Forecaster   |\n+--------------------------+\n");

	do {
		valid = 1;
		printf("\n");
		printf("Enter your monthly NET income: $");
		scanf(" %lf", &income);
		if (income > MAX_INC) {
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n", MAX_INC);
			valid = 0;
		}
		if (income < MIN_INC) {
			printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n", MIN_INC);
			valid = 0;
		}
		
		
	} while (valid==0);


	do {
		valid = 1;
		printf("\n");
		printf("How many wish list items do you want to forecast?: ");
		scanf("%d", &number_items);
		if (number_items< MIN_NUMBER_ITEMS || number_items> MAX_NUMBER_ITEMS) {
			valid = 0;
			printf("ERROR: List is restricted to between %d and %d items.\n", MIN_NUMBER_ITEMS, MAX_NUMBER_ITEMS);
		}

	} while(valid ==0);

	for (i = 0; i < number_items; i++) {
		printf("\n");
		printf("Item-%d Details:\n", i + 1);
		do {
			valid = 1;
			printf("   Item cost: $");
			scanf(" %lf", &cost[i]);
			if (cost[i] < MIN_COST) {
				valid = 0;
				printf("      ERROR: Cost must be at least $100.00\n");
			}
		} while (valid == 0);
		
		do {
			valid = 1;
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf(" %d", &priority[i]);
			if (priority[i] > MAX_PRIORITY || priority[i]< MIN_PRIORITY) {
				printf("      ERROR: Value must be between %d and %d\n", MIN_PRIORITY, MAX_PRIORITY);
				valid = 0;
			}
		} while (valid==0);
		do {
			valid = 1;
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &finance[i]);
			if (finance[i] != YES && finance[i] != NO) {
				valid = 0;
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}
		
			
		} while (valid == 0);


	}
	
	// report
	printf("\n");
	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");\
		for (i = 0; i < number_items; i++) {
			printf("%3d  %5d    %5c    %11.2lf\n",i+1, priority[i],finance[i], cost[i]);
		    total_cost = total_cost + cost[i];
		}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", total_cost);
	
	printf("Best of luck in all your future endeavours!\n");

	return 0;
}
