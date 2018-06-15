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
	int  counter; // Used to issue how many times "for loop" should loop

	int HighestTemp = -10000; //Variable to store highest input temp (Set to -10000 intially because it's unrealistically low)
	int HighestTempDay; //day which highest temp occured
	int LowestTemp = 10000;//Variable to store lowest  input temp (Set to 10000 intially because it's unrealistically high)
	int LowestTempDay; // day which lowest temp occured

	float Avg; //Used to calculate temp average for specific day

	int i;// for for loop

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: "); // Self-Explaintory Input
	scanf("%d", &counter);

	while (counter < 3 || counter >10) {//Printf error message if input is less that 3 and greater than 10 & loop back

		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &counter);



	}

	printf("\n");//For formatting purposes

	for (i = 1; i <= counter; i++) {

		printf("Day %d - High: ", i);
		scanf("%d", &DayHigh[i]);

		printf("Day %d - Low: ", i);
		scanf("%d", &DayLow[i]);

		// See if temps are all time lowest/highest
		if (DayHigh[i] > HighestTemp) {

			HighestTemp = DayHigh[i];
			HighestTempDay = i;

		}

		if (DayLow[i] < LowestTemp) {

			LowestTemp = DayLow[i];
			LowestTempDay = i;

		}

	}
	printf("\n");//For formatting purposes

				 //Print data out
	printf("Day  Hi  Low");

	for (i = 1; i <= counter; i++) {

		printf("\n%d    %d    %d", i, DayHigh[i], DayLow[i]);

	}


	printf("\n");
	printf("\n");  //For formatting purposes

				   //print higher and lowest temp
	printf("The highest temperature was %d, on day %d", HighestTemp, HighestTempDay);
	printf("\nThe lowest temperature was %d, on day %d\n", LowestTemp, LowestTempDay);

	printf("\n");  //For formatting purposes

	printf("Enter a number between 1 and 4 to see the average temperature for the entered number of days, enter a negative number to exit: ");
	scanf("%d", &counter);//In this case counter is just used to grab input


	if (counter < 1) { //close program if entered number is 0
		printf("\n");  //For formatting purposes
		printf("Goodbye!\n");
		return 0;
	}

	while (counter > 4) {

		// If invalid value, ask for valid value
		printf("\n");  //For formatting purposes
		printf("Invalid entry, please enter a number between 1 and 4, inclusive: ");
		scanf("%d", &counter);

		if (counter < 1) { //close program if entered number is 0
			return 0;
		}
	}


	if (counter <= 4) { // if user inputs valid value output average temp for up to day inputted


		for (i = 1; i <= counter; i++) {

			Avg = Avg + (float)DayHigh[i] + (float)DayLow[i];

		}


		Avg = Avg / (2 * counter);



		printf("\n");  //For formatting purposes
		printf("The average temperature up to day %d is: %.2f", counter, Avg);
		Avg = 0;




	}

	printf("\n");  //For formatting purposes


	do {






		printf("\n");  //For formatting purposes
		printf("Enter a number between 1 and 4 to see the average temperature for the entered number of days, enter a negative number to exit: ");
		scanf("%d", &counter);//In this case counter is just used to grab input

		if (counter < 1) { //close program if entered number is 0
			printf("\n");  //For formatting purposes
			printf("Goodbye!\n");
			return 0;
		}


		while (counter > 4) {

			// If invalid value, ask for valid value
			printf("\n");  //For formatting purposes
			printf("\nInvalid entry, please enter a number between 1 and 4, inclusive: ");
			scanf("%d", &counter);



			printf("\n");  //For formatting purposes

		}

		if (counter <= 4) { // if user inputs valid value output average temp for day


			for (i = 1; i <= counter; i++) {

				Avg = Avg + (float)DayHigh[i] + (float)DayLow[i];

			}


			Avg = Avg / (2 * counter);

			printf("\n");  //For formatting purposes
			printf("The average temperature up to day %d is: %.2f", counter, Avg);
			Avg = 0;
		}
		printf("\n");  //For formatting purposes



	} while (counter <= 4 && counter >= 1);















	return 0;
}
