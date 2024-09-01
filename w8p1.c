/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P1)
Full Name  : prince
Student ID#: 145685228
Email      : pprince5@myseneca.ca
Section    : ZCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS


// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* num)
{
	int val;
	do {
		scanf("%d", &val);
		if (val <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (val <= 0);

	if (num != NULL)
		*num = val;

	return val;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* num)
{
	double value;
	do {
		scanf("%lf", &value);
		if (value <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (value<=0);

	if (num != NULL)
		*num = value;

	return value;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int num_product)
{

	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", num_product);
	printf("NOTE: A 'serving' is %dg\n", NUM_GRAMS);
	printf("\n");
}

// 4. Get user input for the details of cat food product
struct  CatFoodInfo getCatFoodInfo(const int sequence_num)
{
	struct  CatFoodInfo food = { 1,0.0,0,0.0 };
	printf("Cat Food Product #%d\n", sequence_num +1);
	printf("--------------------\n");
	printf("SKU           : ");
	/*getIntPositive(&food.sku);*/
	food.sku = getIntPositive(NULL);
	printf("PRICE         : $");
	/*getDoublePositive(&food.price);*/
	food.price = getDoublePositive(NULL);
	printf("WEIGHT (LBS)  : ");
	/*getDoublePositive(&food.weight);*/
	food.weight = getDoublePositive(NULL);
	printf("CALORIES/SERV.: ");
	/*getIntPositive(&food.calories);*/
	food.calories = getIntPositive(NULL);
	printf("\n");
	

	return food;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const int calories, const double* weight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}

// 7. Logic entry point
void start(void)
{
	openingMessage(MAX_PRODUCT);
	int i;

	/*for (i = 1; i < MAX_PRODUCT; i++) 
	{
		getCatFoodInfo(i);
		
	}*/
	struct CatFoodInfo cfi[MAX_PRODUCT] = { {0} };
	for (i = 0; i < MAX_PRODUCT; i++) {
		cfi[i] = getCatFoodInfo(i);
	}
	displayCatFoodHeader();
	//displayCatFoodData(cfi[i].sku, &cfi[i].price,cfi[i].weight, &cfi[i].calories);

	for (i = 0; i < MAX_PRODUCT; i++) {
		displayCatFoodData(cfi[i].sku, &cfi[i].price, cfi[i].calories, &cfi[i].weight);
	}
}