/* -------------------------------------------
Name:
Student number:
Email:
Section:
Date:
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+




// +---------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2   |
// |        function definitions below...              |
// |                                                   |
// | *** See hint regarding the getNumbers function    |
// +---------------------------------------------------+


// getName:

void getName(struct Name * name) {

	int input;

	printf("Please enter the contact's first name: ");
	fgets(name->firstName, 24, stdin);
	FindN(name->firstName); //Remove trailing N if it exist

	//clearKeyboard();



	printf("Do you want to enter a middle initial(s)? (y or n): ");
	//clearKeyboard();
	input = yes();

	if (input == 1) { // If user enters yes then let them enter middle initial(s)
		printf("Please enter the contact's middle initial(s): ");
		fgets(name->middleInitial, 24, stdin);
		FindN(name->middleInitial); //Remove trailing N if it exist
	}


	printf("Please enter the contact's last name: ");
	fgets(name->lastName, 24, stdin);
	FindN(name->lastName); //Remove trailing N if it exist

}


// getAddress:
void getAddress(struct Address * address) {

	int input;
	printf("Please enter the contact's street number: ");
	//clearKeyboard();
	address->streetNumber = getInt();

	printf("Please enter the contact's street name: ");
	fgets(address->street, 41, stdin);
	FindN(address->street);



	printf("Do you want to enter an apartment number? (y or n): ");
	//clearKeyboard();
	input = yes();

	if (input == 1) { // If user enters yes then let them enter  apartment number(s)
		printf("Please enter the contact's apartment number: ");
		//clearKeyboard();
		address->apartmentNumber = getInt();
	}
	//else
	//{
		//address->apartmentNumber = -1; //-1 = Apartment number does not exist
	//}



	printf("Please enter the contact's postal code: ");
	//scanf("%s", &ContactAddress.postalCode);
	fgets(address->postalCode, 8, stdin);
	FindN(address->postalCode);

	clearKeyboard();

	//---------------------------------------------------------------



	printf("Please enter the contact's city: ");
	fgets(address->city, 24, stdin);
	FindN(address->city);

}


// getNumbers:
// HINT:  Update this function to use the new helper 
//        function "getTenDigitPhone" where applicable

void getNumbers(struct Numbers * numbers) {
	int input;

	printf("Please enter the contact's cell phone number: ");
	//clearKeyboard();
	getTenDigitPhone(numbers->cell);

	printf("Do you want to enter a home phone number? (y or n): ");
	//clearKeyboard();
	input = yes();


	if (input == 1) { // If user enters yes then let them enter  home number(s)
		printf("Please enter the contact's home phone number: ");
		//clearKeyboard();
		getTenDigitPhone(numbers->home);
	}
	else {

	numbers->home[0] = 0;
	}



	printf("Do you want to enter a business phone number? (y or n): ");
	input = yes();


	if (input == 1) { // If user enters yes then let them enter  business number(s)
		printf("Please enter the contact's business phone number: ");
		//clearKeyboard();
		getTenDigitPhone(numbers->business);
	}
	else {

	numbers->business[0] = 0;

	}

}


// getContact

void getContact(struct Contact * Contacts) {

	getName(&Contacts->name);
	getAddress(&Contacts->address);
	getNumbers(&Contacts->numbers);


}