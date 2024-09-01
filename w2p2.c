//*****************************************************************************
//<assessment name example : Workshop - #2 (Part - 2)>
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
	double price_small, price_medium, price_large, average_excluding_tax, average_including_tax;
	int patty_number, tommy_number, sally_number, sub_total, total_tax, total;
	int sub_total_patty, sub_total_tommy, sub_total_sally, tax_patty, tax_tommy, tax_sally, total_patty, total_tommy, total_sally;
	const double TAX = 0.13;
	int excluding_quantity_toonies, excluding_quantity_loonies, excluding_quantity_quarters, excluding_quantity_dimes, excluding_quantity_nickels, excluding_quantity_pennies;
	int tax_balance_toonies, tax_balance_loonies, tax_balance_quarters, tax_balance_dimes, tax_balance_nickels, tax_balance_pennies;
	int including_quantity_toonies, including_quantity_loonies, including_quantity_quarters, including_quantity_dimes, including_quantity_nickels, including_quantity_pennies;
	int balance_toonies, balance_loonies, balance_quarters, balance_dimes, balance_nickels, balance_pennies;

	printf("Set Shirt Prices\n");
	printf("================\n");
	printf("Enter the price for a SMALL shirt: $");
	scanf("%lf", &price_small);
	printf("Enter the price for a MEDIUM shirt: $");
	scanf("%lf", &price_medium);
	printf("Enter the price for a LARGE shirt: $");
	scanf("%lf", &price_large);

	printf("\n");
	printf("Shirt Store Price List\n");
	printf("======================\n");
	printf("SMALL  : $%.2lf\n", price_small);
	printf("MEDIUM : $%.2lf\n", price_medium);
	printf("LARGE  : $%.2lf\n", price_large);

	printf("\n");
	printf("Patty\'s shirt size is \'S\'\n");
	printf("Number of shirts Patty is buying: ");
	scanf("%d", &patty_number);

	printf("\n");
	printf("Tommy\'s shirt size is \'L\'\n");
	printf("Number of shirts Tommy is buying: ");
	scanf("%d", & tommy_number);

	printf("\n");
	printf("Sally\'s shirt size is \'M\'\n");
	printf("Number of shirts Sally is buying: ");
	scanf("%d", &sally_number);

	sub_total_patty = patty_number * price_small * 100 + 0.5;
	sub_total_tommy = tommy_number * price_large * 100 + 0.5;
	sub_total_sally = sally_number * price_medium * 100 + 0.5;
	tax_patty = TAX * sub_total_patty + 0.5;
	tax_tommy = TAX * sub_total_tommy + 0.5;
	tax_sally = TAX * sub_total_sally + 0.5;
	total_patty = sub_total_patty + tax_patty;
	total_tommy = sub_total_tommy + tax_tommy;
	total_sally = sub_total_sally + tax_sally;
	sub_total = sub_total_patty + sub_total_tommy + sub_total_sally;
	total_tax = tax_patty + tax_sally + tax_tommy;
	total = total_patty + total_sally + total_tommy;
	printf("\n");
	printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
	printf("-------- ---- ----- --- --------- --------- ---------\n");
	printf("Patty    S    %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", price_small, patty_number, (double)sub_total_patty / 100.0, (double)tax_patty / 100.0, (double)total_patty/100);
	printf("Sally    M    %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", price_medium, sally_number, (double)sub_total_sally / 100.0, (double)tax_sally / 100.0, (double)total_sally/100);
	printf("Tommy    L    %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", price_large, tommy_number, (double)sub_total_tommy / 100.0, (double)tax_tommy / 100.0, (double)total_tommy/100);
	printf("-------- ---- ----- --- --------- --------- ---------\n");
	printf("                         %8.4lf  %8.4lf  %8.4lf\n",(double)sub_total/100, (double)total_tax/100, (double)total/100 );
	
	printf("\n");
	printf("Daily retail sales represented by coins\n");
	printf("=======================================\n");

	printf("\n");
	printf("Sales EXCLUDING tax\n");
	printf("Coin     Qty   Balance\n");
	printf("-------- --- ---------\n");
	printf("              %8.4lf\n", sub_total / 100.0);

	excluding_quantity_toonies = sub_total / 200;
	tax_balance_toonies = sub_total % 200;

	excluding_quantity_loonies = tax_balance_toonies / 100;
	tax_balance_loonies = tax_balance_toonies % 100;

	excluding_quantity_quarters = tax_balance_loonies / 25;
	tax_balance_quarters = tax_balance_loonies % 25;

	excluding_quantity_dimes = tax_balance_quarters / 10;
	tax_balance_dimes = tax_balance_quarters % 10;

	excluding_quantity_nickels = tax_balance_quarters /5;
	tax_balance_nickels = tax_balance_quarters % 5;

	excluding_quantity_pennies= tax_balance_nickels / 1;
	tax_balance_pennies = tax_balance_nickels % 1;

	
	printf("Toonies  %d    %6.4lf\n", excluding_quantity_toonies, tax_balance_toonies/100.0);
	printf("Loonies    %d    %6.4lf\n", excluding_quantity_loonies, tax_balance_loonies / 100.0);
	printf("Quarters   %d    %6.4lf\n", excluding_quantity_quarters, tax_balance_quarters / 100.0);
	printf("Dimes      %d    %6.4lf\n", excluding_quantity_dimes, tax_balance_dimes / 100.0);
	printf("Nickels    %d    %6.4lf\n", excluding_quantity_nickels, tax_balance_nickels / 100.0);
	printf("Pennies    %d    %6.4lf\n", excluding_quantity_pennies, tax_balance_pennies / 100.0);

	printf("\n");
	average_excluding_tax = (double)sub_total / (patty_number + tommy_number + sally_number);
	printf("Average cost/shirt: $%7.4lf\n", average_excluding_tax/100);

	printf("\n");
	printf("Sales INCLUDING tax\n");
	printf("Coin     Qty   Balance\n");
	printf("-------- --- ---------\n");
	printf("              %8.4lf\n", total / 100.0);

	including_quantity_toonies = total / 200;
	balance_toonies = total % 200;

	including_quantity_loonies = balance_toonies / 100;
	balance_loonies = balance_toonies % 100;

	including_quantity_quarters = balance_loonies / 25;
	balance_quarters = balance_loonies % 25;

	including_quantity_dimes = balance_quarters / 10;
	balance_dimes = balance_quarters % 10;

	including_quantity_nickels = balance_dimes /5;
	balance_nickels = balance_quarters % 5;

	including_quantity_pennies = balance_nickels / 1;
	balance_pennies = balance_nickels % 1;


	printf("Toonies  %d    %6.4lf\n", including_quantity_toonies, balance_toonies / 100.0);
	printf("Loonies    %d    %6.4lf\n", including_quantity_loonies, balance_loonies / 100.0);
	printf("Quarters   %d    %6.4lf\n", including_quantity_quarters, balance_quarters / 100.0);
	printf("Dimes      %d    %6.4lf\n", including_quantity_dimes, balance_dimes / 100.0);
	printf("Nickels    %d    %6.4lf\n", including_quantity_nickels, balance_nickels / 100.0);
	printf("Pennies    %d    %6.4lf\n", including_quantity_pennies, balance_pennies / 100.0);

	printf("\n");
	average_including_tax = (double)total / (patty_number + tommy_number + sally_number);
	printf("Average cost/shirt: $%7.4lf\n", average_including_tax/100);

	







	return 0;
}