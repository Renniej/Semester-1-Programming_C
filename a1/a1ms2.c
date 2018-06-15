/* -------------------------------------------
Name: Tai-Juan Rennie
Student number: 101359172
Email: trennie1
Section:
Date: 3/14/2018 7:12pm
----------------------------------------------
Assignment: 1
Milestone:  2
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


int main (void){

    // Declare variables here:
	char input= ' '; // Used for decision making/etc.  I was having a buffer overflow error so I made the char into an array as a workaround
	struct Name ContactName = { {""}, {""}, {""} }; //Fields for first, middle and last name
	struct Address ContactAddress = { 0, {0}, 0, {""}, {""} };// Fields for address
	struct Numbers ContactPhone = { {0},{0}, {0} }; //fields for home, cell and work numbers

    // Display the title

	printf("Contact Management System\n-------------------------\n");


    // Contact Name Input:

	printf("Please enter the contact's first name: "); 
	scanf("%s", ContactName.firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &input);

	if (input == 'y' || input == 'Y') { // If user enters yes then let them enter middle initial(s)
		printf("Please enter the contact's middle initial(s): ");
		scanf("%s", ContactName.middleInitial);
	}
	

	printf("Please enter the contact's last name: ");
	scanf("%s", ContactName.lastName);

    // Contact Address Input:

	printf("Please enter the contact's street number: ");
	scanf("%d", &ContactAddress.streetNumber);


	printf("Please enter the contact's street name: ");
	scanf("%s", ContactAddress.street);


	printf("Do you want to enter an apartment number? (y or n): ");
	scanf(" %c", &input);

	if (input == 'y' || input == 'Y') { // If user enters yes then let them enter  apartment number(s)
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &ContactAddress.apartmentNumber);
	}

	//-------------------------------------------------------------------
	// I was having trouble having scanf accept spaces so i tried the fgets function.
	// Then when i tried the fgets function I found that mixing fgets and scanf are a big no no
	// This was due to the input buffer being filled by the previous scanf function 
	// The below loop makes sure the input buffer is cleared before the fgets function is called.
	// ):< This conclusion took me 2 hours and I now utterly hate this assignment lol.


	while (getchar() != '\n') {
		input = ' ';
	}


	printf("Please enter the contact's postal code: ");
	//scanf("%s", &ContactAddress.postalCode);
	fgets(ContactAddress.postalCode, 8, stdin);

	//---------------------------------------------------------------

	

	printf("Please enter the contact's city: ");
	scanf("%s", ContactAddress.city);


    // Contact Numbers Input:

	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &input);


	if (input == 'y'|| input == 'Y') { // If user enters yes then let them enter  apartment number(s)
		printf("Please enter the contact's cell phone number: ");
		scanf("%s", ContactPhone.cell);
	}


	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &input);


	if (input == 'y' || input == 'Y') { // If user enters yes then let them enter  apartment number(s)
		printf("Please enter the contact's home phone number: ");
		scanf("%s", ContactPhone.home);
	}



	printf("Do you want to enter a business phone number? (y or n): ");
	scanf(" %c", &input);


	if (input == 'y'|| input == 'Y') { // If user enters yes then let them enter  apartment number(s)
		printf("Please enter the contact's business phone number: ");
		scanf("%s", ContactPhone.business);
	}


    // Display Contact Summary Details

	printf("\n");

	printf("Contact Details\n---------------\n");

	printf("Name Details\n");
	printf("First name: %s\n", ContactName.firstName);
	
	if (strcmp(ContactName.middleInitial, "") != 0) {
		printf("Middle initial(s): %s\n", ContactName.middleInitial);
	}
	printf("Last name: %s\n", ContactName.lastName);

	printf("\n");

	printf("Address Details\n");
	printf("Street number: %d\n",ContactAddress.streetNumber);
	printf("Street name: %s\n", ContactAddress.street);

	//Check if apartment exist before displaying it
	if (ContactAddress.apartmentNumber != 0) {
		printf("Apartment: %d\n", ContactAddress.apartmentNumber);
	}

	printf("Postal code: %s\n", ContactAddress.postalCode);
	printf("City: %s\n", ContactAddress.city);

	printf("\n");

	printf("Phone Numbers:\n");

	//Check if number actually exist before displaying it
	if (strcmp(ContactPhone.cell, "" ) != 0) {
		printf("Cell phone number: %s\n", ContactPhone.cell);
	}

	if (strcmp(ContactPhone.home, "") != 0) {
		printf("Home phone number: %s\n", ContactPhone.home);
	}

	if (strcmp(ContactPhone.business, "") != 0) {
		printf("Business phone number: %s\n", ContactPhone.business);
	}

	printf("\n");

	

    // Display Completion Message
	printf("Structure test for Name, Address, and Numbers Done!\n");
	


    return 0;
}

/*  SAMPLE OUTPUT:
    
Contact Management System
-------------------------
Please enter the contact's first name: Tom
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): Wong
Please enter the contact's last name: Song
Please enter the contact's street number: 20
Please enter the contact's street name: Keele
Do you want to enter an appartment number? (y or n): y
Please enter the contact's appartment number: 40
Please enter the contact's postal code: A8A 4J4
Please enter the contact's city: Toronto
Do you want to enter a cell phone number? (y or n): Y
Please enter the contact's cell phone number: 905-111-6666
Do you want to enter a home phone number? (y or n): Y
Please enter the contact's home phone number: 705-222-7777
Do you want to enter a business phone number? (y or n): Y
Please enter the contact's business phone number: 416-333-8888

Contact Details
---------------
Name Details
First name: Tom
Middle initial(s): Wong
Last name: Song

Address Details
Street number: 20
Street name: Keele
Apartment: 40
Postal code: A8A 4J4
City: Toronto

Phone Numbers:
Cell phone number: 905-111-6666
Home phone number: 705-222-7777
Business phone number: 416-333-8888

Structure test for Name, Address, and Numbers Done!
*/