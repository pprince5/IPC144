/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P2)
Full Name  : Prince
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

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

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
	} while (value <= 0);

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
	printf("Cat Food Product #%d\n", sequence_num + 1);
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
void displayCatFoodData(int sku_number, double* product_price, int calorie_per_serving, double* product_weight_lbs)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku_number, *product_price, *product_weight_lbs, calorie_per_serving);
}


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* pounds, double* conversionResultToKg) {
	double poundtoKg = (*pounds) / poundstokg;

	if (conversionResultToKg != NULL)
	{
		*conversionResultToKg = poundtoKg;
	}

	return poundtoKg;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* pounds, int* conversionResultToG) {
	int poundsToG = ((*pounds) / poundstokg) * 1000;

	if (conversionResultToG != NULL)
	{
		*conversionResultToG = poundsToG;
	}

	return poundsToG;
}

// 10. convert lbs: kg and g
void convertLbs(const double* pounds, double* conversionResultToKg, int* conversionResultToG) {
	double poundtokg = (*pounds) / poundstokg;
	int poundsToG = ((*pounds) / poundstokg) * 1000;

	if (conversionResultToG != NULL && conversionResultToKg != NULL)
	{
		*conversionResultToG = poundsToG;
		*conversionResultToKg = poundtokg;
	}
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeGrams, const int totalGrams, double* numberOfServings) {
	double servings = ((double)totalGrams) / servingSizeGrams;

	if (numberOfServings != NULL)
	{
		*numberOfServings = servings;
	}

	return servings;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* numberOfServings, double* result) {
	double costPerServing = (*price) / (*numberOfServings);

	if (result != NULL)
	{
		*result = costPerServing;
	}

	return costPerServing;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* totalCalories, double* result) {
	double costPerCal = (*price) / (*totalCalories);

	if (result != NULL)
	{
		*result = costPerCal;
	}

	return costPerCal;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo cfi) {

	struct ReportData rd;

	// Assigning Values
	rd.identification = cfi.sku;
	rd.reportprice = cfi.price;
	rd.reportpounds = cfi.weight;
	rd.reportcalories = cfi.calories;

	// Assigning calculated values
	rd.reportkgs = convertLbsKg(&rd.reportpounds, &rd.reportkgs);
	rd.reportgrams = convertLbsG(&rd.reportpounds, &rd.reportgrams);
	rd.reportservings = calculateServings(NUM_GRAMS, rd.reportgrams, &rd.reportservings);

	// Total calories
	double calories = rd.reportcalories * rd.reportservings;

	rd.reportcostperserving = calculateCostPerServing(&rd.reportprice, &rd.reportservings, &rd.reportcostperserving);
	rd.reportcalorieperserving = calculateCostPerCal(&rd.reportprice, &calories, &rd.reportcalorieperserving);


	// Returning the struct
	return rd;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", NUM_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData rd, const int cheapestProductCheck) {

	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", rd.identification, rd.reportprice, rd.reportpounds, rd.reportkgs, rd.reportgrams, rd.reportcalories, rd.reportservings, rd.reportcostperserving, rd.reportcalorieperserving);
}


// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cfi) {
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%5.2lf\n", cfi.sku, cfi.price);
	printf("\n");

	// Ending line
	printf("Happy shopping!\n");
	printf("\n");
}


// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	//arrays of Structures
	struct ReportData rd[MAX_PRODUCT] = { {0} };
	struct CatFoodInfo cfi[MAX_PRODUCT] = { {0} };

	//Variables
	int i, cheapestIndex = 0;

	//opening Message
	openingMessage(MAX_PRODUCT);

	//Cfi array
	for (i = 0; i < MAX_PRODUCT; i++) {
		cfi[i] = getCatFoodInfo(i);
		rd[i] = calculateReportData(cfi[i]);
	}

	//Catfood Header
	displayCatFoodHeader();

	//Catfood data
	for (i = 0; i < MAX_PRODUCT; i++) {
		displayCatFoodData(cfi[i].sku, &cfi[i].price, cfi[i].calories, &cfi[i].weight);
	}

	//Cheapest Product
	double cheapestProductPrice = rd[0].reportcostperserving;
	for (i = 0; i < MAX_PRODUCT; i++)
	{
		if (rd[i].reportcostperserving <= cheapestProductPrice)
		{
			cheapestProductPrice = rd[i].reportcostperserving;
			cheapestIndex = i;
		}
	}
	printf("\n");

	//Report Header
	displayReportHeader();

	//Report Data
	for (i = 0; i < MAX_PRODUCT; i++)
	{
		displayReportData(rd[i], cheapestIndex);

		if (cheapestIndex == i)
		{
			printf(" ***\n");
		}
		else
		{
			printf("\n");
		}
	}
	printf("\n");

	//Final Analysis
	for (i = 0; i < MAX_PRODUCT; i++)
	{
		if (i == cheapestIndex)
		{
			displayFinalAnalysis(cfi[i]);
		}
	}
}
