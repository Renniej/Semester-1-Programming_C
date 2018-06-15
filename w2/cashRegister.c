/*
     Name:      Tai-Juan Rennie		
     Student#:  101359172
     Section:   BTP100
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	double Input;
	double placeholder;
	int loonies;
	int quarters;
	double leftover;
	printf("Please enter the amount to be paid: $");
	scanf("%lf", &Input);
	 
	loonies = (int)Input;

	placeholder = (Input - (double)loonies)*100;

	quarters = (int)(placeholder / 25);

	leftover = (placeholder - (double)(quarters * 25))/100;

	printf("Loonies required: %d, balance owing $%.2lf\nQuarters required: %d, balance owing $%.2lf\n", loonies, Input - loonies, quarters, leftover);


	
	return 0;


}
