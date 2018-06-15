/*
Name:      Tai-Juan Rennie
Student#:  101359172
Section:   BTP100
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	double Input;
	int placeholder;
	double placeholder2;
	int loonies;
	int quarters;
	int dimes;
	int nickels;
	int pennies;
	
	double GST;
	printf("Please enter the amount to be paid: $");
	scanf("%lf", &Input);

	GST = Input * (0.13) + 0.005;
	Input = Input + GST;

	loonies = (int)Input;

	placeholder = (int)(100 * Input)- (loonies*100);
	
	
	quarters = (int)(placeholder / 25);

	dimes =(int)( (Input - (double)loonies - ((double)quarters*0.25))/0.10 );


	placeholder2 = Input - (double)loonies - ((double)quarters*0.25) - ((double)dimes*0.10);

	nickels = (int) (placeholder2 / 0.05);

	placeholder2 = Input - ((double)loonies) - ((double)quarters*0.25) - ((double)dimes*0.10) - ((double)nickels*0.05)    ;

	pennies = (int)(placeholder2 / 0.01);
	

	printf("GST: %.2lf\n", GST);
	printf("Balance owing: $%.2lf\n", Input);
	printf("Loonies required: %d, balance owing $%.2lf\n",loonies, Input-(double)loonies);
	printf("Quarters required: %d, balance owing $%.2lf\n", quarters, Input - (double)loonies - ((double)quarters*0.25));
	printf("Dimes required: %d, balance owing $%.2lf\n", dimes, Input - (double)loonies - ((double)quarters*0.25) - ((double)dimes*0.10));
	printf("Nickels required: %d, balance owing $%.2lf\n", nickels, Input - (double)loonies - ((double)quarters*0.25) - ((double)dimes*0.10) - ((double)nickels*0.05));
	printf("Pennies required: %d, balance owing $%.2lf\n", pennies, Input - (double)loonies - ((double)quarters*0.25) - ((double)dimes*0.10)- ((double)nickels*0.05) - ((double)pennies*0.01) );

	return 0;


}
