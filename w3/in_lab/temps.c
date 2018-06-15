/*
     Name:      Tai-Juan Rennie		
     Student#:  101359172
     Section:   BTP100
*/

#define _CRT_SECURE_NO_WARNINGS
#define NUMS 3
#include <stdio.h>


// Put your code below:

int main(void) {
	//Note:  +1 was added to arrays using NUM to avoid crashing.  (I forgot the last array value is reserved so the program knows where it ends)

	int dayHigh[NUMS+1]; //Array for High temp. of days
	int dayLow[NUMS+1];// Array for Low temp. of days
	double totalHigh = 0; // Total calculated amount for High (Used for calculating Avg)
	double totalLow = 0; // Total calculated amount for low  (Used for calculating Avg)
	double Avg;

	printf("---=== IPC Temperature Analyzer ===---\n");

	int i;
	for (i = 1; i <= NUMS; i++) {

		do {

			printf("Enter the high value for day %d: ", i);
			scanf("%d", &dayHigh[i]);

			printf("\n"); // print blank line

			printf("Enter the low value for day %d: ", i);
			scanf("%d", &dayLow[i]);

			printf("\n"); // print blank line

			if (dayHigh[i] < dayLow[i] || dayHigh[i] > 40 || dayLow[i] < -40) { // if invalid input then print error message

				printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
				printf("\n"); // print blank line
			}
			else // If valid inputs then add values to their respective total amount counters
			{
				totalHigh = totalHigh + (double)dayHigh[i]; 
				totalLow = totalLow + (double)dayLow[i];
			}

		} while (dayHigh[i] < dayLow[i] || dayHigh[i] > 40 || dayLow[i] < -40);  // If invalid inputs then restart intpus for that particular day
	}

	Avg = (totalHigh + totalLow) /(NUMS * 2); // calculate avg

	printf("The average (mean) temperature was: %.2lf", Avg); // print avg.

	printf("\n"); // print blank line

	return 0;


}
