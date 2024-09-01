//*****************************************************************************
//<assessment name example : Workshop - #6 (Part - 2)>
//Full Name :prince
//Student ID# :145685228
//	Email :pprince5@myseneca.ca
//	Section :ZCC
//	Authenticity Declaration :
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider.This submitted
//piece of work is entirely of my own creation.
//* ****************************************************************************
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_NUMBER 10
#define MIN_NUMBER 1

int main() {
	int forecast_number, i;
	int priority[MAX_NUMBER];
	int forecast_wish;
	int valid = 1;
	int priority_number;
	int year;
	int month;
	int priority_true = 0;


	double total_cost = 0;
	double cost[MAX_NUMBER];
	double total_cost_priority = 0;
	double  net_income;


	char finance[MAX_NUMBER];

	const int MIN_PRIORITY = 1;
	const int MAX_PRIORITY = 3;
	const char YES = 'y';
	const char NO = 'n';
	const int MAX_FORECAST = 2;
	const double MAX_INCOME = 400000;
	const double MIN_INCOME = 500;
	const double MIN_REQUIRED_COST = 100;

	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n");

	do {
		valid = 1;
		printf("\n");
		printf("Enter your monthly NET income: $");
		scanf(" %lf", &net_income);
		if (net_income > MAX_INCOME) {
			valid = 0;
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n", MAX_INCOME);

		}
		if (net_income < MIN_INCOME) {
			valid = 0;
			printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n", MIN_INCOME);
		}
	} while (valid == 0);

	do {
		valid = 1;
		printf("\n");
		printf("How many wish list items do you want to forecast?: ");
		scanf(" %d", &forecast_number);
		if (forecast_number > MAX_NUMBER || forecast_number < MIN_NUMBER) {
			valid = 0;
			printf("ERROR: List is restricted to between 1 and 10 items.\n");
		}
	} while (valid == 0);

	for (i = 0; i < forecast_number; i++) {
		printf("\n");
		printf("Item-%d Details:\n", i + 1);
		do {
			valid = 1;
			printf("   Item cost: $");
			scanf(" %lf", &cost[i]);
			if (cost[i] < MIN_REQUIRED_COST) {
				valid = 0;
				printf("      ERROR: Cost must be at least $100.00\n");
			}
		} while (valid == 0);

		do {
			valid = 1;
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf(" %d", &priority[i]);
			if (priority[i] > MAX_PRIORITY || priority[i] < MIN_PRIORITY) {
				valid = 0;
				printf("      ERROR: Value must be between %d and %d\n", MIN_PRIORITY, MAX_PRIORITY);
			}
		} while (valid == 0);

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
	printf("\n");
	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (i = 0; i < forecast_number; i++) {
		printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], finance[i], cost[i]);
		total_cost = total_cost + cost[i];
	}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf", total_cost);
	printf("\n");


	do {
		valid = 1;
		printf("\n");
		printf("How do you want to forecast your wish list?\n ");
		printf("1. All items (no filter)\n");
		printf(" 2. By priority\n");
		printf(" 0. Quit/Exit\n");
		printf("Selection: ");
		scanf(" %d", &forecast_wish);
		printf("\n");
		if (forecast_wish > MAX_FORECAST) {
			valid = 0;
			printf("ERROR: Invalid menu selection.\n");

		}
		if (forecast_wish <= MAX_NUMBER) {
			switch (forecast_wish) {
			case 1:priority_true = 0;
				valid = 0;
				printf("====================================================\n");
				printf("Filter:   All items\n");
				printf("Amount:   $%1.2lf\n", total_cost);
				year = (total_cost / net_income + 0.5) / 12;
				month = (total_cost / net_income) + 1 - year * 12;
				printf("Forecast: %d years, %d months\n", year, month);
				for (i = 0; i < forecast_number; i++)
				{
					if (finance[i] == YES) 
					{
						priority_true = 1;
					}
				}
				if (priority_true == 1) 
				{
					printf("NOTE: Financing options are available on some items.\n");
					printf("      You can likely reduce the estimated months.\n====================================================");
					printf("\n");
				}
				break;

			case 2: {priority_true = 0;
				valid = 0;
				printf("What priority do you want to filter by? [1-3]: ");
				scanf("%d", &priority_number);
				switch (priority_number) 
				{
				case 1:priority_true = 0;
					total_cost_priority = 0;
					printf("\n");
					printf("====================================================\n");
					printf("Filter:   by priority (%d)\n", priority_number);
					for (i = 0; i < forecast_number; i++)
					{
						if (priority[i] == priority_number)
						{
							total_cost_priority = total_cost_priority + cost[i];
							if (finance[i] == YES)
							{
								priority_true = 1;
							}
						}


					}
					printf("Amount:   $%1.2lf\n", total_cost_priority);
					year = (total_cost_priority / net_income + 0.5) / 12;
					month = (total_cost_priority / net_income) + 1 - year * 12;
					printf("Forecast: %d years, %d months\n", year, month);
					if (priority_true == 1)
					{
						printf("NOTE: Financing options are available on some items.\n");
						printf("      You can likely reduce the estimated months.\n====================================================");
						printf("\n");
					}
					break;
				case 2:priority_true = 0;
					total_cost_priority = 0;
					printf("\n");
					printf("====================================================\n");
					printf("Filter:   by priority (%d)\n", priority_number);
					for (i = 0; i < forecast_number; i++)
					{
						if (priority[i] == priority_number)
						{
							total_cost_priority = total_cost_priority + cost[i];
							if (finance[i] == YES) {
								priority_true = 1;
							}
						}

					}
					printf("Amount:   $%.2lf\n", total_cost_priority);
					year = (total_cost_priority / net_income + 0.5) / 12;
					month = (total_cost_priority / net_income) + 1 - year * 12;
					printf("Forecast: %d years, %d months\n", year, month);
					if (priority_true == 1)
					{
						printf("NOTE: Financing options are available on some items.\n");
						printf("      You can likely reduce the estimated months.\n"); 
					}
						printf("====================================================");
						printf("\n");
					break;
				case 3:priority_true = 0;
					total_cost_priority = 0;
					printf("\n");
					printf("====================================================\n");
					printf("Filter:   by priority (%d)\n", priority_number);
					for (i = 0; i < forecast_number; i++)
					{
						if (priority[i] == priority_number)
						{
							total_cost_priority = total_cost_priority + cost[i];
							if (finance[i] == YES)
							{
								priority_true = 1;
							}
						}

					}
					printf("Amount:   $%.2lf\n", total_cost_priority);
					year = (total_cost_priority / net_income + 0.5) / 12;
					month = (total_cost_priority / net_income) + 1 - year * 12;
					printf("Forecast: %d years, %d months\n", year, month);
					if (priority_true == 1)
					{
						printf("NOTE: Financing options are available on some items.\n");
						printf("      You can likely reduce the estimated months.\n====================================================");
						printf("\n");
					}
					break;
				case 0:
					valid = 1;
					break;
				default:break;
				}
				break;
			}

			default:
				break;

			}


		}
	} while (valid == 0);
	printf("Best of luck in all your future endeavours!\n");

	return 0;
}