/******************************************************************************
	<assessment name example : Workshop - #3 (Part - 1)>
	Full Name :prince prince
Student ID# :145685228
	Email :pprince5@myseneca.ca
	Section :ZCC
	Authenticity Declaration :
I declare this submission is the result of my own work and has not been
	shared with any other student or 3rd party content provider.This submitted
	piece of work is entirely of my own creation.
	* ****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	const int PRODUCT1_ID = 111,
		PRODUCT2_ID = 222,
		PRODUCT3_ID = 111;
	const double PRODUCT1_PRICE = 111.49,
		PRODUCT2_PRICE = 222.99,
		PRODUCT3_PRICE = 334.49;
	const char PRODUCT1_TAXED = 'Y',
		PRODUCT2_TAXED = 'N',
		PRODUCT3_TAXED = 'N';
	double average_price = (PRODUCT1_PRICE + PRODUCT2_PRICE + PRODUCT3_PRICE) / 3;
	double test_value = 330.99;


	printf("Product Information\n");
	printf("===================\n");
	printf("Product-1 (ID:%d)\n", PRODUCT1_ID);
	printf("  Taxed: %c\n", PRODUCT1_TAXED);
	printf("  Price: $%.4lf\n", PRODUCT1_PRICE);

	printf("\n");
	printf("Product-2 (ID:%d)\n", PRODUCT2_ID);
	printf("  Taxed: %c\n", PRODUCT2_TAXED);
	printf("  Price: $%.4lf\n", PRODUCT2_PRICE);

	printf("\n");
	printf("Product-3 (ID:%d)\n", PRODUCT3_ID);
	printf("  Taxed: %c\n", PRODUCT3_TAXED);
	printf("  Price: $%.4lf\n", PRODUCT3_PRICE);

	printf("\n");
	printf("The average of all prices is: $%.4lf\n", average_price);

	printf("\n");
	printf("About Relational and Logical Expressions!\n");
	printf("========================================\n");
	printf("1. These expressions evaluate to TRUE or FALSE\n");
	printf("2. FALSE: is always represented by integer value 0\n");
	printf("3. TRUE : is represented by any integer value other than 0\n");

	printf("\n");
	printf("Some Data Analysis...\n");
	printf("=====================\n");
	printf("1. Is product 1 taxable? -> %d\n", PRODUCT1_TAXED == 'Y');

	printf("\n");
	printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n", PRODUCT2_TAXED && PRODUCT3_TAXED == 'N');

	printf("\n");
	printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n", test_value, PRODUCT3_PRICE < test_value);

	printf("\n");
	printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n", PRODUCT3_PRICE > PRODUCT1_PRICE + PRODUCT2_PRICE);

	printf("\n");
	printf("5. Is the price of product 1 equal to or more than the price difference\n");
	printf("   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n", PRODUCT1_PRICE >= PRODUCT3_PRICE - PRODUCT2_PRICE, PRODUCT3_PRICE - PRODUCT2_PRICE);

	printf("\n");
	printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n", PRODUCT2_PRICE >= average_price);

	printf("\n");
	printf("7. Based on product ID, product 1 is unique -> %d\n", PRODUCT1_ID != PRODUCT2_ID && PRODUCT1_ID != PRODUCT3_ID);

	printf("\n");
	printf("8. Based on product ID, product 2 is unique -> %d\n", PRODUCT2_ID != PRODUCT1_ID && PRODUCT2_ID != PRODUCT3_ID);

	printf("\n");
	printf("9. Based on product ID, product 3 is unique -> %d\n", PRODUCT3_ID != PRODUCT1_ID && PRODUCT3_ID != PRODUCT2_ID);




	return 0;
}