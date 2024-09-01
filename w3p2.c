//*****************************************************************************
//<assessment name example : Workshop - #3 (Part - 1)>
//Full Name : prince prince
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
int main()
{
	char coffee_type1, coffee_type2, coffee_type3, coffee_strength, like_cream;
	char type1_suggest_cream, type2_suggest_cream, type3_suggest_cream;
	int type1_package_weight, type2_package_weight, type3_package_weight, serving_number;

	printf("Take a Break - Coffee Shop\n");
	printf("==========================\n");

	printf("\n");
	printf("Enter the coffee product information being sold today...\n");

	printf("\n");
	printf("COFFEE-1...\n");
	printf("Type ([L]ight,[M]edium,[R]ich): ");
	scanf(" %c", &coffee_type1);
	printf("Bag weight (g): ");
	scanf(" %d", &type1_package_weight);
	printf("Best served with cream ([Y]es,[N]o): ");
	scanf(" %c", &type1_suggest_cream);

	printf("\n");
	printf("COFFEE-2...\n");
	printf("Type ([L]ight,[M]edium,[R]ich): ");
	scanf(" %c", &coffee_type2);
	printf("Bag weight (g): ");
	scanf(" %d", &type2_package_weight);
	printf("Best served with cream ([Y]es,[N]o): ");
	scanf(" %c", &type2_suggest_cream);

	printf("\n");
	printf("COFFEE-3...\n");
	printf("Type ([L]ight,[M]edium,[R]ich): ");
	scanf(" %c", &coffee_type3);
	printf("Bag weight (g): ");
	scanf(" %d", &type3_package_weight);
	printf("Best served with cream ([Y]es,[N]o): ");
	scanf(" %c", &type3_suggest_cream);

	printf("\n");
	printf("---+------------------------+---------------+-------+\n");
	printf("   |    Coffee              |   Packaged    | Best  |\n");
	printf("   |     Type               |  Bag Weight   | Served|\n");
	printf("   +------------------------+---------------+ With  |\n");
	printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
	printf("---+------------------------+---------------+-------|\n");
	printf(" 1 |   %d   |   %d    |   %d   |  %d |  %.3lf |   %d   |\n", coffee_type1 == 'l'|| coffee_type1 == 'L', coffee_type1 == 'm' || coffee_type1 == 'M', coffee_type1 == 'r'|| coffee_type1 == 'R', type1_package_weight, (double)type1_package_weight / 453.6 , type1_suggest_cream == 'y'|| type1_suggest_cream == 'Y');
	printf(" 2 |   %d   |   %d    |   %d   |  %d |  %.3lf |   %d   |\n", coffee_type2 == 'l'|| coffee_type2 == 'L', coffee_type2 == 'm' || coffee_type2 == 'M', coffee_type2 == 'r'|| coffee_type2 == 'R', type2_package_weight, (double)type2_package_weight / 453.6, type2_suggest_cream == 'y'|| type2_suggest_cream == 'Y');
	printf(" 3 |   %d   |   %d    |   %d   | %d |  %.3lf  |   %d   |\n", coffee_type3 == 'l'|| coffee_type3 == 'L', coffee_type3 == 'm' || coffee_type3 == 'M', coffee_type3 == 'r'|| coffee_type3 == 'R', type3_package_weight, (double)type3_package_weight / 453.6, type3_suggest_cream == 'y'|| type3_suggest_cream == 'Y');

	printf("\n");
	printf("Enter how you like your coffee...\n");

	printf("\n");
	printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
	scanf(" %c", &coffee_strength);
	printf("Do you like your coffee with cream ([Y]es,[N]o): ");
	scanf(" %c", &like_cream);
	printf("Typical number of daily servings: ");
	scanf(" %d", &serving_number);
	
	printf("\n");
	printf("The below table shows how your preferences align to the available products:\n");

	printf("--------------------+-------------+-------+\n");
	printf("  |     Coffee      |  Packaged   | With  |\n");
	printf("ID|      Type       | Bag Weight  | Cream |\n");
	printf("--+-----------------+-------------+-------+\n");
	printf("1|       %d       |      %d      |   %d   |\n"),coffee_strength==coffee_type1,serving_number<=4 ,like_cream=='y'|| like_cream == 'Y';







	return 0;
}