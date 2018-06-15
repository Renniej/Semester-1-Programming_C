/* -------------------------------------------
Name:
Student number:
Email:
Section:
Date:
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "contacts.h"


// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:



// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:



// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:



	//-------------------------------------------------------------------
	// I was having trouble having scanf accept spaces so i tried the fgets function.
	// Then when i tried the fgets function I found that mixing fgets and scanf are a big no no
	// This was due to the input buffer being filled by the previous scanf function 
	// The below loop makes sure the input buffer is cleared before the fgets function is called.
	// ):< This conclusion took me 2 hours and I now utterly hate this assignment lol.




// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:


void getName(struct Name * name) {

	char input = ' ';

	printf("Please enter the contact's first name: ");
	scanf("%s", name->firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &input);

	if (input == 'y' || input == 'Y') { // If user enters yes then let them enter middle initial(s)
		printf("Please enter the contact's middle initial(s): ");
		scanf("%s", name->middleInitial);
	}


	printf("Please enter the contact's last name: ");
	scanf("%s", name->lastName);

}

void getAddress(struct Address * address) {

	char input = ' ';
	printf("Please enter the contact's street number: ");
	scanf("%d", &address->streetNumber);


	printf("Please enter the contact's street name: ");
	scanf("%s", address->street);


	printf("Do you want to enter an apartment number? (y or n): ");
	scanf(" %c", &input);

	if (input == 'y' || input == 'Y') { // If user enters yes then let them enter  apartment number(s)
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &address->apartmentNumber);
	}

	while (getchar() != '\n') {//clear input buffer
		input = ' ';
	}

	printf("Please enter the contact's postal code: ");
	//scanf("%s", &ContactAddress.postalCode);
	fgets(address->postalCode, 8, stdin);

	//---------------------------------------------------------------



	printf("Please enter the contact's city: ");
	scanf("%s", address->city);

}

void getNumbers(struct Numbers * numbers) {
	char input = ' ';

	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &input);


	if (input == 'y' || input == 'Y') { // If user enters yes then let them enter  apartment number(s)
		printf("Please enter the contact's cell phone number: ");
		scanf("%s", numbers->cell);
	}


	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &input);


	if (input == 'y' || input == 'Y') { // If user enters yes then let them enter  apartment number(s)
		printf("Please enter the contact's home phone number: ");
		scanf("%s", numbers->home);
	}



	printf("Do you want to enter a business phone number? (y or n): ");
	scanf(" %c", &input);


	if (input == 'y' || input == 'Y') { // If user enters yes then let them enter  apartment number(s)
		printf("Please enter the contact's business phone number: ");
		scanf("%s", numbers->business);
	}

}

