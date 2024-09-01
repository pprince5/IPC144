//*****************************************************************************
//<assessment name example : Workshop - #5 (Part - 2)>
//Full Name : prince
//Student ID# : 145685228
//	Email : pprince5@myseneca.ca
//	Section :ZCC
//	Authenticity Declaration :
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider.This submitted
//piece of work is entirely of my own creation.
//* ****************************************************************************
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3
int main(void) {
	const int JAN = 1;
	const int DEC = 12;
	int year, month, valid = 1, i;
	double mRate, eRate, sumM, sumE, sumA;

	printf("General Well-being Log\n======================\n");
	do {
		valid = 1;
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf(" %d %d", &year, &month);

		if (year > MAX_YEAR || year < MIN_YEAR) {
			printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
			valid = 0;
		}
		if (month > DEC || month < JAN) {
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
			valid = 0;

		}

	} while (!valid);
	printf("\n");
	printf("*** Log date set! ***\n");
	sumM = 0;
	sumE = 0;
	sumA = 0;
	for (i = 1; i <= LOG_DAYS; i++) {
	
		printf("\n");
		switch (month) {
		case 1:
			printf("%d-JAN-%02d\n", year, i);
			break;
		case 2:
			printf("%d-FEB-%02d\n", year, i);
			break;
		case 3:
			printf("%d-MAR-%02d\n", year, i);
			break;
		case 4:
			printf("%d-APR-%02d\n", year, i);
			break;
		case 5:
			printf("%d-MAY-%02d\n", year, i);
			break;
		case 6:
			printf("%d-JUN-%02d\n", year, i);
			break;
		case 7:
			printf("%d-JUL-%02d\n", year, i);
			break;
		case 8:
			printf("%d-AUG-%02d\n", year, i);
			break;
		case 9:
			printf("%d-SEP-%02d\n", year, i);
			break;
		case 10:
			printf("%d-OCT-%02d\n", year, i);
			break;
		case 11:
			printf("%d-NOV-%02d\n", year, i);
			break;
		case 12:
			printf("%d-DEC-%02d\n", year, i);
			break;
		default:
			break;




		}

		do {
			printf("   Morning rating (0.0-5.0): ");
			scanf("%lf", &mRate);
			if (mRate > 5.0 || mRate < 0) {
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
			}

		} while (mRate > 5.0 || mRate < 0);
		sumM = sumM + mRate;
		do {
			printf("   Evening rating (0.0-5.0): ");
			scanf("%lf", &eRate);
			if (eRate > 5.0 || eRate < 0) {
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
			}

		} while (eRate > 5.0 || eRate < 0);
		sumE = sumE + eRate;
		

	}
	sumA = sumA + sumM + sumE;
	printf("\n");
	printf("Summary\n=======\n");
	printf("Morning total rating: ");
	printf("%.3lf\n", sumM);
	printf("Evening total rating: ");
	printf(" %.3lf\n", sumE);
	printf("----------------------------\n");
	printf("Overall total rating: ");
	printf("%.3lf\n", sumA);
	printf("\n");
	printf("Average morning rating: ");
	printf(" %.1lf\n", sumM / LOG_DAYS);
	printf("Average evening rating: ");
	printf(" %.1lf\n", sumE / LOG_DAYS);
	printf("----------------------------\n");
	printf("Average overall rating: ");
	printf(" %.1lf\n", (sumM + sumE) / (2 * LOG_DAYS));










	return 0;
}