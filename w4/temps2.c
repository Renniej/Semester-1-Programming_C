//--------------------------------------------------
// Name:           Tai-Juan Rennie
// Student Number: 101359172
// Email:          
// Section:      BTP100SBB  
// Workshop:       4
//--------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {

	int DayHigh[10]; // Array for High Temp
	int DayLow[10];// Array for Low Temp
	int  counter; // Used to issue how many times for loop should loop
	int i;// for for loop

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: "); // Self-Explaintory Input
	scanf("%d", &counter);

	do {//Printf error message if input is less that 3 and greater than 10 & loop back

			printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
			scanf("%d", &counter);

		

	} while (counter < 3 || counter >10);

	printf("\n");
	
	for (i = 1; i <= counter; i++) {
	
		printf("Day %d - High: ", i );
		scanf("%d", &DayHigh[i]);

		printf("Day %d - Low: ", i);
		scanf("%d", &DayLow[i]);
	
	}
	printf("\n");

	//Print data out
	printf("Day  Hi  Low");

	for (i = 1; i <= counter; i++) {

		printf("\n%d    %d    %d", i, DayHigh[i], DayLow[i]);

	}
	printf("\n");  //For formatting purposes


	return 0;
}
